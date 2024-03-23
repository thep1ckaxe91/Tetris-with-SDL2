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

int bytes_to_int(char c1,char c2,char c3,char c4)
{
    return ((((((c1<<8)|c2)<<8)|c3)<<8)|c4);
}
char *int_to_bytes(int x)
{
    char *res = new char[4];
    for(int i=0;i<4;i++) res[i] = ((x<<(i*8))>>(8*3));
    return res;
}


int get_personal_best()
{
    if(!filesystem::exists("data/save/config.dat")) return 0;
    ifstream file(base_path+"data/save/config.dat",ios_base::binary);
    int offset[8];
    file.read((char*)offset,sizeof(offset));
    char dat1[4],dat2[4];
    for(int i=0;i<8;i++)
    {
        file.seekg(std::streamoff(sizeof(offset)+offset[i]),ios_base::seekdir(ios_base::beg));
        if(i<4) file.read(dat1+i,1);
        else file.read(dat2+i%4,1);
    }
    int pb1 = bytes_to_int(dat1[0],dat1[1],dat1[2],dat1[3]);
    int pb2 = bytes_to_int(dat2[0],dat2[1],dat2[2],dat2[3]);

    if(pb1!=pb2)
    {
        SDL_Quit();
        printf("Oh, you nearly found the answer, it so close, it just that you could never reach it\n");
        printf("Press any key to close...\n");
        cin.get();
        exit(0);
    }

    return pb1;
}
//score must biger than get_personal_best()
void set_personal_best(int score)
{
    ofstream file(base_path+"data/save/config.dat",ios_base::binary);
    pair<int,int> data_range = {
        sdlgame::random::randint(15,17),
        sdlgame::random::randint(17,20)
    };
    //offset 0->3 is the first 4 byte of the score value, 
    int offset[8];
    map<int,bool> mp;
    for(int i=0;i<8;i++)
        do{
            offset[i] = sdlgame::random::randint(
                0,
                1<<sdlgame::random::randint(
                    data_range.first,
                    data_range.second
                )
            );
        }while(mp.at(offset[i]));
    //now the config.cfg should have 8*4 bytes for the offset info, and all of them
    //shall be unique
    file.write((char*)offset,sizeof(offset));
    
    char *dat = int_to_bytes(score);

    int data_size = *max_element(offset,offset+8) + sdlgame::random::randint(20,30);
    while(data_size%4!=0) data_size++;
    char *data = new char[data_size+1];
    for(int i=0;i<data_size;i++) data[i] = sdlgame::random::randint(0,255);

    for(int i=0;i<8;i++)
        data[offset[i]] = dat[i%4];

    file.write(data,sizeof(data));

    delete[] dat;
    delete[] data;
}