#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int T,n,a[N],b[N],A,t;
void C(int i)
{
	for(;i;i-=i&-i)
		b[i]--;
}
int Q(int i)
{
	t=0;
	for(;i<=n;i+=i&-i)
		t+=b[i];
	return t;
}
int main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		A=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],b[i]=0;
		for(int i=1;i<=n;i++)
			A+=!Q(i),C(a[i]);
		cout<<A<<'\n';
	}
}