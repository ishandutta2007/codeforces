#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,D=998244353;
int n,m,p[N],a[N],b[N],t,w[N],A,x,y;
int P(int a,int b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
void C(int i,int x)
{
	for(;i<N;i+=i&-i)
		w[i]+=x;
}
int Q(int i)
{
	t=0;
	for(;i;i-=i&-i)
		t+=w[i];
	return t;
}
signed main()
{
	cin>>n>>m,p[0]=1;
	for(int i=1;i<N;i++)
		p[i]=p[i-1]*i%D;
	x=p[n];
	for(int i=1;i<=n;i++)
		cin>>a[i],C(a[i],1),(x*=P(Q(a[i])-Q(a[i]-1),D-2))%=D;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		(A+=Q(b[i]-1)*P(n-i+1,D-2)%D*x+(i>n))%=D;
		if(y=Q(b[i])-Q(b[i]-1))
			(x*=y*P(n-i+1,D-2)%D)%=D,C(b[i],-1);
		else
			break;
	}
	cout<<A;
}