#include<bits/stdc++.h>
using namespace std;

const int P=1e9+7;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    T=1;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        int ans=0;
        int fc=1;
        vector<int>iv(n+1);
        iv[0]=iv[1]=1;
        for(int i=2;i<=n;i++)
            iv[i]=1ll*iv[P%i]*(P-P/i)%P;
        int c=1;
        for(int i=0;i<=min(n,k);i++)
            (ans+=c)%=P,c=1ll*c*(n-i)%P*iv[i+1]%P;
        printf("%d\n",ans);
    }
}