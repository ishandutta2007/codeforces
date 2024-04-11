#include<stdio.h>
#include<algorithm>
struct node{
	node *ls,*rs;
	int cnt;
}tr[2000002],*null=tr,*top=tr,*rt;
void init(){
	null->ls=null->rs=null;
	null->cnt=0;
}
node *addnode(){
	node *p=++top;
	p->ls=p->rs=null;
	p->cnt=0;
	return p;
}
void build(int l,int r,node *p){
	if(l!=r)build(l,l+r>>1,p->ls=addnode()),build(l+r+2>>1,r,p->rs=addnode());
}
void add(int p,int l,int r,node *t){
	t->cnt+=1;
	if(l==r)return;
	if(l+r>>1>=p)add(p,l,l+r>>1,t->ls);
	else add(p,l+r+2>>1,r,t->rs);
}
int getk(int k,int l,int r,node *t){
	if(l==r)return l;
	if(t->ls->cnt>=k)return getk(k,l,l+r>>1,t->ls);
	else return getk(k-t->ls->cnt,l+r+2>>1,r,t->rs);
}
std::pair<int,std::pair<int,int> >q[200002];
int n,a[200002],m,ans[200002];
std::pair<int,int>d[200002];
int main(){
	scanf("%d",&n);init();build(1,n,rt=addnode());
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),d[i]=std::make_pair(-a[i],i);
	std::sort(d+1,d+n+1);scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].first,&q[i].second.first);q[i].second.second=i;
	}std::sort(q+1,q+m+1);
	int tp=1;
	for(int i=1;i<=n;i++){
		add(d[i].second,1,n,rt);
		while(tp<=m&&q[tp].first<=i){
			ans[q[tp].second.second]=getk(q[tp].second.first,1,n,rt);
			tp++;
		}
	}for(int i=1;i<=m;i++)printf("%d\n",a[ans[i]]);
}