#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
struct S
{
	int s,i;
};
int n,a[N],b[N],t,T;
S w[N],W[N];
bool c(S x,S y)
{
	return x.s<y.s;
}
bool C(S x,S y)
{
	return x.s>y.s;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
		if(a[i]>b[i])
			w[++t]=(S){a[i]+b[i],i};
		else
			W[++T]=(S){a[i]+b[i],i};
	if(t>=T)
	{
		sort(w+1,w+t+1,c);
		cout<<t<<'\n';
		for(int i=1;i<=t;i++)
			cout<<w[i].i<<" ";
	}
	else
	{
		sort(W+1,W+T+1,C);
		cout<<T<<'\n';
		for(int i=1;i<=T;i++)
			cout<<W[i].i<<" ";
	}
	return 0;
}