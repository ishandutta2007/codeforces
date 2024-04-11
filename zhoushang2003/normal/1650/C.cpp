#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct S
{
	int x,w,i;
};
int t,n,m,x,y,A;
S w[N];
bool C(S x,S y)
{
	return x.w<y.w;
}
bool D(S x,S y)
{
	return x.x<y.x;
}
int main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		for(int i=1;i<=m;i++)
			cin>>x>>y,w[i]={x,y,i};
		sort(w+1,w+m+1,C),sort(w+1,w+2*n+1,D),A=0;
		for(int i=1;i<=2*n;i++)
			A+=w[i].w;
		cout<<A<<'\n';
		for(int i=1;i<=n;i++)
			cout<<w[i].i<<' '<<w[2*n-i+1].i<<'\n';
		cout<<'\n';
	}
}