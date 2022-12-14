#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
long long n,s,c,A;
priority_queue<int>q;
pair<int,int>p[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first;
	for(int i=1;i<=n;i++)
		cin>>p[i].second;
	sort(p+1,p+n+1);
	p[n+1]=make_pair(2e9,0);
	for(int i=1;i<=n+1;i++)
	{
		c=p[i].first-p[i-1].first;
		while(!q.empty()&&c)
			s-=q.top(),A+=s,q.pop(),c--;
		q.push(p[i].second),s+=p[i].second;
	}
	cout<<A;
	return 0;
}