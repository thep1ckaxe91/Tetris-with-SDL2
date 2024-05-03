#include <bits/stdc++.h>
using namespace std;

// 1

struct Point
{
    Point(int _x = 0, int _y = 0) : x(_x), y(_y)
    {
    }
    int x, y;
};
void print(Point &p)
{
    // p.x = 2;
    cout << p.x << " " << p.y << endl;
}
Point mid_point(const Point &p1, const Point &p2)
{
    return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

struct Rect
{
    int x, y, w, h;

    bool contains(const Point &p) const
    {
        return p.x >= x and p.x <= x + w and p.y >= y and p.y <= y + h;
    }
};

struct Ship
{
    Rect hitbox;
    string id;
    int dx, dy;
    Ship(){id = "lol"; hitbox = Rect(); dx=1; dy=1;}
    void move()
    {
        hitbox.x += dx;
        hitbox.y += dy;
    }
};

void display(const Ship &ship)
{
    cout << ship.id << endl;
    cout << ship.hitbox.x << " " << ship.hitbox.y << endl;
}

int main()
{
    // Point point;
    // point.x = 10;
    // point.y = 12;
    // print(point);
    // cout<<point.x;

    Ship ship1;
    Ship ship2;
    int loop=0;

    while (loop < 10)
    {
        ship1.move();
        ship2.move();
        display(ship1);
        display(ship2);
        loop++;
    }
}