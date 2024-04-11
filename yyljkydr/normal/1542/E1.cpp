#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=501,S=130000;

int n,P;

int f[S*2+101],s[2][S*2+101];

signed main()
{
    scanf("%lld%lld",&n,&P);
    int now=1,last=0;
    f[S]=1;
    for(int j=-S+1;j<=S;j++)
        s[now][j+S]=(s[now][j+S-1]+f[j+S])%P;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        swap(now,last);
        for(int j=-S+i+1;j<=S-i+1;j++)
            f[j+S]=(f[j+S-1]-(s[last][j-1+S]-s[last][j-1+S-i])+(s[last][j-1+S+i]-s[last][j-1+S])+P+P)%P;
        for(int j=-S+1;j<=S;j++)
            s[now][j+S]=(s[now][j+S-1]+f[j+S])%P;
        int tot=0;
		for(int j=1;j<i;j++)
            tot=(tot+(s[last][S*2]-s[last][j+S]+P)%P*(i-j))%P;
        ans=(ans*i+tot)%P;
    }
    printf("%lld\n",ans);
}