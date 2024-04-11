#include<bits/stdc++.h>
#define maxh 20
#define maxn 300050
using namespace std;

int n,a[maxn];

int Log2[maxn];
int ST[maxn][maxh];

int L[maxn],R[maxn],cnt[maxn];

int ans[maxn];

int main()  {
    Log2[0]=-1;
    for (int i=1;i<maxn;++i) Log2[i]=Log2[i>>1]+1;

    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d",a+i),L[i]=n,R[i]=cnt[i]=0;
        
        for (int i=1;i<=n;++i)  {
            ST[i][0]=a[i];
            ++cnt[a[i]];
            L[a[i]]=min(L[a[i]],i);
            R[a[i]]=max(R[a[i]],i);
        }
        for (int j=1;j<=Log2[n];++j)
            for (int i=1;i+(1<<j)-1<=n;++i)
                ST[i][j]=min(ST[i][j-1],ST[i+(1<<j-1)][j-1]);
        auto Min=[&](int l,int r)   {
            int t=Log2[r-l+1];
            return min(ST[l][t],ST[r-(1<<t)+1][t]);
        };

        int lim=0;
        for (int i=1;i<=n;++i)
            lim=max(lim,R[i]-L[i]+1);
        
        for (int i=1;i<=n;++i) ans[i]=0;
        int l=1,r=n;
        for (int len=n;len>=lim;--len)  {
            // cout<<"len:"<<len<<" "<<Min(l,r)<<" "<<n-len+1<<endl;
            if (Min(l,r)==n-len+1)
                ans[len]=1;
            if (a[l]==n-len+1)
                ++l;
            else
            if (a[r]==n-len+1)
                --r;
            else
                break;
        }

        ans[1]=1;
        for (int i=1;i<=n;++i)
            ans[1]&=(cnt[i]==1);
        
        for (int i=1;i<=n;++i)
            printf("%d",ans[i]);
        puts("");
    }
    return 0;
}