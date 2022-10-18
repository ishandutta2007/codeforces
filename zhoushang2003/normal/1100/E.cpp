#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,I=1e9; 
struct S
{
	int a,b,c;
};
int n,m,l,r=I,c[N],q[N],s,t,X,d[N],A[N];
S w[N];
vector<int>a[N];
bool C(int k)
{
	memset(c,0,sizeof(c)),s=t=0;
	for(int i=1;i<=m;i++)
		if(w[i].c>k)
			a[w[i].a].push_back(w[i].b),c[w[i].b]++;
	for(int i=1;i<=n;i++)
		if(c[i]==0)
			q[t++]=i;
	while(s<t)
	{
		X=q[s++];
		for(int i=0;i<a[X].size();i++)
		{
			c[a[X][i]]--;
			if(c[a[X][i]]==0)
				q[t++]=a[X][i];
		}
	}
	for(int i=1;i<=n;i++)
		a[i].clear();
	if(t<n)
		return true;
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>w[i].a>>w[i].b>>w[i].c;
	while(l<r)
		if(C((l+r)/2))
			l=(l+r)/2+1;
		else
			r=(l+r)/2;
	C(l),t=0;
	for(int i=0;i<n;i++)
		d[q[i]]=i;
	for(int i=1;i<=m;i++)
		if(d[w[i].a]>d[w[i].b])
			A[t++]=i;
	cout<<l<<" "<<t<<endl;
	for(int i=0;i<t;i++)
		cout<<A[i]<<" ";
	return 0;
}