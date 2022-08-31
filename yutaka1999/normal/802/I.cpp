#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

char str[SIZE];
int rnk[SIZE],sa[SIZE],lcp[SIZE];
PP tmp[SIZE];
P st[SIZE];

void solve()
{
	scanf("%s",&str);
	int n=strlen(str);
	for(int i=0;i<n;i++) rnk[i]=str[i]-'a';
	for(int k=1;k<=n;k<<=1)
	{
		for(int i=0;i<n;i++)
		{
			tmp[i]=PP(P(rnk[i],i+k<n?rnk[i+k]:-1),i);
		}
		sort(tmp,tmp+n);
		for(int i=0;i<n;)
		{
			int f=i;
			for(;i<n&&tmp[i].first==tmp[f].first;i++) rnk[tmp[i].second]=f;
		}
	}
	for(int i=0;i<n;i++) sa[rnk[i]]=i;
	int H=0;
	for(int i=0;i<n;i++)
	{
		if(H>0) H--;
		if(rnk[i]==n-1) continue;
		int to=sa[rnk[i]+1];
		while(i+H<n&&to+H<n&&str[i+H]==str[to+H]) H++;
		lcp[rnk[i]]=H;
	}
	int sz=0;
	st[sz++]=P(n-sa[0],0);
	ll ret=0;
	for(int i=1;i<n;i++)
	{
		int back=lcp[i-1];
		int last=i-1;
		while(sz>0&&st[sz-1].first>=back)
		{
			int nxt=sz==1?0:st[sz-2].first;
			nxt=max(nxt,back);
			ret+=(ll) (st[sz-1].first-nxt)*(ll) (i-st[sz-1].second)*(ll) (i-st[sz-1].second);
			last=st[sz-1].second;
			sz--;
		}
		st[sz++]=P(back,last);
		if(back<n-sa[i]) st[sz++]=P(n-sa[i],i);
	}
	while(sz>0)
	{
		int nxt=sz==1?0:st[sz-2].first;
		ret+=(ll) (st[sz-1].first-nxt)*(ll) (n-st[sz-1].second)*(ll) (n-st[sz-1].second);
		sz--;
	}
	printf("%lld\n",ret);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}