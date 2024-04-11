#include<bits/stdc++.h>
#define maxn 100200

using namespace std;

int a[maxn],x[maxn],y[maxn],n,k,cnt[maxn];

int main()
{
    scanf("%d",&n);for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(x,0,sizeof(x));memset(y,0,sizeof(y));
    for (int i=1;i<=n;i++)
    {
        x[i]=x[i-1];y[i]=y[i-1];
        if (a[i]>x[i]) y[i]=x[i],x[i]=a[i];
        else if (a[i]>y[i]) y[i]=a[i];
    }
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) if (y[i]==a[i]) cnt[x[i]]++;
    for (int i=1;i<=n;i++) if (x[i]==a[i]) cnt[a[i]]--;
    k=1;for (int i=2;i<=n;i++) if (cnt[i]>cnt[k]) k=i;
    printf("%d\n",k);return 0;
}