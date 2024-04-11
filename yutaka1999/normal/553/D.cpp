#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005

using namespace std;
typedef long long int ll;

struct Q
{
	ll a,b;// a/b , a,b>=0
	Q(ll a=0,ll b=0):a(a),b(b){}
	bool operator<(const Q&l) const
	{
		return a*l.b<b*l.a;
	}
};
vector <int> vec[SIZE];
Q can[2*SIZE];
int deg[SIZE],ob[SIZE];
bool out[SIZE],use[SIZE];
bool ans[SIZE];
int n,m,k;

int ok(Q q)// get/all >= q 
{
	queue <int> que;
	for(int i=0;i<n;i++)
	{
		ob[i]=((ll) deg[i]*q.a+q.b-1)/q.b;
		ob[i]=deg[i]-ob[i];
		ans[i]=!out[i];
		if(out[i]) que.push(i);
	}
	int all=n;
	while(!que.empty())
	{
		int v=que.front();que.pop();
		all--;
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			if(ans[to])
			{
				ob[to]--;
				if(ob[to]<0)
				{
					ans[to]=false;
					que.push(to);
				}
			}
		}
	}
	return all;
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);a--;
		out[a]=true;
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		deg[a]++;
		deg[b]++;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int sz=0;
	can[sz++]=Q(0,1);
	can[sz++]=Q(1,1);
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<deg[i];j++)
		{
			can[sz++]=Q(j,deg[i]);
		}
	}
	sort(can,can+sz);
	int l=0,r=sz;
	while(r-l>1)
	{
		int m=(l+r)/2;
		if(ok(can[m])>0) l=m;
		else r=m;
	}
	printf("%d\n",ok(can[l]));
	bool f=true;
	for(int i=0;i<n;i++)
	{
		if(ans[i])
		{
			if(!f) printf(" ");
			printf("%d",i+1);
			f=false;
		}
	}puts("");
	return 0;
}