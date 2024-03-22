#include "SaveData.hpp"



int get_personal_best()
{
    ifstream file(base_path+"data/save/config.dat",ios_base::binary);

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
                1,
                1<<sdlgame::random::randint(
                    data_range.first,
                    data_range.second
                )
            );
        }while(mp.at(offset[i])==1);
    

    
}