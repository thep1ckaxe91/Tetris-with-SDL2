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

int bytes_to_int(const char *c)
{
    union                                                  
    {
        int val;
        char cc[4];
    }data;
    memcpy(data.cc,c,4);
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
    data.val=x; memcpy(res,data.c,4);
    return res;
}

int get_personal_best()
{
    if(!filesystem::exists(base_path+"data/save/config.dat"))
    {
        set_personal_best(0);
        return 0;
    }
    ifstream file(base_path + "data/save/config.dat", ios_base::binary);

    int offset[8];
    file.read((char *)offset, sizeof(int)*8);
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
    int pb2 = bytes_to_int(dat+4);
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