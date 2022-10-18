#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
char o;
int n,m,P,a[N],f[N],c,x,y,z;
void C(int x,int y){
	if(x<=n)
		c-=!a[x],(a[x]+=z*y+P)%=P,c+=!a[x];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>P;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[i]=(i==1?1:(f[i-1]+f[i-2])%P);
	for(int i=1;i<=n;i++)
		cin>>x,(a[i]-=x-P)%=P;
	for(int i=n;i>1;i--)
		(a[i]-=a[i-1]+a[i-2]-P-P)%=P;
	for(int i=1;i<=n;i++)
		c+=!a[i];
	while(m--&&cin>>o>>x>>y)
		z=(o=='A'?1:-1),C(x,1),C(y+1,-f[y-x+2]),C(y+2,-f[y-x+1]),puts(c==n?"YES":"NO");
}