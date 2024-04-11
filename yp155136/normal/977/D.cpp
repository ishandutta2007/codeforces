#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 106;

LL a[N];

bool vis[N];

int n;

vector<LL> ans;

void dfs(int i)
{
    vis[i] = true;
    //printf("%lld ",a[i]);
    ans.push_back(a[i]);
    for (int j=1;n>=j;j++)
    {
        if (i==j) continue;
        if (a[i] == a[j]*2)
        {
            if (!vis[j]) dfs(j);
        }
        else if (a[j] == a[i]*3)
        {
            if (!vis[j]) dfs(j);
        }
    }
}

int main ()
{
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&a[i]);
    }
    if (n == 2 && false)
    {
        printf("%lld %lld\n",a[1],a[2]);
        return 0;
    }
    else
    {
        for (int i=1;n>=i;i++)
        {
            int cnt=0;
            for (int j=1;n>=j;j++)
            {
                if (i==j) continue;
                if (a[i]*2 == a[j]) cnt++;
                else if (a[j]*3 == a[i]) cnt++;
            }
            if (cnt == 0)
            {
                dfs(i);
                reverse(ans.begin(),ans.end());
                for (int i=0;n>i;i++)
                {
                    if (i) printf(" ");
                    printf("%lld",ans[i]);
                }
                puts("");
                //puts("");
                return 0;
            }
        }
    }
}