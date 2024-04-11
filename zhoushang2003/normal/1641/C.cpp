#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,o,x,l,r,A,b[N];
set<int>s;
void C(int i,int x)
{
	for(;i<N;i+=i&-i)
		b[i]=max(b[i],x);
}
int Q(int i)
{
	A=0;
	for(;i;i-=i&-i)
		A=max(A,b[i]);
	return A;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)
		s.insert(i);
	while(m--&&cin>>o)
		if(o&&cin>>x)
			cout<<(s.count(x)?(Q(*s.upper_bound(x)-1)>*--s.lower_bound(x)?"YES":"N/A"):"NO")<<'\n';
		else
		{
			cin>>l>>r>>o;
			if(o)
				C(r,l);
			else
				while((x=*s.lower_bound(l))<=r)
					s.erase(x);
		}
}