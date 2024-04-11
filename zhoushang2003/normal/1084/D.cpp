#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=3e5+1;
bool v[N];
int n,m,x,y,z,c[N],q[N],t,X,s;
long long w[N],f[N],p[N],A;
vector<int>a[N];
vector<long long>b[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	m=n-1;
	while(m--&&cin>>x>>y>>z)
		a[x].push_back(y),b[x].push_back(z),a[y].push_back(x),b[y].push_back(z),c[x]++,c[y]++;
	for(int i=1;i<=n;i++)
		if(c[i]==1)
			q[t++]=i;
	while(t)
	{
		X=q[--t],v[X]=true,f[X]=w[X],s=0;
		for(int i=0;i<a[X].size();i++)
			if(v[a[X][i]])
				p[s++]=max((long long)0,f[a[X][i]]-b[X][i]);
		if(s>1)
			sort(p,p+s),A=max(A,p[s-1]+w[X]+p[s-2]);
		if(s>0)
			f[X]+=p[s-1];
		A=max(A,f[X]);
		for(int i=0;i<a[X].size();i++)
			if(!v[a[X][i]])
			{
				c[a[X][i]]--;
				if(c[a[X][i]]==1)
					q[t++]=a[X][i];
			}
	}
	if(n==1)
		cout<<w[1];
	else
		cout<<A;
	return 0;
}