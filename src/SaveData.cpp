/**
 * For security reason, there should be a way to prevent
 * cheater to cheat their pb
 *
 * the config.cfg file will be written in binary mode
 * first 8*4 bytes represent 8 integer is the bytes offset of the data
 * we will compare after merge the first 4 and the last 4,
 * if they are different, it good to say they're trying to cheat
 *
 * But this is good, since author score will be (1<<31)-1
 * Player must figure a way to find this, but randomness will secure
 * my wallet from emptying itself :)
 */

#include "SaveData.hpp"
#include <bits/stdc++.h>
int bytes_to_int(const char *c)
{
    union
    {
        int val;
        char cc[4];
    } data;
    memcpy(data.cc, c, 4);
    return data.val;
}
char *int_to_bytes(int x)
{
    union
    {
        int val;
        char c[4];
    } data;
    char *res = new char[4];
    data.val = x;
    memcpy(res, data.c, 4);
    return res;
}

int get_personal_best()
{
    if (!filesystem::exists(base_path + "data/save/config.dat"))
    {
        set_personal_best(0);
        return 0;
    }
    ifstream file(base_path + "data/save/config.dat", ios_base::binary);

    int offset[8];
    file.read((char *)offset, sizeof(int) * 8);
    if (file.fail())
    {
        printf("Failed to get personal best offset");
        exit(0);
    }
    char dat[8];
    for (int i = 0; i < 8; i++)
    {
        file.seekg(std::streamoff(sizeof(offset) + offset[i]), ios_base::seekdir(ios_base::beg));
        file.read(dat + i, 1);
    }
    int pb1 = bytes_to_int(dat);
    int pb2 = bytes_to_int(dat + 4);
    if (pb1 != pb2)
    {
        SDL_Quit();
        printf("Oh, you nearly found the answer, it so close, it just that you could never reach it\n");
        printf("Press any key to close...\n");
        cin.get();
        exit(0);
    }

    return pb1;
}
// score must biger than get_personal_best()
void set_personal_best(int score)
{
    ofstream file(base_path + "data/save/config.dat", ios_base::binary);
    // offset 0->3 is the first 4 byte of the score value,
    int offset[8];
    map<int, bool> mp;
    for (int i = 0; i < 8; i++)
        do
        {
            offset[i] = sdlgame::random::randint(
                0,
                1 << sdlgame::random::randint(
                    sdlgame::random::randint(15, 17),
                    sdlgame::random::randint(17, 20)));
        } while (mp.find(offset[i]) != mp.end());
    // now the config.cfg should have 8*4 bytes for the offset info, and all of them
    // shall be unique
    file.write((char *)offset, sizeof(offset));
    if (file.fail())
    {
        printf("Failed to write offset\n");
        exit(0);
    }

    char *dat = int_to_bytes(score);
    int data_size = *max_element(offset, offset + 8) + sdlgame::random::randint(20, 30);

    char *data = new char[data_size];
    for (int i = 0; i < data_size; i++)
        data[i] = sdlgame::random::randint(0, 255);

    for (int i = 0; i < 8; i++)
    {
        data[offset[i]] = dat[i % 4];
    }
    file.write(data, data_size);
    if (file.fail())
    {
        printf("Failed to write data\n");
        exit(0);
    }
    file.close();

    delete[] dat;
    delete[] data;
}

float get_sfx_volume()
{
    if (!filesystem::exists(base_path + "data/save/sfx_volume.dat"))
    {
        set_sfx_volume(1);
        return 1;
    }
    ifstream file(base_path + "data/save/sfx_volume.dat");

    float res;
    try
    {
        file >> res;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return res;
}
float get_music_volume()
{
    if (!filesystem::exists(base_path + "data/save/music_volume.dat"))
    {
        set_music_volume(1);
        return 1;
    }
    ifstream file(base_path + "data/save/music_volume.dat");

    float res;
    try
    {
        file >> res;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return res;
}
void set_sfx_volume(float value)
{
    ofstream file(base_path + "data/save/sfx_volume.dat");
    file << (value < 0 ? 0 : (value > 1 ? 1 : value));
    file.close();
}
void set_music_volume(float value)
{
    ofstream file(base_path + "data/save/music_volume.dat");
    file << (value < 0 ? 0 : (value > 1 ? 1 : value));
    file.close();
}

bool have_grid_data()
{
    return filesystem::exists(base_path + "data/save/grid.dat");
}
// delete the save file, if not exist or error is thrown, return false
bool delete_grid_data()
{
    try
    {
        return std::filesystem::remove(base_path + "data/save/grid.dat");
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error deleting file: " << e.what() << std::endl;
        return false;
    }
}
/**
 * @brief save the grid data
 * 
 * overall, this is what we'll save:
 * 
 * 16 bytes of controller topleft
 * 1 byte of controller color
 * 1 byte of tetrimino type (character)
 * 1 byte of tetrimino rotation (0-3)
 * 
 * -> controller can be load with shapeinfolist 
 * 
 * GRID_WIDTH * GRID_HEIGHT bytes for grid data
 * each bytes save the color mask,
 * GRID_WIDTH * GRID_HEIGHT bytes for color offset byte
 * 
 * 
 * 
 *
 * @param grid the grid data to save
 * @return true save grid success
 * @return false save grid failed
 */
bool save_grid_data(Grid &grid)
{
    if(have_grid_data()) delete_grid_data();
    ofstream file(base_path + "data/save/grid.dat", ios_base::binary);
    if (file.is_open())
        file.write((char *)&grid, sizeof(grid));

    char data[]
    if (file.bad())
    {
        cerr << "Cant save progess" << endl;
    }
    file.close();
}
/**
 * @brief load the grid data from file
 *
 * @return Grid
 */
Grid load_grid_data()
{
}