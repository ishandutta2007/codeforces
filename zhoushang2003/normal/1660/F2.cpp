#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int T,n,A,c[N],x,q[3][N],t[3],b[N],r;
string s;
void C(int i)
{
	for(;i<=3*n;i+=i&-i)
		b[i]++;
}
int Q(int i)
{
	r=0;
	for(;i;i-=i&-i)
		r+=b[i];
	return r;
}
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>s)
	{
		s=' '+s,t[0]=t[1]=t[2]=A=0,q[0][++t[0]]=n+n;
		for(int i=1;i<=n;i++)
			c[i]=c[i-1]+(s[i]=='+'?-1:1),x=(c[i]%3+3)%3,q[x][++t[x]]=c[i]+n+n;
		for(int i=0;i<3;i++)
		{
			for(int j=1;j<=3*n;j++)
				b[j]=0;
			for(int j=1;j<=t[i];j++)
				A+=Q(x=q[i][j]),C(x);
		}
		cout<<A<<'\n';
	}
}