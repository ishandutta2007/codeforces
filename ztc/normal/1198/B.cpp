#include<stdio.h>
inline int Min(int a,int b){return a<b?a:b;}
inline int Max(int a,int b){return a>b?a:b;}
int n,d[200002];
struct node{
	node *ls,*rs;
	int val,laz;
	void push(){
		if(laz==-1)return;
		if(ls==rs)val=Max(val,laz);
		else{
			ls->laz=Max(ls->laz,laz);
			rs->laz=Max(rs->laz,laz);
		}laz=-1;
	}
}tr[6000002],*null,*top,*rt;
node *addnode(){
	node *p=++top;
	p->ls=p->rs=null;
	p->val=0;p->laz=-1;
	return p;
}
void build(int l,int r,node *t){
	if(l==r)return void(t->val=d[l]);
	build(l,l+r>>1,t->ls=addnode());
	build(l+r+2>>1,r,t->rs=addnode());
}
void init(){
	null=top=tr;
	null->ls=null->rs=null;
	null->val=null->laz=-1;
	build(1,n,rt=addnode());
}
void opt1(int l,int r,node *t,int p,int x){
	if(l>p||r<p)return;t->push();
	if(l==r)return void(t->val=x);
	if(p<=l+r>>1)opt1(l,l+r>>1,t->ls,p,x);
	else opt1(l+r+2>>1,r,t->rs,p,x);
}
void opt1(int p,int x){opt1(1,n,rt,p,x);}
void opt2(int val){rt->push();rt->laz=val;}
void print(node *t){
	t->push();
	if(t->ls==t->rs)return void(printf("%d ",t->val));
	print(t->ls);print(t->rs);
}int m,A,B,C;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	scanf("%d",&m);init();
	while(m--){
		scanf("%d%d",&A,&B);
		if(A==1){
			scanf("%d",&C);
			opt1(B,C);
		}else opt2(B);
	}print(rt);
}