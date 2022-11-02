#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, k;
int cost[89][89];
//vi bests[89][89];
int best[89][89][5];
int was[89];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>cost[i][j];
        }
    }

    if(n==2)
    {
        cout<<((cost[0][1]+cost[1][0])*(k/2))<<endl;
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            /*set<pii> s;
            for(int x=1; x<n; x++)
            {
                if(x==i || x==j) continue;
                int cc=cost[i][x]+cost[x][j];
                if(s.size()<maxtop)
                {
                    s.insert({-cc, x});
                }
                else
                {
                    if(-(*s.begin()).F>cc)
                    {
                        s.erase(s.begin());
                        s.insert({-cc, x});
                    }
                }
            }
            for(pii p: s)
            {
                bests[i][j].push_back(p.S);
            }
            reverse(bests[i][j].begin(), bests[i][j].end());*/
            for(int x=1; x<n; x++)
            {
                if(x==i || x==j) continue;
                int cc=cost[i][x]+cost[x][j];
                if(best[i][j][0]==0 || cc<cost[i][best[i][j][0]]+cost[best[i][j][0]][j])
                {
                    best[i][j][3]=best[i][j][2];
                    best[i][j][2]=best[i][j][1];
                    best[i][j][1]=best[i][j][0];
                    best[i][j][0]=x;
                    continue;
                }
                if(best[i][j][1]==0 || cc<cost[i][best[i][j][1]]+cost[best[i][j][1]][j])
                {
                    best[i][j][3]=best[i][j][2];
                    best[i][j][2]=best[i][j][1];
                    best[i][j][1]=x;
                    continue;
                }
                if(best[i][j][2]==0 || cc<cost[i][best[i][j][2]]+cost[best[i][j][2]][j])
                {
                    best[i][j][3]=best[i][j][2];
                    best[i][j][2]=x;
                    continue;
                }
                if(best[i][j][3]==0 || cc<cost[i][best[i][j][3]]+cost[best[i][j][3]][j])
                {
                    best[i][j][3]=x;
                    continue;
                }
            }
        }
    }
    int ans=1e9+1;
    int pownk=1;
    int cn=k/2-1;
    for(int i=1; i<=cn; i++)
    {
        pownk*=n;
    }

    for(int msk=0; msk<pownk; msk++)
    {
        int ms=msk;
        was[0]=msk+1;
        for(int i=0; i<=cn; i++)
        {
            was[ms%n]=msk+1;
            ms/=n;
        }
        ms=msk;
        int last=0;
        bool jo=true;
        int cans=0;
        for(int i=0; i<=cn; i++)
        {
            int bestmiddle=-1;
            int cur=ms%n;
            ms/=n;
            for(int j=0; j<4; j++)
            {
                if(best[last][cur]==0) break;
                if(was[best[last][cur][j]]<=msk)
                {
                    bestmiddle=best[last][cur][j];
                    break;
                }
            }
            if(bestmiddle==-1)
            {
                jo=false;
                break;
            }
            cans+=(cost[last][bestmiddle]+cost[bestmiddle][cur]);
            last=cur;
            if(cans>=ans)
            {
                jo=false;
                break;
            }
        }
        if(!jo) continue;
        ans=min(ans, cans);
        //int cans=0;
        //cpoints.push_back(0);
        /*bool jo=true;
        for(int i=0; i<=cn; i++)
        {
            int bestmiddle=-1;
            for(int j=0; j<4; j++)
            {
                if(best[cpoints[i]][cpoints[i+1]]==0) break;
                if(!was[best[cpoints[i]][cpoints[i+1]][j]])
                {
                    bestmiddle=best[cpoints[i]][cpoints[i+1]][j];
                    break;
                }
            }
            if(bestmiddle==-1)
            {
                jo=false;
                break;
            }
            cans+=(cost[cpoints[i]][bestmiddle]+cost[bestmiddle][cpoints[i+1]]);
            if(cans>=ans)
            {
                jo=false;
                break;
            }
        }
        for(int x: cpoints) was[x]=false;
        if(!jo) continue;
        ans=min(ans, cans);*/

    }
    cout<<ans<<endl;

    return 0;
}