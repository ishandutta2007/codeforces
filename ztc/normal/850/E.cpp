#include<stdio.h>
#define mod 1000000007
int a[1048576],n,m,ans=0;char c[2000000];
inline void Mod(int &p){p>=mod&&(p-=mod);}
inline void div(int &p){p>=mod&&(p-=mod),(p&1)&&(p+=mod),p>>=1;}
int main(){
	scanf("%d%s",&n,c);m=1<<n;
	for(int i=0;i<m;i++)a[i]=c[i]=='1';
	for(int i=0;i<n;i++)for(int j=0,v;j<m;j++)if(j>>i&1)Mod(v=a[j^1<<i]+mod-a[j]),Mod(a[j^1<<i]+=a[j]),a[j]=v;
	for(int i=0;i<m;i++)a[i]=1ull*a[i]*a[i]%mod;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(j>>i&1)div(a[j^1<<i]+=a[j]),Mod(a[j]=a[j^1<<i]+mod-a[j]);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(!(j>>i&1))Mod(a[j]<<=1);
	for(int i=0;i<m;i++)Mod(ans+=a[i]);
	printf("%lld",3ull*ans%mod);
}