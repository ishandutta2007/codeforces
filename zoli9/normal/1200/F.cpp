#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int e9=1008000000;
int MOD=2520;
int n;
int plusz[1009];
int m[1009];
int ne[1009][10];
bool was[1009][2520];
int ans[1009][2520];

bool circle=false;

set<int> ss;
int sx, sy, ex, ey;
int test;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>plusz[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>m[i];
        plusz[i]=(plusz[i]+(e9))%MOD;
        for(int j=0; j<m[i]; j++)
        {
            cin>>ne[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<MOD; j++)
        {
            if(!was[i][j])
            {
                circle=false;
                int x=i;
                int y=j;
                int ux, uy;
                int answerr=0;
                int sx, sy, ex, ey;
                while(1)
                {
                    //cout<<x<<" and "<<y<<endl;
                    was[x][y]=true;
                    uy=(y+plusz[x])%MOD;
                    ux=ne[x][(y+plusz[x])%m[x]];
                    if(was[ux][uy])
                    {
                        if(ans[ux][uy]>0)
                        {
                            ex=ux;
                            ey=uy;
                            answerr=ans[ux][uy];
                        }
                        else
                        {
                            sx=ux;
                            sy=uy;
                            ex=x;
                            ey=y;
                            circle=true;
                        }
                        break;
                    }
                    x=ux;
                    y=uy;
                }
                //cout<<sx<<" "<<sy<<" ee:: "<<ex<<" "<<ey<<endl;
                int idx=0;
                if(circle)
                {
                    ss.clear();
                    while(!(sx==ex && sy==ey))
                    {
                        ss.insert(sx);
                        sy=(sy+plusz[sx])%MOD;
                        sx=ne[sx][(sy)%m[sx]];
                        /*cout<<"belso "<<sx<<" : "<<sy<<endl;
                        idx++;
                        if(idx%100==0 )
                        {idx=0;
                            char okok;

                        cin>>okok;
                        }*/

                    }
                    ss.insert(ex);

                    answerr=ss.size();
                }
                ans[ex][ey]=answerr;
                x=i;
                y=j;
                while(1)
                {
                    if(x==ex && y==ey) break;
                    ans[x][y]=answerr;
                    y=(y+plusz[x])%MOD;
                    x=ne[x][y%m[x]];
                    //cout<<x<<" "<<y<<" kellene: "<<ex<<" "<<ey<<endl;
                }
            }
        }
    }
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        int xx, yy;
        cin>>xx>>yy;
        yy=(yy+e9)%MOD;
        cout<<ans[xx][yy]<<endl;
    }





    return 0;
}