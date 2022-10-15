#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lbt(x) ((x)&-(x))
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return f?r:-r;
}
const int N=22,mod=31607,inv=3973;
int n,a[N][N];
int f[1<<N],num[1<<N],mul[N][1<<N];
int main(){
	n=read();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)a[i][j]=read()*inv%mod;
	for(int i=0;i<n;i++)num[1<<i]=i;
	int S=(1<<n)-1;
	for(int i=0;i<n;i++){
		mul[i][0]=1;
		for(int s=1;s<=S;s++){
			int x=lbt(s);
			mul[i][s]=mul[i][s^x]*a[num[x]][i]%mod;
		}
	}
	int ans=0;
	for(int t=0;t<4;t++){
		for(int s=0;s<=S;s++)
			f[s]=(__builtin_popcount(s)^__builtin_popcount(t))&1?mod-1:1;
		for(int i=0;i<n;i++)
			for(int s=0;s<=S;s++){
				int b=s;
				if(t&1)b|=1<<i;
				if(t>1)b|=1<<n-i-1;
				f[s]=f[s]*mul[i][b]%mod*(mod+1-mul[i][b^S])%mod;
			}
		for(int s=0;s<=S;s++)ans=(ans+f[s])%mod;
	}
	cout<<(mod+1-ans)%mod;
	return 0;
}