#include<bits/stdc++.h>
using namespace std;
const int N=30030;
int n,a[N<<2]={},b[N<<2]={},c[N<<2]={},del[N<<2]={};
int ans[N<<2]={},tot=0,t[N]={};
unordered_set<int> s[N];
void calc(int now)
{
	//assert(!s[now].empty());
	auto d=*s[now].begin();
	s[b[d]].erase(d);
	s[c[d]].erase(d);
	del[d]=true;
	ans[++tot]=d;
	--t[b[d]],--t[c[d]],++t[a[d]];
	if(t[a[d]]==9)
		calc(a[d]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*4;++i)
		scanf("%d%d%d",a+i,b+i,c+i);
	for(int i=1;i<=n*4;++i)
	{
		s[b[i]].insert(i);
		s[c[i]].insert(i);
	}
	fill(t+1,t+n+1,8);
	for(int i=1;i<=n*4;++i)
	{
		if(del[i])
			continue;
		--t[b[i]],--t[c[i]],++t[a[i]];
		del[i]=true;
		s[b[i]].erase(i);
		s[c[i]].erase(i);
		ans[++tot]=i;
		if(t[a[i]]==9)
			calc(a[i]);
	}
	puts("YES");
	for(int i=tot;i>=1;--i)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}