#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Tree_independent_set
{
    static const int N = 1e6 + 6;
    int dp[2][N];
    //int dp[1][N];
    bool vis[N];
    vector<int> G[N];
    int n;
    void init(int n)
    {
        this->n = n;
        for (int i=0;n>=i;i++)
        {
            dp[0][i] = 0;  //have i
            dp[1][i] = 0;  //not have i
            vis[i] = 0;
            G[i].clear();
        }
    }
    void add_edge(int x,int y)
    {
        G[x].push_back(y);
        G[y].push_back(x);
    }
    void dfs(int now)
    {
        vis[now] = 1;
        //vector<int> v;
        dp[0][now] = 1;
        int inn = 0;
        for (int son:G[now])
        {
            if (!vis[son])
            {
                inn = 1;
                dfs(son);
                dp[0][now] += dp[1][son];
                dp[1][now] += max(dp[0][son],dp[1][son]);
            }
        }
        if (!inn)
        {
            dp[0][now] = 1;
            dp[1][now] = 0;
        }
    }
    int kirino()
    {
        int ret=0;
        for (int i=1;n>=i;i++)
        {
            if (!vis[i])
            {
                dfs(i);
                //cout<<"i = "<<i<<" , max = "<<max(dp[0][i],dp[1][i])<<endl;
                ret += max(dp[0][i],dp[1][i]);
            }
            //cout<<"dp0 = "<<dp[0][i]<<" , dp1 = "<<dp[1][i]<<endl;
        }
        return ret;
    }
} sagiri;

const int N = 1e6 + 6;

string s[N];

typedef long long LL;
typedef pair<LL,LL> pii;

pii operator+(const pii &p1,const pii &p2)
{
    return make_pair(p1.first+p2.first,p1.second+p2.second);
}

/*
pii operator-(const pii &p1,const pii &p2)
{
    return make_pair(p1.first-p2.first,p1.second-p2.second);
}
*/

pii operator*(const pii &p1,const pii &p2)
{
    return make_pair(p1.first*p2.first,p1.second*p2.second);
}

pii operator%(const pii &p1,const pii &p2)
{
    return make_pair(p1.first%p2.first,p1.second%p2.second);
}

const pii mod = make_pair(1000000007,1000000009);
const pii X = make_pair(19753,997);

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i=1;n>=i;i++)
        {
            cin >> s[i];
        }
        map<pii,int> mp;
        int idd=0;
        for (int i=1;n>=i;i++)
        {
            pii pre = make_pair(0,0);
            pii x = make_pair(1,1);
            for (int j=0;s[i].size()>j;j++)
            {
                pre = (pre + make_pair(s[i][j],s[i][j]) * x) % mod;
                x = (x * X)%mod;
                if (mp.find(pre) == mp.end())
                {
                    mp.insert(make_pair(pre,(++idd)));
                }
                //cout<<"pre = "<<pre.first<<","<<pre.second<<endl;
            }
        }
        int nm = mp.size();
        //cout<<"nm  = "<<nm<<endl;
        sagiri.init(nm);
        for (int i=1;n>=i;i++)
        {
            pii pre = make_pair(0,0);
            pii x = make_pair(1,1);
            pii pre2 = make_pair(0,0);
            pii x2 = make_pair(1,1);
            for (int j=0;s[i].size()>j;j++)
            {
                pre = (pre + make_pair(s[i][j],s[i][j]) * x) % mod;
                x = (x * X)%mod;
                if (j)
                {
                    pre2 = (pre2 + make_pair(s[i][j],s[i][j]) * x2) % mod;
                    x2 = (x2 * X) % mod;
                }
                if (j)
                {
                    //cout<<"pre2 = "<<pre2.first<<","<<pre2.second<<endl;
                    if (mp.find(pre2) != mp.end())
                    {
                        sagiri.add_edge(mp[pre],mp[pre2]);
                        //cout<<"edge = "<<mp[pre]<<" , "<<mp[pre2]<<endl;
                        //cout<<"inn"<<endl;
                    }
                }
                /*
                if (mp.find(pre) == mp.end())
                {
                    mp.insert(make_pair(pre,(++idd)));
                }
                */
            }
        }
        cout<<sagiri.kirino()<<endl;
    }
}