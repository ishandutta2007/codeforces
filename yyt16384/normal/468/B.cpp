#include <cstdio>
#include <map>
#include <set>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
int n;
int a[MAXN];
int ans[MAXN];
int sa,sb;
std::set<int> all;
std::map<int,int> aa;
int que[MAXN];
int qb,qe;
void init()
{
	scanf("%d%d%d",&n,&sa,&sb);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
}
void solve()
{
	for (int i=0;i<n;++i) all.insert(a[i]);
	for (int i=0;i<n;++i) aa[a[i]]=i;
	for (int i=0;i<n;++i) ans[i]=0;
	for (int i=0;i<n;++i)
		if (aa.find(sa-a[i])==aa.end())
			que[qe++]=i;
	while (qb<qe)
	{
		int x=que[qb++];
		ans[x]=1;
		aa.erase(a[x]);
		if (aa.find(sa-a[x])!=aa.end()) que[qe++]=aa[sa-a[x]];
		if (aa.find(sb-a[x])!=aa.end()) que[qe++]=aa[sb-a[x]];
	}
	int ok=1;
	for (int i=0;i<n;++i)
		if ((ans[i]==0&&aa.find(sa-a[i])==aa.end())||(ans[i]==1&&(all.find(sb-a[i])==all.end()||aa.find(sb-a[i])!=aa.end())))
		{
			ok=0;break;
		}
	if (!ok) printf("NO\n");
	else
	{
		printf("YES\n");
		for (int i=0;i<n;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}