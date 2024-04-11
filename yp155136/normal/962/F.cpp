#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

vector<int> G[N];
int e[N];  //special way to represent edged
int x[N],y[N];

bool vis[N];
int low[N];
int depth[N];

vector<int> ans;

vector<int> bcc[N];
int bcc_cnt;

stack<int> sta;

int dfs_clock;

void dfs(int now,int par)
{
    vis[now] = true;
    depth[now] = low[now] = (++dfs_clock);
    for (int ii:G[now])
    {
        int i = (e[ii]^now);
        //cout << "now = " << now << " , ii = " << ii <<endl;
        if (i == par) continue;
        if (!vis[i])
        {
            sta.push(ii);
            dfs(i,now);
            low[now] = min(low[now],low[i]);
            if (low[i] >= depth[now])
            {
                ++bcc_cnt;
                while (!sta.empty())
                {
                    int t=sta.top();
                    sta.pop();
                    bcc[bcc_cnt].push_back(t);
                    if (t == ii) break;
                }
            }
        }
        else if (vis[i] && depth[i] < depth[now])
        {
            sta.push(ii);
            low[now] = min(low[now],depth[i]);
        }
    }
}

void go(int root)
{
    dfs(root,root);
    //while (!sta.empty()) cout << "sta has " << sta.top() <<endl , sta.pop();
    //for (int i:sta) cout << "sta has " << i << endl;
}

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;m>=i;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        e[i] = (x[i]^y[i]);
        G[ x[i] ].push_back(i);
        G[ y[i] ].push_back(i);
    }
    for (int i=1;n>=i;i++)
    {
        if (!vis[i]) go(i);
    }
    //cout << "bcc_cnt = " << bcc_cnt << " : " << endl;
    for (int i=1;bcc_cnt>=i;i++)
    {
        /*cout << "no " << i << " : ";
        for (int j:bcc[i]) cout << j << ' ';
        cout << endl;*/
        set<int> st;
        for (int j:bcc[i])
        {
            st.insert(x[j]);
            st.insert(y[j]);
        }
        if ((int)st.size() == (int)bcc[i].size())
        {
            for (int j:bcc[i])
            {
                ans.push_back(j);
            }
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for (int i=0;(int)ans.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}