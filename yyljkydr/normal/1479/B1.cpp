#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],nxt[N],to[N];

vector<int>v[2];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i>=1;i--)
        if(a[i]==a[i+1])
            to[i]=to[i+1];
        else
            to[i]=a[i+1];
    v[0].push_back(-1);
    v[1].push_back(-1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=v[0].back(),y=v[1].back();
        if(x!=a[i]&&y!=a[i])
        {
            int z=to[i];
            if(z==x)
                v[0].push_back(a[i]),ans++;
            else
                v[1].push_back(a[i]),ans++;
        }
        else if(x==a[i])
        {
            v[1].push_back(a[i]);
            ans+=y!=a[i];
        }
        else if(y==a[i])
        {
            v[0].push_back(a[i]);
            ans+=x!=a[i];
        }
    }
    printf("%d\n",ans);
}