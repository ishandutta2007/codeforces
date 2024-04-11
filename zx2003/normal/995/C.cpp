#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
struct P{int x,y;}a[N];
typedef pair<P,int>ppi;
P operator+(P a,P b){return (P){a.x+b.x,a.y+b.y};}
P operator-(P a,P b){return (P){a.x-b.x,a.y-b.y};}
ll len(P a){return 1ll*a.x*a.x+1ll*a.y*a.y;}
int n,i,lc[N*2],rc[N*2],tp[N*2],nn,ans[N];
ppi p,q;
P calc(P a,P b){return len(a+b)>len(a-b)?a-b:a+b;}
bool ck(P a,P b){P c=calc(a,b);return len(c)<=max(len(a),len(b));}
ppi uni(ppi a,ppi b){
	P a1,b1;int a2,b2;tie(a1,a2)=a;tie(b1,b2)=b;
	++nn;
	if(len(a1+b1)>len(a1-b1)){
		lc[nn]=a2;rc[nn]=b2;tp[nn]=-1;
		return {a1-b1,nn};
	}else{
		lc[nn]=a2;rc[nn]=b2;tp[nn]=1;
		return {a1+b1,nn};
	}
}
void ins(pair<P,int>r){
	if(ck(p.first,q.first)){
		p=uni(p,q);q=r;
	}else if(ck(q.first,r.first)){
		q=uni(q,r);
	}else p=uni(r,p);
}
void dfs(int x,int v){if(!lc[x] && !rc[x])ans[x]=v;else dfs(lc[x],v),dfs(rc[x],v*tp[x]);}
void spj(){
	P tot=(P){0,0};
	for(i=1;i<=n;++i){
		assert(ans[i]==1 || ans[i]==-1);
		if(ans[i]==1)tot=tot+a[i];else tot=tot-a[i];
	}
	assert(sqrt(len(tot))<=1.5e6);
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
	if(n==1){puts("1");return 0;}
	p={a[1],1};q={a[2],2};nn=n;
	for(i=3;i<=n;++i)ins({a[i],i});
	uni(p,q);
	dfs(nn,1);
	for(i=1;i<=n;++i)printf("%d%c",ans[i],i==n?'\n':' ');
spj();
}