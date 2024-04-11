#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005
#define MX 5005

using namespace std;
typedef long long int ll;
typedef pair <int,ll> PL;

struct P
{
	int f,s;
	P(int f=0,int s=0):f(f),s(s){}
	bool operator<(const P&l) const
	{
		if(f!=l.f) return f<l.f;
		return s<l.s;
	}
};
int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
P st[MX],cur[MX];
vector <P> vec;
vector <PL> vv;

int main()
{
	int n,m;
	scanf("%d",&n);
	int sz=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<sz;j++) st[j].f=gcd(st[j].f,a);
		st[sz++]=P(a,1);
		int now=0;
		for(int j=0;j<sz;)
		{
			int s=j,cnt=0;
			for(;j<sz&&st[j].f==st[s].f;j++)
			{
				cnt+=st[j].s;
			}
			cur[now++]=P(st[s].f,cnt);
		}
		sz=now;
		for(int j=0;j<sz;j++)
		{
			st[j]=cur[j];
			vec.push_back(st[j]);
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();)
	{
		int s=i;
		ll sum=0;
		for(;i<vec.size()&&vec[i].f==vec[s].f;i++)
		{
			sum+=vec[i].s;
		}
		vv.push_back(PL(vec[s].f,sum));
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		int pos=lower_bound(vv.begin(),vv.end(),PL(a,-1))-vv.begin();
		if(pos<vv.size()&&vv[pos].first==a)
		{
			printf("%I64d\n",vv[pos].second);
		}
		else puts("0");
	}
	return 0;
}