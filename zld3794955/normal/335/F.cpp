#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,now=0;
	long long s=0; 
	map<int,int> m;
	priority_queue<int,vector<int>,greater<int> > q,q2;
	scanf("%d",&n);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		s+=x;
		++m[x];
	}
	for(auto it=m.rbegin(); it!=m.rend(); ++it)
	{
		int a=it->first,y=it->second;
		while(y && now)
			q2.push(a),--y,--now;
		for(; y>=2 && (!q.empty() && q.top()<a+a); y-=2)
		{
			if(q.top()<a)
				q2.push(a),q2.push(a);
			else
				q2.push(a+a-q.top()),q2.push(q.top());
			q.pop();
		}
		if(y && !q.empty() && q.top()<a)
			q.pop(),q2.push(a);
		while(!q2.empty())
			q.push(q2.top()),q2.pop();
		now+=y;
	}
	for(; !q.empty(); q.pop())
		s-=q.top();
	printf("%I64d\n",s);
	return 0;
}