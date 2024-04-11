#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
#define SIZE 100005

using namespace std;
typedef long long int ll;

struct Q
{
	ll a,b;//a/b
	Q(ll a=0,ll b=0):a(a),b(b){}
	bool operator<(const Q&l) const
	{
		return a*l.b<b*l.a;
	}
	bool operator>(const Q&l) const
	{
		return a*l.b>b*l.a;
	}
};
typedef pair <Q,int> P;
typedef pair <int,int> PP;
vector <PP> add[SIZE];
int T[SIZE],I[SIZE],B[SIZE];
ll A[SIZE],mx[SIZE];
int id[SIZE];
int pos[SIZE];
bool use[SIZE];

int main()
{
	int k,n,m;
	scanf("%d %d %d",&k,&n,&m);
	for(int i=0;i<k;i++)
	{
		scanf("%I64d",&A[i]);
		mx[i]=A[i];
		id[i]=-1;
	}
	priority_queue <P> que;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&T[i],&I[i],&B[i]);
		T[i]--;I[i]--;
		if(T[i]==0)
		{
			int v=I[i];
			if(mx[v]<B[i])
			{
				mx[v]=B[i];
				id[v]=i;
			}
		}
		else if(T[i]==1)
		{
			add[I[i]].push_back(PP(B[i],i));
		}
		else que.push(P(Q(B[i],1),i));
	}
	for(int i=0;i<k;i++)
	{
		if(id[i]!=-1) add[i].push_back(PP(mx[i]-A[i],id[i]));
		sort(add[i].begin(),add[i].end(),greater <PP>());
		pos[i]=0;
		if(!add[i].empty())
		{
			PP q=add[i][pos[i]++];
			int nxt=q.second;
			que.push(P(Q(A[i]+q.first,A[i]),nxt));
		}
	}
	for(int i=0;i<m;i++)
	{
		if(que.empty()) break;
		P p=que.top();que.pop();
		int d=p.second;
		use[d]=true;
		if(T[d]!=2)
		{
			int v=I[d];
			A[v]+=B[d];
			if(pos[v]<add[v].size())
			{
				PP q=add[v][pos[v]++];
				int nxt=q.second;
				que.push(P(Q(A[v]+q.first,A[v]),nxt));
			}
		}
	}
	vector <int> ans;
	for(int t=0;t<3;t++)
	{
		for(int i=0;i<n;i++)
		{
			if(use[i]&&T[i]==t)
			{
				ans.push_back(i);
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}