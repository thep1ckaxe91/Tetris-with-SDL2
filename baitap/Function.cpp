#include <bits/stdc++.h>
using namespace std;
//do min
int m,n,k;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int a[12][12];
bool vis[12][12];
void display()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // if(a[i][j]==-1) cout << "*";
            // else
            if(!vis[i][j]) cout << "#";
            else if(a[i][j]==0 and vis[i][j]) cout << "_";
            else if(a[i][j]!=0 and vis[i][j]) cout << a[i][j];
        }
        cout<<endl;
    }
}
bool openup(int i,int j)
{
    if(a[i][j]==-1)
    {
        cout << "YOU'RE DEAD!" << endl;
            for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==-1) cout << "*";
            else
            if(!vis[i][j]) cout << "#";
            else if(a[i][j]==0 and vis[i][j]) cout << "_";
            else if(a[i][j]!=0 and vis[i][j]) cout << a[i][j];
        }
        cout<<endl;
    }
        return 1;
    }

    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j]=1;
    while(q.size())
    {
        auto u = q.front();
        q.pop();
        if(a[u.first][u.second]==0){
            for(int id=0;id<4;id++)
            {
                int x=u.first+dx[id];
                int y=u.second+dy[id];
                if(!vis[x][y] and x>0 and y>0 and x<=m and y<=n)
                {
                    q.push({x,y});
                    vis[x][y]=1;
                }
            }
        }
    }

    return 0;
}
int main(int argc, const char * argv[])
{
    srand(time(NULL));
    // cin>>m>>n>>k;
    // m = rand() %10 + 1;
    // n = rand() %10 + 1;
    m = stoi(string(argv[1])); n=stoi(string(argv[2]));
    k = stoi(string(argv[3]));
    for(int i=0;i<k;i++)
    {
        int x=rand()%m+1;
        int y=rand()%n+1;
        a[x][y]=-1;
        for(int id=0;id<4;id++)
        {
            int tx=x+dx[id];
            int ty=y+dy[id];
            a[tx][ty]++;
        }
    }
    while(true)
    {
        int x,y;
        display();
        cout << "\ninput row and collumn to discover:\n";
        cout << "row: ";
        cin>>x;
        cout<<"col: ";
        cin>>y;

        if(openup(x,y))
        {
            break;
        }
    }
}