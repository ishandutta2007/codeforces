#include<bits/stdc++.h>
#define maxh 60
#define maxn 100050
using namespace std;
typedef long long LL;

const LL inf=1LL<<60;

int n;
LL a[maxn];

LL dp[maxh+1][maxn];

int pos[maxn];
int m,tmp[maxn];

LL pre0[maxn],pre1[maxn];

void Min(LL &a,LL b)    {
    a=min(a,b);
}

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)  a[i]=a[n]-a[i];
    for (int i=1;i<=n;++i)  pos[i]=i;
    // for (int i=1;i<=n;++i) cout<<a[i]<<" "; cout<<endl;

    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for (int i=0;i<maxh;++i)    {
        for (int j=1;j<=n;++j)  
            pre0[j]=pre0[j-1]+(~a[pos[j]]>>i&1),pre1[j]=pre1[j-1]+(a[pos[j]]>>i&1);
        // cout<<"pos:"; for (int j=1;j<=n;++j)    cout<<(a[pos[j]])<<" "; cout<<endl;
        // cout<<"pos:"; for (int j=1;j<=n;++j)    cout<<(a[pos[j]]>>i&1)<<" "; cout<<endl;
        // cout<<"pre0:"; for (int j=1;j<=n;++j)    cout<<pre0[j]<<" "; cout<<endl;
        // cout<<"pre1:"; for (int j=1;j<=n;++j)    cout<<pre1[j]<<" "; cout<<endl;
        for (int j=0;j<=n;++j)  {
            if (dp[i][j]>inf)   continue;
            // cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
            //0
            // cout<<"add:"<<pre1[j]<<" "<<dp[i][j]<<"+"<<(pre0[j]+pre1[n]-pre1[j])<<endl;
            Min(dp[i+1][pre1[j]],dp[i][j]+(pre0[j]+pre1[n]-pre1[j]));
            //1
            // cout<<"add:"<<j+pre1[n]-pre1[j]<<" "<<dp[i][j]<<"+"<<(pre1[j]+pre0[n]-pre0[j])<<endl;
            Min(dp[i+1][j+pre1[n]-pre1[j]],dp[i][j]+(pre1[j]+pre0[n]-pre0[j]));
        }

        for (int j=m=1;j<=n;++j)  tmp[j]=pos[j];
        for (int j=1;j<=n;++j)  
            if (a[tmp[j]]>>i&1)
                pos[m++]=tmp[j];
        for (int j=1;j<=n;++j)
            if (~a[tmp[j]]>>i&1)
                pos[m++]=tmp[j];
    }
    printf("%lld\n",dp[maxh][0]);
    return 0;
}