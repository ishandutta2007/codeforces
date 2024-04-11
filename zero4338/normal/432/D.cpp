#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
int n;
char s[maxn];
int nxt[maxn];
ll d[maxn];
vector<pair<int,ll>>ans;
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	nxt[1]=n;
	for(int i=2,l=0,r=0;i<=n;i++)
	{
		if(i<=r)nxt[i]=min(nxt[i-l+1],r-i+1);
		while(i+nxt[i]<=n&&s[i+nxt[i]]==s[nxt[i]+1])nxt[i]++;
		if(i+nxt[i]-1>r)l=i,r=i+nxt[i]-1;
	}
	for(int i=1;i<=n;i++)d[nxt[i]]++;
	for(int i=n;i>=1;i--)d[i]+=d[i+1];
	for(int i=n;i>=1;i--)
		if(i+nxt[i]==n+1)
			ans.push_back({nxt[i],d[nxt[i]]});
	printf("%lu\n",ans.size());
	for(auto &i:ans)printf("%d %lld\n",i.first,i.second);
	return 0;
}