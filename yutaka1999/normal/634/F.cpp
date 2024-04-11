#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 3005
#define MX 30
#define MD 15

using namespace std;
typedef long long int ll;

vector <int> query[SIZE];
int nxt[SIZE],back[SIZE];
int pos[SIZE],lt[SIZE];
int id[MX];
int n,m,nm,k;
int sz;

ll getB(int x)
{
	ll ret=0;
	int now=x;
	int len=0;
	if(back[now]!=-1) len=lt[now]-lt[back[now]];
	for(int j=1;j<k;j++)
	{
		if(nxt[now]==sz) break;
		ret+=lt[nxt[now]]-lt[now];
		now=nxt[now];
	}
	return ret*len+len*(len-1)/2;
}
ll diff(int x)//erase x
{
	int now=x;
	for(int i=0;i<k;i++)
	{
		if(nxt[now]==sz) id[MD+i]=0;
		else
		{
			id[MD+i]=lt[nxt[now]]-lt[now];
			now=nxt[now];
		}
	}
	now=x;
	for(int i=1;i<=k;i++)
	{
		if(back[now]==-1) id[MD-i]=0;
		else
		{
			id[MD-i]=lt[now]-lt[back[now]];
			now=back[now];
		}
	}
	ll ret=0;
	for(int i=0;i<k;i++) ret+=id[MD+i]*id[MD+i-k];
	int f=back[x],s=nxt[x];
	if(f!=-1) nxt[f]=s;
	if(s!=sz) back[s]=f;
	return ret;
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&nm,&k);
	for(int i=0;i<nm;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		query[a].push_back(b);
	}
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		sz=0;
		lt[sz++]=-1;
		lt[sz++]=m;
		for(int j=i;j<n;j++)
		{
			for(int p=0;p<query[j].size();p++)
			{
				lt[sz++]=query[j][p];
			}
		}
		sort(lt,lt+sz);
		memset(pos,-1,sizeof(pos));
		for(int j=0;j<sz;j++) if(lt[j]!=-1&&lt[j]!=m&&pos[lt[j]]==-1) pos[lt[j]]=j;
		for(int j=0;j<sz;j++)
		{
			nxt[j]=j+1;
			back[j]=j-1;
		}
		ll sum=0;
		for(int j=0;j<sz;j++) sum+=getB(j);
		for(int j=n-1;j>=i;j--)
		{
			//printf("%d %d : %lld\n",i,j,sum);
			ret+=sum;
			for(int p=0;p<query[j].size();p++)
			{
				int x=query[j][p];
				sum+=diff(pos[x]);
				pos[x]++;
			}
		}
	}
	ll all=(ll) n*(ll) (n+1)/2*(ll) m*(ll) (m+1)/2;
	printf("%lld\n",all-ret);
	return 0;
}