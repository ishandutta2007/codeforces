#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=50005;
int n,m,tp;
int fa[N],ch[N][2];;
ll ans;
struct node{
	int dsz,sz,tg,v;
	ll w,sum;
}p[N];
void pushup(int k){
	int l=ch[k][0],r=ch[k][1];
	p[k].sz=p[k].dsz+p[l].sz+p[r].sz;
	p[k].sum=1ll*p[k].dsz*p[k].v+p[l].sum+p[r].sum;
}
void change(int k,int y){
	p[k].tg+=y;
	p[k].w+=1ll*y*p[k].dsz;
}
void pushdown(int k){
	if (!p[k].tg) return;
	change(ch[k][0],p[k].tg);
	change(ch[k][1],p[k].tg);
	p[k].tg=0;
}
bool isrt(int x){
	return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
}
void rotate(int x){
	int y=fa[x],z=fa[y],l=(ch[y][1]==x),r=l^1;
	if (!isrt(y)) ch[z][ch[z][1]==y]=x;
	fa[x]=z; fa[y]=x; fa[ch[x][r]]=y;
	ch[y][l]=ch[x][r]; ch[x][r]=y;
	pushup(y);
}
void splay(int x){
	static int q[N],top=0;
	q[top=1]=x;
	for (int i=x;!isrt(i);q[++top]=i=fa[i]);
	for (;top;pushdown(q[top--]));
	for (;!isrt(x);rotate(x)){
		int y=fa[x],z=fa[y];
		if (!isrt(y)){
			if ((ch[z][0]==y)^(ch[y][0]==x))
				rotate(x);
			else rotate(y);
		}
	}
	pushup(x);
}
void access(int x){
	int y=0;
	for (;x;y=x,x=fa[x]){
		splay(x); p[x].dsz+=p[ch[x][1]].sz;
		ch[x][1]=y; p[x].dsz-=p[y].sz;
		pushup(x);
	}
}
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	node &o=p[x];
	o.w=o.dsz=1;
	for (int i=head[x];i;i=e[i].next){
		int y=e[i].to; dfs(e[i].to);
		o.w+=1ll*o.dsz*p[y].dsz*2;
		o.dsz+=p[y].dsz;
	}
	ans+=o.v*o.w;
	pushup(x);
}
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		add(fa[i],i);
	}
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i].v);
	dfs(1);
	printf("%.20lf\n",1.0*ans/n/n);
	int Q;
	scanf("%d",&Q);
	while (Q--){
		char s[5]; int x,y,z;
		scanf("%s%d%d",s,&x,&y);
		if (s[0]=='P'){
			access(y); splay(x);
			for (z=x;!isrt(z);z=ch[z][0]);
			if (fa[z]) access(x); 
			else swap(x,y);
			if (!ch[x][0]) z=fa[x];
			else for (z=ch[x][0];ch[z][1];z=ch[z][1]);
			if (z!=y){
				access(z); splay(z); splay(x);
				p[z].dsz-=p[x].dsz;
				change(z,-(p[x].sz*2));
				pushup(z); ans-=p[z].sum*p[x].sz*2;
				access(y); splay(y);
				ans+=p[y].sum*p[x].sz*2;
				change(y,p[x].sz*2);
				p[y].dsz+=p[x].sz;
				pushup(y); fa[x]=y;
			}
		}
		else{
			splay(x);
			ans+=(y-p[x].v)*p[x].w;
			p[x].v=y;
		}
		printf("%.20lf\n",1.0*ans/n/n);
	}
}