#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
long long n,k,x,y,s,A;
pair<int,int>p[N];
priority_queue<int>q;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		p[i]=make_pair(y,x);
	}
	sort(p+1,p+n+1);
	for(int i=n;i>=1;i--)
	{
		s+=p[i].second,q.push(-p[i].second);
		if(q.size()>k)
			s+=q.top(),q.pop();
		A=max(A,p[i].first*s);
	}
	cout<<A;
	return 0;
}