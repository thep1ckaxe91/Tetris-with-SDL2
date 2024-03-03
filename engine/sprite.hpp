#ifndef SDLGAME_SPRITE_
#define SDLGAME_SPRITE_

namespace sdlgame
{
    /**
     * Should be test heavyly around pointer
     * just use stack-alloc like normal
     * treat the pointer as a address holder only,
     * not an pointer to a heap allocated object
     */
    namespace sprite
    {
        /**
         *
         * The base class for visible game objects.
         * Derived classes will want to override the Sprite.update() and assign a Sprite.image and Sprite.rect attributes.
         * The initializer can accept any number of Group instances to be added to
         *
         */
        class Sprite;
        class Group
        {
        public:
            std::set<Sprite *> sprite_list;
            Group(std::vector<Sprite *> sprites = std::vector<Sprite *>())
            {
                for (auto sprite : sprites)
                    this->add(sprite);
            }
            Group &operator=(Group oth)
            {
                sprite_list = oth.sprite_list;
                return *this;
            }
            std::set<Sprite *> &sprites();
            void add(Sprite *sprite);
            void add(std::vector<Sprite *> &sprites);
            void remove(std::vector<Sprite *> &sprites);
            void remove(Sprite *sprite);
            bool has(std::vector<Sprite *> &sprites);
            bool has(Sprite *sprite);
            void update();
            void draw(sdlgame::surface::Surface &surface);
        };

        class Sprite
        {
        public:
            sdlgame::rect::Rect rect;
            sdlgame::surface::Surface image;
            std::set<Group *> group_list;
            Sprite(std::vector<Group *> groups = std::vector<Group *>())
            {
                for (Group *group : groups)
                    this->add(group);
            }
            /**
             * return a set of group that conrtain this sprite
             */
            std::set<Group *> &groups()
            {
                return group_list;
            }
            virtual void update() = 0;
            void add(std::vector<Group *> groups)
            {
                for (auto &group : groups)
                {
                    group->sprite_list.insert(this);
                    group_list.insert(group);
                }
            }
            void add(Group *group)
            {
                group->sprite_list.insert(this);
                group_list.insert(group);
            }
            void remove(std::vector<Group *> groups)
            {
                for (auto &group : groups)
                {
                    auto it = group_list.find(group);
                    if (it != group_list.end())
                    {
                        group->sprite_list.erase(this);
                        group_list.erase(group);
                    }
                }
            }
            void remove(Group *group)
            {
                auto it = group_list.find(group);
                if (it != group_list.end())
                {
                    group->sprite_list.erase(this);
                    group_list.erase(group);
                }
            }
            /**
             * remove this sprite from all group, still usable after call
             */
            void kill()
            {
                for (auto &group : group_list)
                    group->sprite_list.erase(this);
                group_list.clear();
            }
            bool alive()
            {
                return group_list.size() > 0;
            }
        };

        std::set<Sprite *> &Group::sprites()
        {
            return sprite_list;
        }
        void Group::add(Sprite *sprite)
        {
            sprite_list.insert(sprite);
            sprite->group_list.insert(this);
        }
        void Group::add(std::vector<Sprite *> &sprites)
        {
            for (auto &sprite : sprites)
            {
                sprite_list.insert(sprite);
                sprite->group_list.insert(this);
            }
        }
        void Group::remove(std::vector<Sprite *> &sprites)
        {
            for (auto &sprite : sprites)
            {
                auto it = sprite_list.find(sprite);
                if (it != sprite_list.end())
                {
                    sprite->remove(this);
                    sprite_list.erase(it);
                }
            }
        }
        void Group::remove(Sprite *sprite)
        {
            auto it = sprite_list.find(sprite);
            if (it != sprite_list.end())
            {
                sprite->remove(this);
                sprite_list.erase(it);
            }
        }
        bool Group::has(std::vector<Sprite *> &sprites)
        {
            for (auto &sprite : sprites)
            {
                if (sprite_list.find(sprite) == sprite_list.end())
                    return false;
            }
            return true;
        }
        bool Group::has(Sprite *sprite)
        {
            if (sprite_list.find(sprite) == sprite_list.end())
                return false;
            return true;
        }
        void Group::update()
        {
            for (auto &sprite : sprite_list)
            {
                sprite->update();
            }
        }
        void Group::draw(sdlgame::surface::Surface &surface)
        {
            for (auto &sprite : sprite_list)
            {
                surface.blit(sprite->image, sprite->rect.getTopLeft());
            }
        }
        /**
         * Also a sprite group, the only difference is it only hold 1 sprite,
         * if you call add, it will replace that sprite
         */
        class GroupSingle
        {
        public:
            Sprite *sprite;
            GroupSingle(Sprite *sprite = NULL)
            {
                this->sprite = sprite;
            }
            void add(Sprite *sprite)
            {
                this->sprite = sprite;
            }
            void remove()
            {
                sprite = NULL;
            }
            void update()
            {
                sprite->update();
            }
            void draw(sdlgame::surface::Surface &surface)
            {
                surface.blit(sprite->image, sprite->rect.getTopLeft());
            }
        };

        /**
         * @return a list containing all Sprites in a Group that intersect with another Sprite.
         * Intersection is determined by comparing the Sprite.rect attribute of each Sprite.
         * The dokill argument is a bool. If set to True, all Sprites that collide will be removed from the Group.
         */
        std::vector<Sprite *> spritecollide(Sprite *sprite, Group *group, bool dokill = false)
        {
            std::vector<Sprite *> res;
            for (auto &img : group->sprite_list)
            {
                if (img->rect.colliderect(sprite->rect))
                {
                    res.push_back(img);
                }
            }
            if (dokill)
                group->remove(res);
            return res;
        }
        /**
         * @return if 2 sprite is collide or not, but using 2 sprite, both must have rect attr defined
         */
        bool collide_rect(Sprite *left, Sprite *right)
        {
            return left->rect.colliderect(right->rect);
        }
        /**
         * Tests for collision between two sprites,
         * by testing to see if two circles centered on the sprites overlap.
         * If the radius value is passed, it will check if 2 circle center at the both rect center is collide with that center and that radius or not
         * otherwise a circle is created that is big enough to completely enclose the sprites rect as given by the "rect" attribute.
         */
        bool collide_circle(Sprite *left, Sprite *right, double left_radius = 0, double right_radius = 0)
        {
            left_radius = (left_radius == 0 ? (left->rect.getTopLeft() - left->rect.getBottomRight()).magnitude() / 2 : left_radius);
            right_radius = (right_radius == 0 ? (right->rect.getTopLeft() - right->rect.getBottomRight()).magnitude() / 2 : right_radius);
            return (left->rect.getCenter() - right->rect.getCenter()).magnitude() <= left_radius + right_radius;
        }

    }
}

#endif