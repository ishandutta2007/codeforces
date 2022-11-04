#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100005
#define ll long long
using namespace std;
ll f[N][40],g[N][40],h[N][40];
ll n,m,x,ans1,ans2;
inline ll read(){
	ll x=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;
	return x;
}
int main(){
	n=read();
	m=read();
	for (ll i=0;i<n;i++) f[i][0]=read();
	for (ll i=0;i<n;i++) g[i][0]=h[i][0]=read();
	for (ll i=1;i<=35;i++)
		for (ll j=0;j<n;j++){
			f[j][i]=f[f[j][i-1]][i-1];
			g[j][i]=g[j][i-1]+g[f[j][i-1]][i-1];
			h[j][i]=min(h[j][i-1],h[f[j][i-1]][i-1]);
		}
	for (ll i=0;i<n;i++){
		ans2=1e10;
		ans1=0;
		x=i;
		for (ll tmp=m,p=0;tmp;tmp/=2,p++)
			if (tmp%2){
				ans1+=g[x][p];
				ans2=min(ans2,h[x][p]);
				x=f[x][p];
			}
		printf("%I64d %I64d\n",ans1,ans2);
	}
}