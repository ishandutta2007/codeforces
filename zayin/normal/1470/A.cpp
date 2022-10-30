#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
typedef long long LL;

int n,m;
int id[maxn];
LL c[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;++i) scanf("%d",id+i);
        for (int i=1;i<=m;++i) scanf("%lld",c+i);
        sort(id+1,id+n+1);

        int l=1,r=n;
        while (l<r) {
            int mid=(l+r)>>1;
            bool flag=1;
            for (int i=mid;i<=n;++i)
                flag&=i-mid+1<=id[i];
            
            // cout<<l<<" "<<r<<" "<<mid<<" "<<flag<<endl;
            if (flag)
                r=mid;
            else
                l=mid+1;
        }
        LL sum=0;
        for (int i=1;i<=n;++i) sum+=c[id[i]];
        LL ans=sum;
        for (int i=n;i>=l;--i)  {
            sum=sum-c[id[i]]+c[n-i+1];
            ans=min(ans,sum);
        }
        printf("%lld\n",ans);
    }
    return 0;
}