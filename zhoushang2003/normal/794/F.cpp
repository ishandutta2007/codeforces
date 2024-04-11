#import<bits/stdc++.h>
using namespace std;
#define int long long
#define I 2*k
#define J 2*k+1
#define d (l+r)/2
const int N=4e5,M=10;
int n,m,o,L,R,x,y,s[N][M],h[N][M],p[M];
void U(int k)
{
	for(int i=0;i<=9;i++)
		s[k][i]=0;
	for(int i=0;i<=9;i++)
		s[k][h[I][i]]+=s[I][i],s[k][h[J][i]]+=s[J][i];
}
void B(int k,int l,int r)
{
	for(int i=0;i<=9;i++)
		h[k][i]=i,s[k][i]=0;
	if(l==r&&cin>>x)
	{
		y=1;
		while(x)
			s[k][x%10]+=y,x/=10,y*=10;
		return;
	}
	B(I,l,d),B(J,d+1,r),U(k);
}
void V(int k)
{
	for(int i=0;i<=9;i++)
		h[I][i]=h[k][h[I][i]],h[J][i]=h[k][h[J][i]],p[i]=0;
	for(int i=0;i<=9;i++)
		p[h[k][i]]+=s[k][i];
	for(int i=0;i<=9;i++)
		s[k][i]=p[i],h[k][i]=i;
}
void C(int k,int l,int r,int L,int R,int x,int y)
{
	if(L<=l&&r<=R)
	{
		for(int i=0;i<=9;i++)
			if(h[k][i]==x)
				h[k][i]=y;
		return;
	}
	V(k);
	if(L<=d)
		C(I,l,d,L,R,x,y);
	if(R>d)
		C(J,d+1,r,L,R,x,y);
	U(k); 
}
int Q(int k,int l,int r,int L,int R)
{
	int A=0;
	if(L<=l&&r<=R)
	{
		for(int i=0;i<=9;i++)
			A+=s[k][i]*h[k][i];
		return A;
	}
	V(k);
	if(L<=d)
		A=Q(I,l,d,L,R);
	if(R>d)
		A+=Q(J,d+1,r,L,R);
	return A;
}
main()
{
	cin>>n>>m,B(1,1,n);
	while(m--&&cin>>o>>L>>R)
		if(o==1&&cin>>x>>y)
			C(1,1,n,L,R,x,y);
		else
			cout<<Q(1,1,n,L,R)<<'\n';
}