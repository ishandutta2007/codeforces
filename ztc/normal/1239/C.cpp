#include<stdio.h>
#include<bits/stdc++.h>
int n,m,a[100002];
long long ans[100002],pre=0;
inline long long Min(long long a,long long b){return a<b?a:b;}
inline long long Max(long long a,long long b){return a>b?a:b;}
struct node{
	node *ls,*rs;
	long long val,laz;
}tr[300002],*null=tr,*top=tr,*rt;
void init(){
	null->ls=null->rs=null;
	null->val=null->laz=1e18;
}
node *addnode(){
	node *p=++top;
	p->ls=p->rs=null;
	p->val=p->laz=0;
	return p;
}
void build(int l,int r,node *t){
	if(l==r)return void(t->val=a[l]);
	build(l,l+r>>1,t->ls=addnode());
	build(l+r+2>>1,r,t->rs=addnode());
	t->val=Min(t->ls->val,t->rs->val);
}
void add(int p,int l,int r,node *t){
	if(l==r)return void(t->val=1e18);
	p<=l+r>>1?add(p,l,l+r>>1,t->ls):add(p,l+r+2>>1,r,t->rs);
	t->val=Min(Max(t->ls->val,t->ls->laz),Max(t->rs->val,t->rs->laz));
}
void add(int p,int l,int r,node *t,long long v){
	if(l>=p)return void(t->laz=v);
	if(p<=r)add(p,l+r+2>>1,r,t->rs,v);
	if(p<=l+r>>1)add(p,l,l+r>>1,t->ls,v);
	t->val=Min(Max(t->ls->val,t->ls->laz),Max(t->rs->val,t->rs->laz));
}
std::pair<int,long long>get(int l,int r,node *t,long long laz){
	laz=Max(laz,t->laz);if(l==r)return std::make_pair(l,Max(t->val,laz));
	return Max(t->ls->val,Max(t->ls->laz,laz))<=Max(t->rs->val,Max(t->rs->laz,laz))?get(l,l+r>>1,t->ls,laz):get(l+r+2>>1,r,t->rs,laz);
}
int main(){
	scanf("%d%d",&n,&m);init();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,rt=addnode());
	for(int i=1;i<=n;i++){
		std::pair<int,int>a=get(1,n,rt,0);
		pre=ans[a.first]=Max(pre,a.second)+m;
		add(a.first,1,n,rt);
		add(a.first+1,1,n,rt,ans[a.first]);
	}for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
}