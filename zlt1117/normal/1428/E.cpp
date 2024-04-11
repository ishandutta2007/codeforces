#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
inline long long calc(long long _a,long long _b)
{
	long long now=(_a%_b)*(_a/_b+1)*(_a/_b+1);
	now+=(_b-_a%_b)*(_a/_b)*(_a/_b);
	return now;
}
struct node
{
	long long a,b;
	node(long long aa=0,long long bb=0){a=aa,b=bb;}
	inline bool operator<(const node &bb)const
	{
		long long val=calc(a,b);
		val-=calc(a,b+1);
		long long val1=calc(bb.a,bb.b);
		val1-=calc(bb.a,bb.b+1);
		return val<=val1;
	}
};
multiset<node>s;
int n,a[100001],k;
long long ans;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)s.insert(node(a[i],1));
	for(int i=1;i<=k-n;++i)
	{
		auto it=s.end();
		--it;
		node x=*it;
		s.erase(it);
		s.insert(node(x.a,x.b+1));
	}
	while(s.size())
	{
		auto it=s.end();
		--it;
		node x=*it;
		s.erase(it);
		ans+=calc(x.a,x.b);
	}
	cout<<ans<<endl;
	return 0;
}