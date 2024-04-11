#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005
#define BT 20

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

vector <P> vec[SIZE];
char str[SIZE];
int rank[SIZE],sa[SIZE];
int lcp[SIZE],cnt[SIZE];
int tg[SIZE],start[SIZE];
int memo[SIZE];
int to[SIZE][BT];
int n;

void build()
{
	for(int i=0;i<n;i++) rank[i]=str[i]=='('?1:0;
	for(int k=1;k<=n;k<<=1)
	{
		for(int i=0;i<=n;i++) vec[i].clear();
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			int to=i+k<n?rank[i+k]:-1;
			vec[to+1].push_back(P(rank[i],i));
			cnt[rank[i]]++;
		}
		for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
		for(int i=0;i<n;i++) if(rank[i]>0) rank[i]=cnt[rank[i]-1];
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<vec[i].size();j++)
			{
				P p=vec[i][j];
				rank[p.second]+=cnt[p.first];
			}
			for(int j=0;j<vec[i].size();j++)
			{
				P p=vec[i][j];
				cnt[p.first]++;
			}
		}
	}
	for(int i=0;i<n;i++) sa[rank[i]]=i;
	int h=0;
	for(int i=0;i<n;i++)
	{
		if(h>0) h--;
		if(rank[i]==n-1) continue;
		int to=sa[rank[i]+1];
		while(i+h<n&&to+h<n&&str[i+h]==str[to+h]) h++;
		lcp[rank[i]]=h;
	}
}
void make()
{
	memset(tg,-1,sizeof(tg));
	int sz=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]==')'&&sz>0) tg[memo[--sz]]=i;
		else if(str[i]=='(') memo[sz++]=i;
	}
	for(int i=0;i<n;i++)//start : last >= start[i]
	{
		if(rank[i]==0) start[i]=i;
		else start[i]=i+lcp[rank[i]-1];
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%s",&str);
	build();
	//for(int i=0;i<n;i++) printf("%d ",rank[i]);puts("");
	make();
	//for(int i=0;i<n;i++) printf("[%d %d]\n",tg[i],start[i]);
	memset(to,-1,sizeof(to));
	for(int i=0;i<n;i++) if(tg[i]!=-1) to[i][0]=tg[i]+1;
	for(int i=0;i+1<BT;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(to[j][i]==-1) to[j][i+1]=-1;
			else to[j][i+1]=to[to[j][i]][i];
		}
	}
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]==')') continue;
		int now=i;
		int f=ret;
		for(int j=BT-1;j>=0;j--)
		{
			if(to[now][j]!=-1)
			{
				ret+=1LL<<j;
				now=to[now][j];
			}
		}
		now=i;
		for(int j=BT-1;j>=0;j--)
		{
			if(to[now][j]!=-1&&to[now][j]<=start[i])
			{
				ret-=1LL<<j;
				now=to[now][j];
			}
		}
		//printf("%d %d : %d\n",i,start[i],ret-f);
	}
	printf("%lld\n",ret);
	return 0;
}