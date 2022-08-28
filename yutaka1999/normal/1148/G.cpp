#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cmath>
#include <cassert>
#define SIZE 100005
#define MX 10000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> dv[SIZE];
vector <int> ch[SIZE];
vector <P> dp[MX];
vector <int> vec;
int A[SIZE];
int pr[MX],pos[SIZE];
bool use[SIZE];

int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
void make()
{
	memset(pr,-1,sizeof(pr));
	for(int i=2;i<MX;i++)
	{
		if(pr[i]==-1)
		{
			for(int j=i;j<MX;j+=i) pr[j]=i;
		}
	}
}
bool check(int id,int X)
{
	int sz=dv[id].size();
	int sum=0;
	for(int S=1;S<1<<sz;S++)
	{
		int mul=1,c=-1;
		for(int i=0;i<sz;i++) if(S>>i&1) mul*=dv[id][i],c*=-1;
		int pos=lower_bound(dp[mul].begin(),dp[mul].end(),P(X+1,-1))-dp[mul].begin()-1;
		if(pos>=0)
		{
			sum+=c*dp[mul][pos].second;
		}
	}
	//if(X==0) printf("%d %d\n",id,sum);
	return sum==X+1;
}
int main()
{
	make();
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		int now=A[i];
		while(now>1)
		{
			int p=pr[now];
			dv[i].push_back(p);
			while(now%p==0) now/=p;
		}
	}
	int sz=0;
	for(int i=0;i<2*k;i++)
	{
		//if(i>0&&!check(i,0)) puts("-1");
		//printf("%d : %d\n",vec.size(),l+1);
		if(i==0||check(i,vec.size()-1))
		{
			vec.push_back(i);
			int sz=dv[i].size();
			for(int S=1;S<1<<sz;S++)
			{
				int mul=1;
				for(int j=0;j<sz;j++) if(S>>j&1) mul*=dv[i][j];
				int bef=0;
				if(dp[mul].size()>0) bef=dp[mul][dp[mul].size()-1].second;
				bef++;
				dp[mul].push_back(P(vec.size()-1,bef));
			}
			if(vec.size()>=k)
			{
				for(int j=0;j<k;j++) printf("%d ",vec[j]+1);
				puts("");
				return 0;
			}
		}
		else
		{
			int l=-1,r=vec.size();
			while(r-l>1)
			{
				int d=(l+r)/2;
				if(check(i,d)) l=d;
				else r=d;
			}
			ch[vec[l+1]].push_back(i);
			sz++;
			//if(sz>=k+3) break;
		}
	}
	int f=-1;
	for(int i=0;i<vec.size();i++)
	{
		if(ch[vec[i]].size()>=3)
		{
			f=i;
		}
	}
	vector <int> ret;
	ret.push_back(vec[f]);
	for(int i=1;i<ch[vec[f]].size();i++)
	{
		ret.push_back(ch[vec[f]][i]);
	}
	for(int i=0;i<vec.size();i++)
	{
		if(ret.size()+1==k)
		{
			ret.push_back(ch[vec[f]][0]);
			break;
		}
		if(i==f||ch[vec[i]].size()==0) continue;
		ret.push_back(vec[i]);
		for(int j=0;j<ch[vec[i]].size();j++)
		{
			if(ret.size()==k) break;
			ret.push_back(ch[vec[i]][j]);
		}
		if(ret.size()==k) break;
	}
	if(ret.size()+1==k) ret.push_back(ch[vec[f]][0]);
	for(int i=0;i<k;i++) printf("%d ",ret[i]+1);
	puts("");
	return 0;
}