#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE 100005
#define SQR 101
#define OT 1001

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

priority_queue <P> vec[OT];
ll sum[OT];
int in[SIZE];
int n;

void update(int k,int mod)
{
	while(!vec[k].empty()&&vec[k].top().first>=mod)
	{
		P p=vec[k].top();vec[k].pop();
		int v=p.second;
		sum[k]-=(ll) in[v];
		in[v]%=mod;
		sum[k]+=(ll) in[v];
		vec[k].push(P(in[v],v));
	}
}
void make(int k)
{
	while(!vec[k].empty()) vec[k].pop();
	sum[k]=0;
	for(int i=k*SQR;i<(k+1)*SQR;i++)
	{
		if(i>=n) break;
		vec[k].push(P(in[i],i));
		sum[k]+=(ll) in[i];
	}
}
void up(int a,int b,int mod)
{
	if(a%SQR!=0)
	{
		int va=a/SQR;
		while(a%SQR!=0&&a<=b)
		{
			in[a]%=mod;
			a++;
		}
		make(va);
		if(a>b) return;
	}
	if((b+1)%SQR!=0)
	{
		int vb=b/SQR;
		while((b+1)%SQR!=0&&a<=b)
		{
			in[b]%=mod;
			b--;
		}
		make(vb);
		if(a>b) return;
	}
	for(int i=a/SQR;i<(b+1)/SQR;i++) update(i,mod);
}
ll calc(int a,int b)
{
	ll ret=0;
	if(a%SQR!=0)
	{
		while(a%SQR!=0&&a<=b)
		{
			ret+=in[a];
			a++;
		}
		if(a>b) return ret;
	}
	if((b+1)%SQR!=0)
	{
		while((b+1)%SQR!=0&&a<=b)
		{
			ret+=in[b];
			b--;
		}
		if(a>b) return ret;
	}
	for(int i=a/SQR;i<(b+1)/SQR;i++) ret+=sum[i];
	return ret;
}
int main()
{
	int m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i=0;i<=n/SQR;i++) make(i);
	for(int i=0;i<m;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int l,r;
			scanf("%d %d",&l,&r);l--;r--;
			printf("%llld\n",calc(l,r));
		}
		else if(t==2)
		{
			int l,r,mod;
			scanf("%d %d %d",&l,&r,&mod);l--;r--;
			up(l,r,mod);
		}
		else
		{
			int k,x;
			scanf("%d %d",&k,&x);k--;
			in[k]=x;
			make(k/SQR);
		}
	}
	return 0;
}