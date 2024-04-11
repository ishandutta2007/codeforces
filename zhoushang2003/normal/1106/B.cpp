#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct S
{
	int i;
	long long a,c;
};
int n,m,p[N],t,c;
long long A,d;
S w[N];
bool C(S x,S y)
{
	if(x.c!=y.c)
		return x.c<y.c;
	return x.i<y.i;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		w[i].i=i;
	for(int i=0;i<n;i++)
		cin>>w[i].a;
	for(int i=0;i<n;i++)
		cin>>w[i].c;
	sort(w,w+n,C);
	for(int i=0;i<n;i++)
		p[w[i].i]=i;
	while(m--&&cin>>t>>d)
	{
		A=0;
		if(w[p[t-1]].a<d)
			A+=w[p[t-1]].a*w[p[t-1]].c,d-=w[p[t-1]].a,w[p[t-1]].a=0;
		else
			A+=d*w[p[t-1]].c,w[p[t-1]].a-=d,d=0;
		while(c<n&&d)
			if(w[c].a<d)
				A+=w[c].a*w[c].c,d-=w[c].a,w[c++].a=0;
			else
				A+=d*w[c].c,w[c].a-=d,d=0;
		if(d)
			cout<<0<<endl;
		else
			cout<<A<<endl;
	}
	return 0;
}