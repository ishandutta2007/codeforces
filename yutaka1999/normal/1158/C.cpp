#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
#include <functional>
#include <cmath>
#define SIZE 500005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
int deg[SIZE];
int id[SIZE];
P st[SIZE];

void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) vec[i].clear();
    for(int i=0;i<n;i++) deg[i]=0;
    int sz=0;
    bool up=true;
    for(int i=0;i<n;i++)
    {
        while(sz>0&&st[sz-1].first<=i) sz--;
        if(sz>0)
        {
            vec[st[sz-1].second].push_back(i);
            deg[i]++;
        }
        int to;
        scanf("%d",&to);
        to--;
        if(to>=0)
        {
            if(to<n)
            {
                vec[to].push_back(i);
                deg[i]++;
            }
            if(sz>0&&st[sz-1].first<to) up=false;
            st[sz++]=P(to,i);
        }
        //for(int j=0;j<sz;j++) printf("[%d %d] ",st[j].first,st[j].second);puts("");
    }
    if(!up)
    {
        puts("-1");
        return;
    }
    queue <int> que;
    for(int i=0;i<n;i++)
    {
        if(deg[i]==0)
        {
            que.push(i);
        }
    }
    sz=0;
    while(!que.empty())
    {
        int v=que.front();que.pop();
        id[v]=sz++;
        for(int i=0;i<vec[v].size();i++)
        {
            int to=vec[v][i];
            deg[to]--;
            if(deg[to]==0) que.push(to);
        }
    }
    if(sz!=n)
    {
        puts("-1");
        return;
    }
    for(int i=0;i<n;i++) printf("%d ",n-id[i]);
    puts("");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}