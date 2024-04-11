#include<cstdio>
#include<iostream>
using namespace std;
int n,m,t,a[300002],b[300002];
struct node{
	node *ls,*rs;
	int maxu,maxv,cnt,l,r;
}tr[4000002],*null,*top;
void init(){
	null=top=tr;
	null->ls=null->rs=null;
	null->cnt=null->maxu=null->maxv=-1;
}
node *add_node(int l,int r){
	node *p=++top;
	p->ls=p->rs=null;
	p->cnt=0;
	p->maxu=r;
	p->maxv=0;
	p->l=l;
	p->r=r;
	return p;
}
void build(node *p){
	if(p->l==p->r)return;
	build(p->ls=add_node(p->l,p->l+p->r>>1));
	build(p->rs=add_node(p->l+p->r+2>>1,p->r));
}
void add(int p,int v,node *t){
	if(t->l>p)return;
	if(t->r<=p){
		t->cnt+=v;
		return;
	}
	add(p,v,t->ls);
	add(p,v,t->rs);
	if(t->rs->maxv+t->rs->cnt>=t->ls->maxv+t->ls->cnt){
		t->maxv=t->rs->maxv+t->rs->cnt;
		t->maxu=t->rs->maxu;
	}
	else{
		t->maxv=t->ls->maxv+t->ls->cnt;
		t->maxu=t->ls->maxu;
	}
}
int find(node *t,int cnt){
	if(t->maxv+t->cnt+cnt<=0)return -1;
	if(t->l==t->r)return t->l;
	if(t->rs->maxv+t->rs->cnt+t->cnt+cnt>0)return find(t->rs,cnt+t->cnt);
	return find(t->ls,cnt+t->cnt);
}
int main(){
	int aa,ab,ac;
	scanf("%d%d",&n,&m);
	init();
	build(add_node(1,1000001));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(a[i],1,tr+1);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		add(b[i],-1,tr+1);
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&aa,&ab,&ac);
		if(aa==1){
			add(a[ab],-1,tr+1);
			add(a[ab]=ac,1,tr+1);
		}
		else{
			add(b[ab],1,tr+1);
			add(b[ab]=ac,-1,tr+1);
		}
		printf("%d\n",find(tr+1,0));
	}
}