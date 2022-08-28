#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define SIZE 100005
#define MM 62
#define MX 4

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

ll dp[MX][MX][MM],ans[2][MX];
char str[SIZE];
int rank[SIZE],sa[SIZE],lcp[SIZE];
int bef[SIZE],nt[SIZE];
bool up[MX];
PP pos[SIZE];
P memo[SIZE];

int main()
{
	ll n;
	scanf("%I64d",&n);
	scanf("%s",&str);
	int m=strlen(str);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<m;i++) rank[i]=str[i]-'A';
	for(int k=1;k<=m;k<<=1)
	{
		for(int i=0;i<m;i++)
		{
			pos[i]=PP(P(rank[i],i+k<m?rank[i+k]:-1),i);
		}
		sort(pos,pos+m);
		for(int i=0;i<m;)
		{
			int r=i;
			P p=pos[i].first;
			for(;i<m&&pos[i].first==p;i++) rank[pos[i].second]=r;
		}
	}
	for(int i=0;i<m;i++) sa[rank[i]]=i;
	int H=0,sz=0;
	for(int i=0;i<m;i++)
	{
		if(H>0) H--;
		if(rank[i]==m-1) continue;
		int to=sa[rank[i]+1];
		while(i+H<m&&to+H<m&&str[i+H]==str[to+H]) H++;
		lcp[i]=H;
		memo[sz++]=P(lcp[i],rank[i]);
	}
	sort(memo,memo+sz);
	memset(bef,0,sizeof(bef));
	set <int> st;
	set <int>::iterator it;
	st.insert(0);
	st.insert(m);
	for(int i=0;i<sz;)
	{
		int s=memo[i].first;
		for(;i<m&&memo[i].first==s;)
		{
			int p=memo[i].second;
			if(s==0)
			{
				st.insert(p+1);
				i++;
			}
			else
			{
				it=st.upper_bound(p);
				int to=(*it);it--;
				int v=(*it);
				int g=str[sa[v]]-'A';
				int lim=0;
				memset(up,false,sizeof(up));
				up[str[sa[v]+s]-'A']=true;
				for(;i<m&&memo[i].first==s&&memo[i].second<to;i++)
				{
					if(memo[i].second+1<to)
					{
						int pre=memo[i].second+1;
						up[str[sa[pre]+s]-'A']=true;
						bef[pre]=s;
						st.insert(pre);
					}
				}
				if(s-bef[v]>1)
				{
					int bg=str[sa[v]+bef[v]]-'A';
					for(int j=0;j<MX;j++)
					{
						if(j!=bg)
						{
							ll vl=bef[v]+1;
							if(dp[g][j][0]!=-1) vl=min(vl,dp[g][j][0]);
							dp[g][j][0]=vl;
						}
					}
				}
				bef[v]=s;
				for(int j=0;j<MX;j++)
				{
					if(!up[j])
					{
						ll vl=s;
						if(dp[g][j][0]!=-1) vl=min(vl,dp[g][j][0]);
						dp[g][j][0]=vl;
					}
				}
			}
		}
	}
	char c='$';
	int last=m;
	for(int i=m-1;i>=0;i--)
	{
		if(c!=str[i])
		{
			last=i;
			c=str[i];
		}
		nt[i]=last;
	}
	for(int i=0;i<m;i++)
	{
		int v=sa[i];
		int f=v+bef[i]+1;
		int g=str[v]-'A';
		if(f<m)
		{
			c='$';
			if(f+1<m) c=str[f+1];
			for(int j=0;j<MX;j++)
			{
				if('A'+j!=c)
				{
					ll vl=bef[i]+1;
					if(dp[g][j][0]!=-1) vl=min(vl,dp[g][j][0]);
					dp[g][j][0]=vl;
				}
			}
			if(f+1<m)
			{
				ll vl=nt[f+1]-v+1;
				if(dp[g][c-'A'][0]!=-1) vl=min(vl,dp[g][c-'A'][0]);
				dp[g][c-'A'][0]=vl;
			}
		}
	}
	for(int i=0;i<MM-1;i++)
	{
		for(int j=0;j<MX;j++)
		{
			for(int k=0;k<MX;k++)
			{
				for(int p=0;p<MX;p++)
				{
					if(dp[j][k][i]!=-1&&dp[k][p][i]!=-1&&dp[j][k][i]+dp[k][p][i]<=n)
					{
						ll vl=dp[j][k][i]+dp[k][p][i];
						if(dp[j][p][i+1]==-1) dp[j][p][i+1]=vl;
						else dp[j][p][i+1]=min(dp[j][p][i+1],vl);
					}
				}
			}
		}
	}
	int p=0;
	memset(ans,0,sizeof(ans));
	ll ret=0;
	for(int i=MM-1;i>=0;i--)
	{
		p^=1;
		memset(ans[p],-1,sizeof(ans[p]));
		bool ok=false;
		for(int j=0;j<MX;j++)
		{
			if(ans[p^1][j]==-1) continue;
			for(int k=0;k<MX;k++)
			{
				if(dp[j][k][i]==-1) continue;
				ll len=ans[p^1][j]+dp[j][k][i];
				if(len<=n)
				{
					ok=true;
					if(ans[p][k]==-1) ans[p][k]=len;
					else ans[p][k]=min(ans[p][k],len);
				}
			}
		}
		if(ok) ret|=1LL<<i;
		else
		{
			for(int j=0;j<MX;j++)
			{
				ans[p][j]=ans[p^1][j];
			}
		}
	}
	for(int j=0;j<MX;j++)
	{
		if(ans[p][j]!=-1&&ans[p][j]<n)
		{
			ret++;
			break;
		}
	}
	printf("%I64d\n",ret);
	return 0;
}