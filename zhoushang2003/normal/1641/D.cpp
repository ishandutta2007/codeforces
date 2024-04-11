#include<bits/stdc++.h>
using namespace std;
const int N=1e5,D=12045,I=2e9+1;
struct S
{
	int a[6],x;
};
int n,m,x,A=I;
S w[N];
bitset<N>p[D+1];
bool C(S x,S y)
{
	return x.x<y.x;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>x,w[i].a[j]=x%D;
		cin>>w[i].x;
	}
	sort(w,w+n,C);
	for(int i=0;i<n;i++)
	{
		bitset<N>b;
		for(int j=1;j<=m;j++)
			b|=p[w[i].a[j]];
		x=(~b)._Find_first();
		if(0<=x&&x<i)
			A=min(A,w[i].x+w[x].x);
		for(int j=1;j<=m;j++)
			p[w[i].a[j]][i]=1;
	}
	cout<<(A==I?-1:A);
}