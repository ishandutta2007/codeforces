#include <bits/stdc++.h>
using namespace std;
long long ans=0;
bool mezo[509][509];
bool volt[509][509][31][8];
//7 0 1
//6 x 2
//5 4 3
int direction[8][2]={{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
int n;
int t[39];
void rec(int x, int y, int szint, int dir)
{
    if(szint>n) return;
    //cout<<"rec: "<<x<<" "<<y<<" "<<szint<<" "<<dir<<endl;
    if(volt[x][y][szint][dir]) return;
    volt[x][y][szint][dir]=true;
    for(int i=1; i<t[szint]; i++)
    {
        mezo[x][y]=true;
        x+=direction[dir][0];
        y+=direction[dir][1];
    }
    mezo[x][y]=true;
    int x1=x+direction[(dir+1)%8][0];
    int y1=y+direction[(dir+1)%8][1];
    int x2=x+direction[(dir+7)%8][0];
    int y2=y+direction[(dir+7)%8][1];
    rec(x1, y1, szint+1, (dir+1)%8);
    rec(x2, y2, szint+1, (dir+7)%8);
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    rec(200, 200, 1, 0);
    for(int i=0; i<509; i++)
    {
        for(int j=0; j<509; j++)
        {
            if(mezo[i][j]) ans++;
            /*if(mezo[i][j])
            {
                cout<<i<<" "<<j<<endl;
            }*/
        }
    }
    cout<<ans<<endl;
    return 0;
}