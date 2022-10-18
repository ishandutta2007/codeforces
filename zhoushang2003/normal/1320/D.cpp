#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6,P=998244353;
int n,m,b[N],s[N],f[N][2],x,y,z;
string a;
int H(int l,int r,int x)
{
	return (f[r][x]-f[l-1][x]*b[s[r]-s[l-1]]%P+P)%P;
}
signed main()
{
	cin>>n>>a>>m,a=' '+a,b[0]=1;
	for(int i=1;i<=n;i++)
		b[i]=3*b[i-1]%P,s[i]=s[i-1]+(a[i]=='0');
	for(int i=1;i<=n;i++)
		if(a[i]=='0')
			f[i][0]=(3*f[i-1][0]+1+(i&1))%P,f[i][1]=(3*f[i-1][1]+1+(i&1^1))%P;
		else
			f[i][0]=f[i-1][0],f[i][1]=f[i-1][1];
	while(m--&&cin>>x>>y>>z)
		puts(H(x,x+z-1,x&1)==H(y,y+z-1,y&1)?"YES":"NO");
}