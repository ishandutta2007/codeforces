#include<stdio.h>
int a[1000002],b[1000002],n,pos[1000002];
inline int Max(int p,int q){return p>q?p:q;}
struct node{
	node *ls,*rs;
	int cnt,maxx;
}tr[10000002],*null=tr,*top=tr-1,*rt;
node *addnode(){
	node *p=++top;
	p->ls=p->rs=null;
	p->cnt=p->maxx=0;return p;
}
void build(int l,int r,node *p){
	if(l!=r)build(l,l+r>>1,p->ls=addnode()),build(l+r+2>>1,r,p->rs=addnode());
}
void add(int p,int l,int r,node *t,int v){
	if(r<=p){t->cnt+=v;return;}
	add(p,l,l+r>>1,t->ls,v);
	if(l+r>>1<p)add(p,l+r+2>>1,r,t->rs,v);
	t->maxx=Max(t->ls->maxx+t->ls->cnt,t->rs->maxx+t->rs->cnt);
}
int main(){
	scanf("%d",&n);addnode();build(1,n,rt=addnode());
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1,j=n;i<=n;i++){
		while(rt->maxx+rt->cnt<=0)add(pos[j],1,n,rt,1),j--;
		printf("%d ",j+1);add(b[i],1,n,rt,-1);
	}
}