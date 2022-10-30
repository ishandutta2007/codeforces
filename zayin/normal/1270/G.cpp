#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;
typedef long long LL;

int n;
LL a[maxn],b[maxn];

bool vis[maxn],chs[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            vis[i]=chs[i]=0;
        for (int i=1;i<=n;++i)  {
            scanf("%lld",a+i);
            b[i]=i-a[i];
            // cout<<i<<" -> "<<b[i]<<endl;
        }
        for (int i=1;;i=b[i])  {
            if (vis[i]) {
                // cout<<"vis:"<<i<<endl;
                for (int j=b[i];;j=b[j])    {
                    chs[j]=1;
                    if (j==i) break;
                }
                break;
            }
            vis[i]=1;
        }

        LL sum=0,cnt=0;
        for (int i=1;i<=n;++i)
            if (chs[i])
                // cout<<"chs:"<<i<<endl,
                sum+=a[i],++cnt;
        assert(sum==0);

        printf("%lld\n",cnt);
        for (int i=1;i<=n;++i)
            if (chs[i])
                printf("%d ",i);
        puts("");
    }
    return 0;
}