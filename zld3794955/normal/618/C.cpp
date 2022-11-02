#include<bits/stdc++.h>
using namespace std;
#define int long long
class Constellation
{
	static const int N=100010;
	inline int sign(int x) { return x>0 ? 1 : x==0 ? 0 : -1; }
	struct point
	{
		int x,y,num;
	}b[N];
	int n;
	int cross(const point &a,const point &b,const point &c)
	{
		return sign((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
	}
	bool contain(const point &a,const point &b,const point &c,const point &p)
	{
		int v1=cross(a,b,p),v2=cross(b,c,p),v3=cross(c,a,p);
		return v1*v2>=0 && v2*v3>=0 && v3*v1>=0;
	}
	public:
	void solve()
	{
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>b[i].x>>b[i].y;
		int p1=1,p2=2,p3=0;
		for(int i=3;i<=n;++i)
			if(cross(b[p1],b[p2],b[i]))
			{
				p3=i;
				break;
			}
		for(int i=1;i<=n;++i)
			if(i!=p1 && i!=p2 && i!=p3 && contain(b[p1],b[p2],b[p3],b[i]))
			{
				if(cross(b[p1],b[p2],b[i]))
					p3=i;
				else
					p2=i;
			}
		cout<<p1<<' '<<p2<<' '<<p3<<endl;
	}
}T;
#undef int
int main()
{
	T.solve();
}