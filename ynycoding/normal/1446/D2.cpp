#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define pb push_back
#define N 200005
using std::vector;
int n, a[N], blc, cnt[N<<1], off=N, id[N], x;
vector<int> v[N], ta, tb;
inline int solve(vector<int> a, vector<int> b, int st, int ed)
{
	int l=0, r=0, cur=0, ret=0;
	std::fill(cnt+off-a.size(), cnt+off, n+1);
	std::fill(cnt+off, cnt+off+b.size()+1, st);
//	printf("st %d %d\n", st, ed);
	while(l<a.size()||r<b.size())
	{
		if(r<b.size()&&(l==a.size()||a[l]>b[r]))
		{
			++cur;
//			printf("b %d %d\n", b[r], cur);
			++r;
		}
		else
		{
			ret=std::max(ret, a[l]-cnt[cur+off]-1);
			--cur;
			(cnt[cur+off]>n?cnt[cur+off]=a[l]:0);
//			printf("a %d %d %d\n", a[l], cur, ret);
			++l;
		}
	}
	ret=std::max(ret, ed-cnt[cur+off]-1);
//	puts("");
	return ret;
}
inline int solve1(const vector<int> &x, vector<int> a)
{
	int ret=0;
	for(int i=0; i<a.size(); ++i)
	{
		ta.clear(), tb.clear();
		int l=id[a[i]]-1, r=i, tot=0;
		while(tot<=3*a.size()+1&&(l>=0||r>=0))
		{
			if(r>=0&&(l==-1||x[l]<a[r])) tb.pb(a[r]), --r;
			else ta.pb(x[l]), --l;
			++tot;
		}
		int st=(l==-1?0:x[l]);
		std::reverse(ta.begin(), ta.end());
		std::reverse(tb.begin(), tb.end());
		
		l=id[a[i]], r=i+1, tot=0;
		while(tot<=3*a.size()+1&&(l<x.size()||r<a.size()))
		{
			if(r<a.size()&&(l==x.size()||x[l]>a[r])) tb.pb(a[r]), ++r;
			else ta.pb(x[l]), ++l;
			++tot;
		}
		ret=std::max(ret, solve(ta, tb, st, (l==x.size()?n+1:x[l])));
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), v[a[i]].pb(i);
	for(int i=1; i<=n; ++i) ++cnt[a[i]];
	for(int i=1; i<=n; ++i) if(cnt[i]>cnt[x]) x=i;
//	printf("x %d\n", x);
	std::fill(cnt+1, cnt+n+1, 0);
	for(int i=1; i<=n; ++i)
		if(a[i]==x) id[i]=id[i-1]+1;
		else id[i]=id[i-1];
	
//	blc=0;
//	blc=n;
	blc=sqrt(n)/2;
	int ans=0;
	for(int i=1; i<=n; ++i) if(i!=x&&!v[i].empty())
	{
		if(v[i].size()>blc) ans=std::max(ans, solve(v[x], v[i], 0, n+1));
		else ans=std::max(ans, solve1(v[x], v[i]));
//		printf("fa %d %d\n", i, ans);
	}
	printf("%d\n", ans);
	return 0;
}