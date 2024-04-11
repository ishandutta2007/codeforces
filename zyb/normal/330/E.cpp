#include <cstdio>
#include <algorithm>
#include <vector>
#define maxn 100005
using namespace std;

int n,m,ans;
int a[maxn];
vector<int>v[maxn];

void solve()
{
    int i,j,k,flag=0,ok,sz,tmp;
    for(i=1; i<=500; i++)     // 500
    {
        ok=1;
        random_shuffle(a+1,a+n+1);
        for(j=1;j<=m;j++)     // 
        {
            sz=v[a[j]].size();
            for(k=0;k<sz;k++)
            {
                if(j==n) tmp=1;   // m==n
                else tmp=j+1;
                if(v[a[j]][k]==a[tmp])
                {
                    ok=0;
                    break ;
                }
            }
        }
        if(ok)
        {
            flag=1;
            for(j=1;j<=m;j++)
            {
                if(j==n) tmp=1;
                else tmp=j+1;
                printf("%d %d\n",a[j],a[tmp]);
            }
            break ;
        }
    }
    if(!flag) printf("-1\n");
}
int main()
{
    int i,j,l,r;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1; i<=n; i++)
        {
            v[i].clear();
            a[i]=i;
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d%d",&l,&r);
            v[l].push_back(r);
            v[r].push_back(l);
        }
        solve();
    }
    return 0;
}