#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct L
{
	ll a,b;//y=ax+b
	L(ll a=0,ll b=0):a(a),b(b){}
	bool operator<(const L&l) const
	{
		if(a!=l.a) return a<l.a;
		return b<l.b;
	}
};
bool down(L p,L q,L r)//p<q<r , p.a<q.a
{
	if(q.a==r.a) return true;
	return (q.b-r.b)*(q.a-p.a) <= (p.b-q.b)*(r.a-q.a);
}
L st[SIZE];
int main()
{
	int n;
	scanf("%d",&n);
	vector <L> vec;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		vec.push_back(L(-x,y-x*x));
	}
	//vec 
	sort(vec.begin(),vec.end());
	//XAX
	int sz=0;
	for(int i=0;i<n;i++)
	{
		while(sz>=2&&down(st[sz-2],st[sz-1],vec[i])) sz--;
		if(sz==1&&st[sz-1].a==vec[i].a) sz--;
		st[sz++]=vec[i];
	}
	printf("%d\n",sz-1);
	return 0;
}