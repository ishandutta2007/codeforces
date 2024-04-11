#include<bits/stdc++.h>
using namespace std;
const int N=2001;
struct S
{
	int i,j,v;
};
bool v[N];
int n,x[N],y[N],z[N],c;
S w[N*N];
bool C(S x,S y)
{
	return x.v<y.v;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i]>>z[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			w[++c]=(S){i,j,abs(x[i]-x[j])+abs(y[i]-y[j])+abs(z[i]-z[j])};
	sort(w+1,w+c+1,C);
	for(int i=1;i<=c;i++)
		if(!v[w[i].i]&&!v[w[i].j])
		{
			cout<<w[i].i<<" "<<w[i].j<<'\n';
			v[w[i].i]=v[w[i].j]=true;
		}
	return 0;
}