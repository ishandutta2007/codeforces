#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#define SIZE 15005
#define MX 3000005

using namespace std;
typedef pair <int,int> P;

char str[MX];
P gt[SIZE],nxt[SIZE];
vector <int> vec[MX];
char ans[MX];
int left[SIZE],right[SIZE];
vector <int> ft,st;

void dfs(int v)
{
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		ans[to]=ans[v];
		dfs(to);
	}
}
int main()
{
	scanf("%s",&str);
	int k;
	scanf("%d",&k);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
		left[i]--,right[i]--;
	}
	int sz=0;
	gt[sz++]=P(0,k-1);
	for(int i=n-1;i>=0;i--)
	{
		int L=right[i]-left[i]+1;
		int s=right[i]+1,t=s+L-1;
		if(s>=k) continue;
		ft.clear();
		st.clear();
		int ns=0;
		for(int j=0;j<sz;j++)
		{
			P p=gt[j];
			int len=p.second-p.first+1;
			if(t<0||s>=len) nxt[ns++]=p;
			else
			{
				if(0<s) nxt[ns++]=P(p.first,p.first+s-1);
				if(t<len-1) nxt[ns++]=P(p.first+t+1,p.second);
				int l=p.first+max(0,s),r=min(p.second,p.first+t);
				while(l<=r) st.push_back(l++);
			}
			s-=len,t-=len;
		}
		s=left[i],t=right[i];
		t=min(t,left[i]+(int) st.size()*3);
		for(int j=0;j<sz;j++)
		{
			P p=gt[j];
			int len=p.second-p.first+1;
			if(s<len&&t>=0)
			{
				int l=p.first+max(0,s),r=min(p.second,p.first+t);
				while(l<=r) ft.push_back(l++);
			}
			s-=len,t-=len;
		}
		sz=ns;
		for(int j=0;j<sz;j++) gt[j]=nxt[j];
		for(int j=0;j<ft.size();j++)
		{
			if(j%2==0)
			{
				if(j/2+ft.size()/2<st.size())
				{
					vec[ft[j]].push_back(st[j/2+ft.size()/2]);
				}
			}
			else
			{
				if(j/2<st.size())
				{
					vec[ft[j]].push_back(st[j/2]);
				}
			}
		}
		//for(int j=0;j<sz;j++) printf("[%d %d] ",gt[j].first,gt[j].second);puts("");
	}
	int now=0;
	for(int i=0;i<sz;i++)
	{
		P p=gt[i];
		while(p.first<=p.second)
		{
			ans[p.first]=str[now++];
			dfs(p.first++);
		}
	}
	printf("%s\n",ans);
	return 0;
}