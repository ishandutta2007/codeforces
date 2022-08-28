#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define SIZE 205

using namespace std;
typedef long long int ll;

char str[SIZE];
int A[SIZE];
string S[SIZE];
vector <string> nd;
ll cost[SIZE][SIZE];
ll dist[SIZE][SIZE];
ll cur[SIZE][SIZE];
int n,sz;

void merge(ll A[SIZE][SIZE],ll B[SIZE][SIZE])
{
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<sz;j++)
		{
			cur[i][j]=-1;
			for(int k=0;k<sz;k++)
			{
				if(A[i][k]==-1||B[k][j]==-1) continue;
				cur[i][j]=max(cur[i][j],A[i][k]+B[k][j]);
			}
		}
	}
}
void solve(ll K)
{
	if(K==0)
	{
		memset(dist,-1,sizeof(dist));
		for(int i=0;i<sz;i++) dist[i][i]=0;
		return;
	}
	solve(K/2);
	merge(dist,dist);
	for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) dist[i][j]=cur[i][j];
	if(K%2==1)
	{
		merge(dist,cost);
		for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) dist[i][j]=cur[i][j];
	}
}
int main()
{
	ll L;
	scanf("%d %lld",&n,&L);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	nd.push_back("");
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		S[i]=str;
		string now="";
		for(int j=0;j<S[i].size();j++)
		{
			now+=S[i][j];
			nd.push_back(now);
		}
	}
	sort(nd.begin(),nd.end());
	nd.erase(unique(nd.begin(),nd.end()),nd.end());
	sz=nd.size();
	memset(cost,-1,sizeof(cost));
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<26;j++)
		{
			string s=nd[i];
			char c='a'+j;
			s+=c;
			ll sum=0;
			for(int k=0;k<n;k++)
			{
				if(S[k].size()<=s.size()&&S[k]==s.substr(s.size()-S[k].size(),S[k].size())) sum+=A[k];
			}
			int pos=-1;
			for(int k=0;k<sz;k++)
			{
				if(nd[k].size()<=s.size()&&nd[k]==s.substr(s.size()-nd[k].size(),nd[k].size()))
				{
					if(pos==-1||nd[pos].size()<nd[k].size()) pos=k;
				}
			}
			cost[i][pos]=max(cost[i][pos],sum);
		}
	}/*
	for(int i=0;i<sz;i++) printf("%s\n",nd[i].c_str());
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<sz;j++) printf("%2lld ",cost[i][j]);
		puts("");
	}*/
	solve(L);
	ll ret=0;
	for(int i=0;i<sz;i++) ret=max(ret,dist[0][i]);
	printf("%lld\n",ret);
	return 0;
}