#include <cstdio>
#include <cmath>
#include <algorithm>
const int N=100005, B=805;
int n, p[N], bel[N], rk[N], id[B][B], tp, stk[B][B], top[B], len[B], q, blc=800;
int sum[N], lim, ln;
bool ok[B][N];
inline void add(int p, int v) { while(p<=ln) sum[p]+=v, p+=p&(-p); }
inline int ask(int v)
{
	int p=0;
	for(int i=lim; ~i; --i)
	{
		if((p|(1<<i))<=ln&&sum[p|(1<<i)]<v) p|=1<<i, v-=sum[p];
	}
	return p+1;
}
void build(int x)
{
	int l=(x-1)*blc+1, r=std::min(n, x*blc), len=r-l+1;
	int *stk=::stk[x], &top=::top[x];
	top=r-l+1;
	ln=r;
	for(int i=r; i>=l; --i)
	{
		rk[i]=ask(p[i]);
		add(rk[i], -1);
	}
	for(int i=l; i<=r; ++i) add(rk[i], 1);
	for(int i=1; i<=len; ++i) id[x][i]=i+l-1;
	std::sort(id[x]+1, id[x]+len+1, [] (int x, int y) { return rk[x]<rk[y]; });
	for(int i=1; i<=len; ++i) stk[i]=rk[id[x][i]]-i;
}
int idl[N], idr[N], tpl, tpr;
void change(int x, int y, int v)
{
	int l=(x-1)*blc+1, r=std::min(n, x*blc), len=r-l+1, *id=::id[x];
	tpl=tpr=tp=0;
	p[y]=v;
	for(int i=y+1; i<=r; ++i) if(p[i]<=v) ++v;
	if(v>rk[y])
	{
		for(int i=1, lst=0, pr=-2; i<=len; ++i)
		{
			int u=id[i];
			if(u==y) continue;
			int tt=rk[u];
			if(pr!=rk[u]-1) lst=0;
			if(u>y) idr[++tpr]=u, lst=(pr==rk[u]-1?lst+1:1);
			else
			{
				if(rk[y]<rk[u]&&v>=rk[u]) rk[u]-=lst+1, idl[++tpl]=u;
				else idr[++tpr]=u;
				lst=0;
			}
			pr=tt;
		}
	}
	else
	{
		for(int i=len, lst=0, pr=-2; i; --i)
		{
			int u=id[i];
			if(u==y) continue;
			int tt=rk[u];
			if(pr!=rk[u]+1) lst=0;
			if(u>y) idr[++tpr]=u, lst=(pr==rk[u]+1?lst+1:1);
			else
			{
				if(rk[y]>rk[u]&&v<=rk[u]) rk[u]+=lst+1, idl[++tpl]=u;
				else idr[++tpr]=u;
				lst=0;
			}
			pr=tt;
		}
		std::reverse(idl+1, idl+tpl+1);
		std::reverse(idr+1, idr+tpr+1);
	}
	int cl=1, cr=1;
	while(cl<=tpl||cr<=tpr)
	{
		if(cl<=tpl&&(cr>tpr||rk[idl[cl]]<rk[idr[cr]]))
		{
			id[++tp]=idl[cl];
			++cl;
		}
		else id[++tp]=idr[cr], ++cr;
	}
	int t=1;
	rk[y]=v;
	while(t<=tp&&rk[id[t]]<v) ++t;
	for(int i=tp+1; i>t; --i) id[i]=id[i-1];
	id[t]=y;
	for(int i=1; i<=len; ++i) stk[x][i]=rk[id[i]]-i;
}
inline int query(int x)
{
	int v=p[x];
	for(int i=x+1; bel[i]==bel[x]; ++i) v+=v>=p[i];
	for(int i=bel[x]+1; i<=bel[n]; ++i)
	{
		v+=std::lower_bound(stk[i]+1, stk[i]+top[i]+1, v)-stk[i]-1;
	}
	return v;
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", p+i), p[i]=i-p[i];
	for(int i=1; i<=n; ++i) bel[i]=(i+blc-1)/blc;
	while((1<<lim)<n) ++lim;
	ln=n;
	for(int i=1; i<=n; ++i) add(i, 1);
	for(int i=1; i<=bel[n]; ++i) build(i);
	scanf("%d", &q);
	for(int i=1, op, x, y; i<=q; ++i)
	{
		scanf("%d%d", &op, &x);
		if(op==1) scanf("%d", &y), y=x-y, change(bel[x], x, y);
		else printf("%d\n", query(x));
	}
	return 0;
}