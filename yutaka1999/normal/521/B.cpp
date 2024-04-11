#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 100005
#define MOD 1000000009

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;
typedef pair <int,P> PP2;

set <PP> st;
set <PP>::iterator it,IT;
set <PP2> can;
set <PP2>::iterator its;
ll rt[SIZE];

bool ok(P p)
{
	for(int i=-1;i<=1;i++)
	{
		P q=P(p.first+i,p.second+1);
		it=st.lower_bound(PP(q,-1));
		if(it!=st.end()&&it->first==q)
		{
			int cnt=0;
			for(int j=-1;j<=1;j++)
			{
				P r=P(q.first+j,q.second-1);
				it=st.lower_bound(PP(r,-1));
				if(it!=st.end()&&it->first==r) cnt++;
			}
			if(cnt<=1) return false;
		}
	}
	return true;
}
int main()
{
	int m;
	scanf("%d",&m);
	rt[0]=1;
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		st.insert(PP(P(x,y),i));
		if(i>0) rt[i]=rt[i-1]*(ll) m%MOD;
	}
	for(IT=st.begin();IT!=st.end();IT++)
	{
		PP r=(*IT);
		P p=r.first;
		if(ok(p))
		{
			can.insert(PP2(r.second,r.first));
		}
	}
	ll ret=0;
	for(int i=0;i<m;i++)
	{
		if(i%2==1) its=can.begin();
		else
		{
			its=can.end();
			its--;
		}
		//printf("%d [%d %d]\n",its->first,its->second.first,its->second.second);
		ret+=rt[m-i-1]*(ll) (its->first)%MOD;
		if(ret>=MOD) ret-=MOD;
		st.erase(PP(its->second,its->first));
		P p=its->second;
		can.erase(its);
		for(int j=-2;j<=2;j++)
		{
			for(int k=-1;k<=1;k++)
			{
				P q=P(p.first+j,p.second+k);
				it=st.lower_bound(PP(q,-1));
				if(it!=st.end()&&it->first==q)
				{
					can.erase(PP2(it->second,it->first));
					PP r=(*it);
					if(ok(r.first))
					{
						can.insert(PP2(r.second,r.first));
					}
				}
			}
		}
	}
	printf("%I64d\n",ret);
	return 0;
}