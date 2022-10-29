#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n;
long long f[1<<20],g[1<<20];
char s[1<<20];
typedef long long LL;
void fwt(LL x[],int len,int mode)
{
	LL ni=(mod+1)/2;
    for(int i=2;i<=len;i<<=1)
    {
        int step=i>>1;
        for(int j=0;j<len;j+=i)
            for(int k=j;k<j+step;k++)
            {
                LL a=x[k],b=x[k+step];
                x[k]=(a+b)%mod;
                x[k+step]=(a-b+mod)%mod;
                if(mode==-1) (x[k]*=ni)%=mod,(x[k+step]*=ni)%=mod;
            }
    }
}
int main(){
	scanf("%d%s",&n,&s);
	int len=(1<<n);
	for(int i=0;i<len;++i){
		if(s[i]=='0')f[i]++;
		else g[i]++;
	}
	int ans=0;
	fwt(f,len,1);
	fwt(g,len,1);
	for(int i=0;i<len;++i)
		f[i]=1ll*f[i]*g[i]%mod;
	fwt(f,len,-1);
	for(int i=0;i<len;++i)
		ans=(ans+(1ll<<__builtin_popcount(i))*f[i])%mod;
	printf("%d",ans*3ll%mod);
}