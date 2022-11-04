#include<bits/stdc++.h>
using namespace std;
int n,m,tot,totp,T,blocks;
const int N=500005;
struct edge{
	int to,next;
}e[N*4];
int head[N],be[N];
int sta[N],vis[N];
int dfn[N],low[N],q[N];
vector<int> v[N];
void tarjan(int x){
	dfn[x]=low[x]=++T;
	sta[++(*sta)]=x; vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!dfn[e[i].to]){
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if (vis[e[i].to])
			low[x]=min(low[x],dfn[e[i].to]);
	if (dfn[x]==low[x]){
		blocks++;
		int y=19260817;
		for (;y!=x;){
			y=sta[(*sta)--];
			vis[y]=0; be[y]=blocks;
		}
	}
}
#define A(_) (((_)<<1)-1)
#define B(_) ((_)<<1)
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void work1(){
	for (int i=1;i<=q[0];i++){
		add(A(q[i]),A(i)+totp);
		add(B(i)+totp,B(q[i]));
		if (i==1) continue;
		add(A(i-1)+totp,A(i)+totp);
		add(B(i)+totp,B(i-1)+totp);
		add(A(i-1)+totp,B(q[i]));
		add(A(q[i]),B(i-1)+totp);
	}
	totp+=q[0]<<1; q[0]=0;
}
void work2(){
	for (int i=1;i<=q[0];i++){
		add(B(q[i]),B(i)+totp);
		add(A(i)+totp,A(q[i]));
		if (i==1) continue;
		add(B(i-1)+totp,B(i)+totp);
		add(A(i)+totp,A(i-1)+totp);
		add(B(i-1)+totp,A(q[i]));
		add(B(q[i]),A(i-1)+totp);
	}
	totp+=q[0]<<1; q[0]=0;
}
struct wzp{
	int a,b,c,d;
}p[N];
bool check(int mid){
	memset(head,0,sizeof(head));
	tot=T=blocks=0; totp=m*2;
	for (int i=1;i<=m;i++)
		if (p[i].d>mid) add(B(i),A(i));
	for (int i=1;i<=n;i++){
		for (int j=0;j<v[i].size();j++){
			if (*q&&p[v[i][j]].c!=p[q[*q]].c) work1();
			q[++(*q)]=v[i][j];
		}
		work1();
		for (int j=0;j<v[i].size();j++)
			q[++(*q)]=v[i][j];
		work2();
	}
	memset(dfn,0,sizeof(dfn));
	for (int i=1;i<=m*2;i++)
		if (!dfn[i]) tarjan(i);
	for (int i=1;i<=m;i++)
		if (be[A(i)]==be[B(i)]) return 0;
	return 1;
}
bool cmp(int x,int y){
	return p[x].c<p[y].c; 
}
int main(){
	scanf("%d%d",&n,&m);
	int l=0,r=0,flag=0;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&p[i].a,&p[i].b);
		scanf("%d%d",&p[i].c,&p[i].d);
		r=max(r,p[i].d+1);
		v[p[i].a].push_back(i);
		v[p[i].b].push_back(i);
	}
	for (int i=1;i<=n;i++)
		sort(v[i].begin(),v[i].end(),cmp);
	while (l<r){
		int mid=(l+r)/2;
		if (check(mid)) r=mid,flag=1;
		else l=mid+1;
	}
	if (!flag)
		return puts("No"),0;
	check(r); 
	int top=0;
	for (int i=1;i<=m;i++)
		if (be[A(i)]>be[B(i)]) q[++top]=i;
	printf("Yes\n%d %d\n",r,top);
	for (int i=1;i<=top;i++)
		printf("%d ",q[i]);
}