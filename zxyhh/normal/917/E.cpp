#include <bits/stdc++.h>
#define N 200001
using namespace std;
int n,m,Q,E,cnt,cntpoi,tree[N],ret[N];
int to[N],nex[N],fir[N],w[N],pa[N];
int st[N],ed[N],size[N],co[N],dep[N];
int acori[N],acrev[N];
vector<int> vec[N];
bool vis[N];
int posori[N],posrev[N];
struct point
{
	int x,y,t;
	point(int p,int q,int o){x=p;y=q;t=o;}
	point(){}
} po[5*N];
struct query
{
	int x,y,z,wei,id;
} que[N];
bool operator<(query a,query b)
{
	return a.wei<b.wei; 
}
bool comz(query a,query b)
{
	return a.z<b.z;
}
struct mzc
{
	int NODE,SAMNODE,TIME,acTIME;
	int c[N][26],lis[N],tr[N][26],fir[N],nex[N];
	int mx[N],poi[N],lp[N],rp[N],str[N],from[N];
	int fail[N],fa[N],ch[N][26],aclp[N],acrp[N];
	int insert(int l,int r,int* a,bool rev) 
	{
		int now=0;
		if(!rev)
		for(int i=l;i<=r;i++)
		{
			now=c[now][pa[i]]?c[now][pa[i]]:(c[now][pa[i]]=++NODE);
			a[i]=now;str[now]=i;
		}
		else
		for(int i=r;i>=l;i--)
		{
			now=c[now][pa[i]]?c[now][pa[i]]:(c[now][pa[i]]=++NODE);
			a[i]=now;str[now]=i;
		}
		return now;
	}
	int extend(int p,int c,int pos)
	{
		int np=++SAMNODE,q,nq;
		mx[np]=mx[p]+1;from[np]=pos;
		for(;p && !tr[p][c];p=fa[p]) tr[p][c]=np;
		if(!p)
			fa[np]=1;
		else
		if(mx[q=tr[p][c]]==mx[p]+1)
			fa[np]=q;
		else
		{
			mx[nq=++SAMNODE]=mx[p]+1;from[nq]=pos;
			memcpy(tr[nq],tr[q],sizeof tr[q]);
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			for(;p && tr[p][c]==q;p=fa[p])
				tr[p][c]=nq;
		}
		return np;
	}
	void dfs(int now)
	{
		lp[now]=++TIME;
		for(int i=0;i<26;i++)
		if(ch[now][i])
			dfs(ch[now][i]);
		rp[now]=TIME;
	}
	void acdfs(int now)
	{
		aclp[now]=++acTIME;
		for(int i=fir[now];i;i=nex[i])
			acdfs(i);
		acrp[now]=acTIME;
	}
	void build(bool rev)
	{
		for(int h=1,t=1;h<=t;h++)
			for(int i=0;i<26;i++)
			if(c[lis[h]][i])
			{
				int tem=fail[lis[h]];
				while(tem && !c[tem][i]) tem=fail[tem];
				fail[lis[++t]=c[lis[h]][i]]=c[tem][i];
				if(fail[lis[t]]==lis[t]) fail[lis[t]]=0;
				poi[lis[t]]=extend(poi[lis[h]],i,str[lis[t]]);
			}
		for(int i=2;i<=SAMNODE;i++)
			ch[fa[i]][pa[rev?from[i]+mx[fa[i]]:(from[i]-mx[fa[i]])]]=i;
		for(int i=1;i<=NODE;i++)
			nex[i]=fir[fail[i]],fir[fail[i]]=i;
		dfs(1);acdfs(0);
	}
	mzc()
	{
		memset(c,0,sizeof c);
		memset(lis,0,sizeof lis);
		memset(fail,0,sizeof fail);
		memset(tr,0,sizeof tr);
		memset(fa,0,sizeof fa);
		memset(ch,0,sizeof ch);
		memset(fir,0,sizeof fir);
		NODE=0;SAMNODE=1;acTIME=0;poi[0]=1;TIME=0; 
	}
} ori,rev;
struct state
{
	int p1,p2,le1,le2,p3,p4;
	bool d1,d2;
	state(){ p1=p2=1;le1=le2=d1=d2=p3=p4=0;}
} sta[N][20];
state trans(state x,int y)
{
	if(!x.d1)
		if(x.le1==ori.mx[x.p1])
			if(ori.ch[x.p1][y]) x.p1=ori.ch[x.p1][y],x.le1++;
			else x.d1=1;
		else
			if(pa[ori.from[x.p1]-x.le1]==y) x.le1++;
			else x.d1=1;
	if(!x.d2)
		if(x.le2==rev.mx[x.p2])
			if(rev.ch[x.p2][y]) x.p2=rev.ch[x.p2][y],x.le2++;
			else x.d2=1;
		else
			if(pa[rev.from[x.p2]+x.le2]==y) x.le2++;
			else x.d2=1;
	//ac
	while(x.p3 && !ori.c[x.p3][y])
		x.p3=ori.fail[x.p3];
	if(ori.c[x.p3][y]) x.p3=ori.c[x.p3][y];
	while(x.p4 && !rev.c[x.p4][y])
		x.p4=rev.fail[x.p4];
	if(rev.c[x.p4][y]) x.p4=rev.c[x.p4][y];
	return x;
}
void add(int p,int q,int o)
{
	to[++E]=q;nex[E]=fir[p];fir[p]=E;w[E]=o;
}
int getsize(int now,int fat)
{
	size[now]=1;
	for(int i=fir[now];i;i=nex[i])
	if(to[i]!=fat && !vis[to[i]])
		size[now]+=getsize(to[i],now);
	return size[now];
}
void paint(int now,int fat,int color,int alpha,int depth)
{
	co[now]=color;
	sta[now][depth]=trans(sta[fat][depth],alpha);
	for(int i=fir[now];i;i=nex[i])
	if(!vis[to[i]] && to[i]!=fat)
		paint(to[i],now,color,w[i],depth);
}
int oritr[N],revtr[N];
void acaddori(int x,int y)
{
	while(x<N)
	{
		oritr[x]+=y;
		x+=x&-x;
	}
}
void acaddrev(int x,int y)
{
	while(x<N)
	{
		revtr[x]+=y;
		x+=x&-x;
	}
}
int acqueori(int x,int y)
{
	int ret=0;
	x--;
	while(x)
	{
		ret-=oritr[x];
		x-=x&-x;
	}
	while(y)
	{
		ret+=oritr[y];
		y-=y&-y;
	}
	return ret;
}
int acquerev(int x,int y)
{
	int ret=0;
	x--;
	while(x)
	{
		ret-=revtr[x];
		x-=x&-x;
	}
	while(y)
	{
		ret+=revtr[y];
		y-=y&-y;
	}
	return ret;
}
void acdfs(int now,int fat,int depth)
{
	acaddori(ori.aclp[sta[now][depth].p3],1);
	acaddrev(rev.aclp[sta[now][depth].p4],1);
	for(int i=0;i<vec[now].size();i++)
	if(vec[now][i]>0)
		ret[que[vec[now][i]].id]+=acquerev(rev.aclp[acrev[que[vec[now][i]].z]],rev.acrp[acrev[que[vec[now][i]].z]]);
	else
		ret[que[-vec[now][i]].id]+=acqueori(ori.aclp[acori[que[-vec[now][i]].z]],ori.acrp[acori[que[-vec[now][i]].z]]);
	vec[now].clear();
	for(int i=fir[now];i;i=nex[i])
	if(!vis[to[i]] && to[i]!=fat)
		acdfs(to[i],now,depth);
	acaddori(ori.aclp[sta[now][depth].p3],-1);
	acaddrev(rev.aclp[sta[now][depth].p4],-1);
}
void solve(int now,int l,int r,int depth)
{
	int allsize=getsize(now,0)/2,fat=0;
	for(bool flag=1;flag;)
	{
		flag=0;
		for(int i=fir[now];i;i=nex[i])
		if(to[i]!=fat && !vis[to[i]] && size[to[i]]>allsize)
		{
			fat=now;now=to[i];flag=1;
			break;
		}
	}
	vis[now]=1;co[now]=0;dep[now]=depth;
	int color=0;
	for(int i=fir[now];i;i=nex[i])
	if(!vis[to[i]])
		paint(to[i],now,++color,w[i],depth);
	for(int i=l;i<=r;i++)
		que[i].wei=co[que[i].x]==co[que[i].y]?co[que[i].x]:0;
	sort(que+l,que+r+1);
	int j=l;
	for(;j<=r && que[j].wei==0;j++)
	{
		que[j].wei=now;
		vec[que[j].x].push_back(j);
		vec[que[j].y].push_back(-j);
	}
	for(int i=fir[now];i;i=nex[i])
	if(!vis[to[i]])
		acdfs(to[i],now,depth);
	if(j>r) return;
	for(int i=fir[now];i;i=nex[i])
	if(!vis[to[i]] && que[j].wei==co[to[i]])
	{
		int st=j;
		while(j<=r && que[j].wei==que[st].wei) j++;
		solve(to[i],st,j-1,depth+1);
		if(j>r) return;
	}
}
void Plus(int l1,int r1,int l2,int r2)
{
	po[++cntpoi]=point(l1,l2,1);
	po[++cntpoi]=point(l1,r2+1,-1);
	po[++cntpoi]=point(r1+1,l2,-1);
	po[++cntpoi]=point(r1+1,r2+1,1);
//	printf("+%d %d %d %d\n",l1,r1,l2,r2);
}
bool operator<(point a,point b)
{
	return a.x==b.x?a.y==b.y?a.t<b.t:a.y<b.y:a.x<b.x;
}
void add(int x,int y)
{
	while(x<N)
	{
		tree[x]+=y;
		x+=x&-x;
	}
}
int sum(int x)
{
	int ret=0;
	while(x)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<n;i++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		char ch=getchar();
		for(;!isalpha(ch);ch=getchar());
		ch-='a';add(p,q,ch);add(q,p,ch);
	}
	for(int i=1;i<=m;i++)
	{
		char ch=getchar();
		for(;!isalpha(ch);ch=getchar());
		st[i]=cnt+1;
		for(;isalpha(ch);ch=getchar())
			pa[++cnt]=ch-'a';
		acori[i]=ori.insert(st[i],ed[i]=cnt,posori,0);
		acrev[i]=rev.insert(st[i],ed[i],posrev,1);
	}
	ori.build(0);rev.build(1);
	for(int i=1;i<=cnt;i++)
	{
		posori[i]=ori.poi[posori[i]];
		posrev[i]=rev.poi[posrev[i]];
	} 
	for(int i=1;i<=Q;i++)
		scanf("%d%d%d",&que[i].x,&que[i].y,&que[i].z),que[i].id=i;
	solve(1,1,Q,0);
	sort(que+1,que+Q+1,comz);
	for(int i=1,j=1;i<=m && j<=Q;i++)
	if(que[j].z==i)
	{
		cntpoi=0;
//		printf("%d:\n",i);
		for(int k=st[i];k<ed[i];k++)
			Plus(ori.lp[posori[k]],ori.rp[posori[k]],rev.lp[posrev[k+1]],rev.rp[posrev[k+1]]);
		for(;j<=Q && que[j].z==i;j++)
		{
			state x=sta[que[j].x][dep[que[j].wei]],y=sta[que[j].y][dep[que[j].wei]];
			if(x.le1<ori.mx[x.p1])
				x.p1=ori.fa[x.p1];
			if(y.le2<rev.mx[y.p2])
				y.p2=rev.fa[y.p2];
			po[++cntpoi]=point(ori.lp[x.p1],rev.lp[y.p2],j+1);
//			printf("Q%d %d\n",ori.lp[x.p1],rev.lp[y.p2]);
		}
		sort(po+1,po+cntpoi+1);
		for(int i=1;i<=cntpoi;i++)
		if(po[i].t<2) add(po[i].y,po[i].t);
		else ret[que[po[i].t-1].id]+=sum(po[i].y);
		for(int i=1;i<=cntpoi;i++)
		if(po[i].t<2) add(po[i].y,-po[i].t);
	}
	for(int i=1;i<=Q;i++)
		printf("%d\n",ret[i]);
	return 0;
}