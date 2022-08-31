#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005

using namespace std;
typedef long long int ll;

struct P
{
	int f,s;
	P(int f=0,int s=0):f(f),s(s){}
	bool operator<(const P&l) const
	{
		if(f!=l.f) return f<l.f;
		return s<l.s;
	}
	bool operator>(const P&l) const
	{
		if(f!=l.f) return f>l.f;
		return s>l.s;
	}
};
vector <P> can,one;

P get(int s)
{
	int num=0;
	for(int i=0;i<one.size();i++)
	{
		if(one[i].f==1||one[i].s>s) break;
		s-=one[i].s;num++;
	}
	return P(num,s);
}
int main()
{
	int n,d,s;
	scanf("%d %d %d",&n,&d,&s);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		int c,f,l;
		scanf("%d %d %d",&c,&f,&l);
		if(c==0) one.push_back(P((l>=d)^1,f));
		else
		{
			sum+=(ll) c-1;
			can.push_back(P((l>=d)^1,f));
		}
	}
	sort(can.begin(),can.end());
	sort(one.begin(),one.end());
	int now=s;
	P ret=get(now);
	int pos=ret.f-1,ss=now-ret.s;
	for(int i=0;i<can.size();i++)
	{
		if(can[i].s>now||can[i].f==1) break;
		now-=can[i].s;
		sum++;//
		if(sum+can.size()>=n)
		{
			printf("%d %d\n",n,s-now);
			return 0;
		}
		for(;(pos>=0&&ss>now)||(((int) one.size())-pos+1)<=sum;pos--) ss-=one[pos].s;
		ret=max(ret,P((pos+1)+sum+can.size(),now-ss));
	}
	printf("%d %d\n",ret.f,s-ret.s);
	return 0;
}