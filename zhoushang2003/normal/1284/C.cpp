#include <bits/stdc++.h>
using namespace std;
inline int read() 
{
    register int x = 0 , ch = getchar(); 
    while( !isdigit( ch ) ) ch = getchar(); 
    while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
    return x; 
}
unsigned long long quick_power(unsigned long long a,unsigned long long b,unsigned long long p)
{
    unsigned long long ans=1;
    while(b)
    {
        if(b%2)
        {
            ans=ans*a%p;        
        }
        a=a*a%p;
        b=(b>>1);
    }
    return ans;
}
unsigned long long turtle_muti(unsigned long long ain,unsigned long long bin,unsigned long long modn)
{
    unsigned long long res=0;
    for(;bin;bin>>=1) 
    {
        if(bin&1)
            res=(res+ain)%modn;
        ain=(ain<<1)%modn;
    }
    return res;
}
 
int n,m;
unsigned long long nfac[250010];
unsigned long long ans;
int main()
{
    n=read(),m=read();
    nfac[0]=1,nfac[1]=1;
    for(int i=2;i<=n;i++)
        nfac[i]=turtle_muti(nfac[i-1],i,m);
    for(int i=1;i<=n;i++)
    {
        unsigned long long qwq=1;
        qwq=turtle_muti(qwq,nfac[n-i],m);
        qwq=turtle_muti(qwq,nfac[i],m);
        qwq=turtle_muti(qwq,quick_power(n-i+1,2,m),m);
        ans+=qwq;
        ans%=m;
    }
    cout<<ans<<endl;
    return 0;
}