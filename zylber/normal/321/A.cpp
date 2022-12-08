#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std;

long long pos[128][2];
long long dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int dir(char c)
{
    if(c=='R') return 0;
    if(c=='L') return 1;
    if(c=='U') return 2;
    return 3;
}

int main()
{
    long long x, y;
    cin >> x >> y;
    memset(pos,0,sizeof(pos));
    string movs;
    cin >> movs;
    int s=movs.size();
    
    for(int i=0; i<s; i++)
    {
        int d=dir(movs[i]);
        
        pos[i+1][0]=pos[i][0]+dx[d];
        pos[i+1][1]=pos[i][1]+dy[d];
    }
    
    int can=0; 
    
    for(int i=0; i<s; i++)
    {
        long long gx=x-pos[i][0];
        long long gy=y-pos[i][1];
        
        int mul=-1, canx=0, cany=0;
        if(pos[s][0]==0)
        {
            if(gx==0)
            {
                canx=1;
            }
        }
        else
        {
            if(gx*pos[s][0]>=0 && gx%pos[s][0]==0)
            {
                canx=1;
                mul=gx/pos[s][0];
            }
        }
        
        if(canx)
        {
            if(pos[s][1]==0)
            {
                if(gy==0)
                {
                    cany=1;
                }
            }
            else
            {
                if(gy*pos[s][1]>=0 && gy%pos[s][1]==0)
                {
                    cany=1;
                    if(mul>=0 && gy/pos[s][1]!=mul)
                    {
                        cany=0;
                    }
                }
            }
        }
        
        if(canx && cany) can=1;
    }
    
    if(can) cout << "Yes" << endl; else cout << "No" << endl;
}