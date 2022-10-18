#include <cstdio>
#include <numeric>
#include <functional>
#include <algorithm>
#define ll long long
const int N=6005;
int n, val[N][3], col[N], id[N], cur=1, ct;
ll cnt;
int stk[N<<1], cv[N<<1], top;
int rs[N];
inline int gnx(int x) { return x==n?1:x+1; }
inline int gpr(int x) { return x>1?x-1:n; }
inline int dis(int x, int y) { return x<=y?y-x:y-x+n; }
inline int dis1(int x, int y) { return x<=y?rs[y]-rs[x]:rs[y]-rs[x]+rs[n]; }
inline void fight(void)
{
	int a=id[cur], b=id[gnx(cur)];
	++cnt;
	if(val[a][ct]<val[b][0]) ct=1, cur=gnx(cur);
	else
	{
		std::swap(id[cur], id[gnx(cur)]);
		cur=gnx(cur);
		++ct;
		if(ct==3) printf("%d %lld\n", a-1, cnt), exit(0);
	}
}
inline bool color(void)
{
	for(int i=1; i<=n; ++i)
	{
		col[id[i]]=(val[id[i]][0]<val[id[gpr(i)]][1]?2:0);
	}
	for(int i=1; i<=n; ++i) if(!col[id[i]])
	{
		int v=col[id[gnx(i)]]==2?id[gnx(gnx(i))]:id[gnx(i)];
		col[id[i]]=val[id[i]][2]>val[v][0];
	}
	int ok=0;
	for(int i=1; i<=n; ++i) ok|=col[i]==2;
	return ok;
}
inline int find(void)
{
	std::rotate(id+1, id+cur, id+n+1);
	cur=1;
	top=0;
	for(int i=1; i<=n; ++i) if(col[id[i]]!=2)
	{
		int u=id[i];
		while(top&&cv[top]>=val[u][1]) --top;
		cv[++top]=val[u][1];
		stk[top]=i;
	}
	int ret=n+2;
	for(int i=1; i<=n; ++i) rs[i]=rs[i-1]+(col[id[i]]==2);
	for(int i=1; i<=n; ++i)
	{
		int u=id[i];
		if(col[u]!=2)
		{
			while(top&&cv[top]>=val[u][1]) --top;
			cv[++top]=val[u][1];
			stk[top]=i;
		}
		else
		{
			int p=std::lower_bound(cv+1, cv+top+1, val[u][0])-cv-1;
			if(p) ret=std::min(ret, dis(stk[p], i)-dis1(stk[p], i)-1);
		}
	}
	for(int i=1, ri, pr=0; i<=2*n; ++i)
	{
		int u=id[ri=(i>n?i-n:i)];
		if(col[u]==2&&pr) ret=std::min(ret, dis(pr, ri)-dis1(pr, ri)-1);
		if(col[u]==1) pr=i>n?i-n:i;
	}
	ret=std::max(ret, 0);
	return ret;
}
int id1[N];
void advance(int x)
{
	cnt+=x*(n-1);
	std::rotate(id+1, id+cur, id+n+1);
	cur=1;
	int t=x;
	while(t) t-=col[id[cur]]!=2, cur=gpr(cur);
	if(col[id[cur]]==2) cur=gpr(cur);
	for(int i=1; i<=n; ++i) if(col[id[i]]!=2)
	{
		id1[i]=id[cur];
		cur=gnx(cur);
		if(col[id[cur]]==2) cur=gnx(cur);
	}
	else id1[i]=id[i];
	std::copy(id1+1, id1+n+1, id+1);
	if(x) ct=1+(col[id[n]]==2);
	cur=1;
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d%d", val[i], val[i]+1, val[i]+2), id[i]=i;
	int T=2*n;
	while(T--) fight();
	if(ct==2) fight();
	while(1)
	{
		color();
		int x=find();
		if(x>n) return puts("-1 -1"), 0;
		advance(x);
		T=n;
		while(T--) fight();
		if(ct==2) fight();
	}
	return 0;
}