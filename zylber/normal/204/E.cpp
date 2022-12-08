#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

#define MAXN 200010
int bc[MAXN][20],  r[MAXN][20];
pair<int, int> p[20][MAXN];
string s[100010];
int sz[100010];
int tb[20];
vector<int> inbucket[100010][20];
int c, j;

bool compa(pair<int, int> a, pair<int, int> b)
{
    if(c==0) return s[a.first][a.second]<s[b.first][b.second];
    //cout << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
    return inbucket[a.first][j][min((a.second+c),sz[a.first]-1)]<inbucket[b.first][j][min((b.second+c),sz[b.first]-1)];
}

int tot;
void suffixarray(int n)
{
    tot=0;
    forn(i, n)
    {
        sz[i]=s[i].size();
        forn(j, 20)
            inbucket[i][j].resize(sz[i]);
        forn(j, sz[i])
        {   
            inbucket[i][0][j]=0;
            p[0][tot]=make_pair(i, j);
            tot++;
        }
    }
    bc[0][0]=0;
    bc[1][0]=tot;
    tb[0]=1;
    
    for(j=0; j<18; j++)
    {
        c=(1<<j);
        c/=2;
    
        forn(i, tot)
        {
            p[j+1][i]=p[j][i];
        }
        
        tb[j+1]=0;
        forn(i, tb[j])
        {
            if(bc[i+1][j]-bc[i][j]>1)
            {
                sort(p[j+1]+bc[i][j], p[j+1]+bc[i+1][j], compa);
            }
            
            int it=bc[i][j];
            bc[tb[j+1]][j+1]=it;
            tb[j+1]++;
            
            while(it<bc[i+1][j])
            {
                //cout << compa(p[j+1][it-1], p[j+1][it]) << endl;
                if(it-bc[i][j] && compa(p[j+1][it-1], p[j+1][it]))
                {
                    bc[tb[j+1]][j+1]=it;
                    tb[j+1]++;
                }
                inbucket[p[j+1][it].first][j+1][p[j+1][it].second]=tb[j+1]-1;
                it++;
            }
            
        }
        bc[tb[j+1]][j+1]=tot;
        //cout << tb[j+1] << endl;
    }
}

int match(pair<int,int> a, pair<int, int> b)
{
    if(s[a.first][a.second]!=s[b.first][b.second]) return 0;
    
    int m=min(sz[b.first]-b.second, sz[a.first]-a.second)-1;
    int t=1, j=2;
    while(t<m)
    {
        if(inbucket[a.first][j][a.second]!=inbucket[b.first][j][b.second]) return t+match(make_pair(a.first, a.second+t), make_pair(b.first, b.second+t));
        t*=2; j++;
    }
    return m;
}

int cantin[200010], dif;
int cantpre[200010];
tint ans[200010];
vector<int> salen[200010];

int main()
{
#ifdef ACMTUYO
    freopen("129E.in","r",stdin);
#endif
    memset(ans, 0, sizeof(ans));
    memset(cantpre, 0, sizeof(cantpre));
    int n, k;
    cin >> n >> k;
    forn(i, n)
    {
        cin >> s[i];
        s[i]+='a'-1;
    }
    
    suffixarray(n);
    
    dif=0;
    int i1=0, i2=0;
    while(p[18][i1].second == sz[p[18][i1].first]-1) { i1++; i2++; }
    
    multiset<int> goles;
    while(i1<tot)
    {
        //cout << p[18][i1].first << " " << p[18][i1].second << endl;
        //cout << i1 << " " << i2 << endl;
        while(i2<tot && dif<k)
        {
            pair<int, int> next=p[18][i2];
            if(!cantin[next.first]) dif++;
            cantin[next.first]++;
            i2++;
        }
        
        if(dif>=k)
        {
            //cout << i1 << " " << i2 << endl;
            //cout << p[18][i1].first << " " << p[18][i1].second << " " << p[18][i2-1].first << " " << p[18][i2-1].second << endl; 
            int mach=match(p[18][i1], p[18][i2-1]);
            //cout << mach << endl;
        
            /*int top=tot, bot=i2-1;
            while(top-bot>1)
            {
                int mid=(top+bot)/2;
                if(mach==match(p[18][i1], p[18][mid]))
                {
                    bot=mid;
                }
                else
                {
                    top=mid;
                }
            }*/
            //cout << top << endl;
            salen[i2].push_back(mach);
            goles.insert(mach);
            //cout << mach << endl;
            //for(int j=i1; j<top; j++) cantpre[j]=max(cantpre[j], mach);
        }
        
        //cout << goles.size() << endl;
        int vs=salen[i1].size();
        //cout << vs << endl;
        forn(j, vs) goles.erase(goles.find(salen[i1][j]));
        //cout << goles.size() << endl;
        if(!goles.empty())
        {
            multiset<int>::iterator cand=goles.end(); cand--;
            cantpre[i1]=(*cand);
        }
        pair<int, int> act=p[18][i1];
        cantin[act.first]--;
        if(!cantin[act.first]) dif--;
        i1++;
    }
    
    dif=0;
    memset(cantin, 0, sizeof(cantin));
    goles.clear();
    forn(i, tot) salen[i].clear();
    i1=tot-1; i2=tot-1;
    while(p[18][i1].second != sz[p[18][i1].first]-1)
    {
        //cout << p[18][i1].first << " " << p[18][i1].second << endl;
        //cout << i1 << " " << i2 << endl;
        while(p[18][i2].second != sz[p[18][i2].first]-1 && dif<k)
        {
            pair<int, int> next=p[18][i2];
            if(!cantin[next.first]) dif++;
            cantin[next.first]++;
            i2--;
        }
        
        if(dif>=k)
        {
            //cout << i1 << " " << i2 << endl;
            //cout << p[18][i1].first << " " << p[18][i1].second << " " << p[18][i2-1].first << " " << p[18][i2-1].second << endl; 
            int mach=match(p[18][i1], p[18][i2+1]);
            //cout << mach << endl;
        
            /*int top=0, bot=i2+1;
            while(top-bot>1)
            {
                int mid=(top+bot)/2;
                if(mach==match(p[18][i1], p[18][mid]))
                {
                    bot=mid;
                }
                else
                {
                    top=mid;
                }
            }*/
            //cout << top << endl;
            salen[i2].push_back(mach);
            goles.insert(mach);
            //cout << mach << endl;
            //for(int j=i1; j<top; j++) cantpre[j]=max(cantpre[j], mach);
        }
        
        //cout << goles.size() << endl;
        int vs=salen[i1].size();
        //cout << vs << endl;
        forn(j, vs) goles.erase(goles.find(salen[i1][j]));
        //cout << goles.size() << endl;
        if(!goles.empty())
        {
            multiset<int>::iterator cand=goles.end(); cand--;
            cantpre[i1]=max(cantpre[i1],(*cand));
        }
        pair<int, int> act=p[18][i1];
        cantin[act.first]--;
        if(!cantin[act.first]) dif--;
        i1--;
    }
    
    //forn(j, tot) cout << cantpre[j] << " ";
    forn(j, tot) ans[p[18][j].first]+=cantpre[j];
    //cout << endl;
    forn(j, n){ if(j) cout << " "; cout << ans[j]; }
    cout << endl;
    /*forn(i, n)
    {
        forn(j, sz[i]) cout << cantpre[bc[inbucket[i][18][j]][18]] << " ";
        cout << endl;
    }*/
    return 0;
}