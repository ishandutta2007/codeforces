#include<stdio.h>
#include<queue>
#include<algorithm>
#define qwq p->v=Min(p->ls->v+p->ls->cnt,p->rs->v+p->rs->cnt)
inline int Min(int p,int q){return p<q?p:q;}
struct node{
	node *ls,*rs;
	int v,cnt;
}tr[2000002],*null=tr,*rt,*top=tr-1;
node *addnode(){
	node *p=++top;
	p->ls=p->rs=null;p->cnt=0;p->v=1e9;
	return p;
}
void build(int l,int r,node *p){if(l!=r)build(l,l+r>>1,p->ls=addnode()),build(l+r+2>>1,r,p->rs=addnode());}
void add(int R,int l,int r,node *p,int v){
	if(r<=R)return void(p->cnt+=v);
	add(R,l,l+r>>1,p->ls,v);if(R>l+r>>1)add(R,l+r+2>>1,r,p->rs,v);qwq;
}
void add0(int P,int l,int r,node *p,int v){
	if(l==r)return void(p->v=v);
	P<=l+r>>1?add0(P,l,l+r>>1,p->ls,v):add0(P,l+r+2>>1,r,p->rs,v);qwq;
}
int get(){return rt->cnt+rt->v;}
std::priority_queue<std::pair<int,int> >ql;
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::greater<std::pair<int,int> > >qr;
int a[500002],b[500002],c[500002],n;
int main(){
	for(int i=scanf("%d",&n);i<=n;i++)scanf("%d",&a[c[i]=i]);
	std::sort(c+1,c+n+1,[](int p,int q){return a[p]<a[q];});
	for(int i=1;i<=n;i++)b[c[i]]=i;
	addnode();build(1,n,rt=addnode());
	for(int i=1;i<=n;i++){
		if(a[i]>=-(int)ql.size()){
			qr.push(std::make_pair(a[i],i));
			add0(b[i],1,n,rt,a[i]);
			if(b[i]-1)add(b[i]-1,1,n,rt,1);
		}else{
			ql.push(std::make_pair(a[i],i));
			while(!ql.empty()&&1-(int)ql.size()<=ql.top().first){
				int v=ql.top().first,id=ql.top().second;ql.pop();
				add0(b[id],1,n,rt,v);if(b[id]-1)add(b[id]-1,1,n,rt,1);qr.push(std::make_pair(v,id));
			}while(!qr.empty()&&-(int)ql.size()>qr.top().first){
				int v=qr.top().first,id=qr.top().second;qr.pop();
				add0(b[id],1,n,rt,1e9);if(b[id]-1)add(b[id]-1,1,n,rt,-1);ql.push(std::make_pair(v,id));
			}
		}printf("%d\n",Min(-(int)ql.size()+qr.size(),get()));
	}
}