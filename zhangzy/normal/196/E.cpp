#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define xxx 233520
#define ll long long
using namespace std;
ll n,m,g,st,ans,aim;
struct R{
	ll to,val,nex;
}r[xxx];
ll hea[xxx],cnt=1;
struct E{
	ll from,to,val;
}e[xxx];
bool bo[xxx];

void A(ll u,ll v,ll w){
	r[++cnt]=(R){v,w,hea[u]};
	hea[u]=cnt;
	r[++cnt]=(R){u,w,hea[v]};
	hea[v]=cnt;
}

struct P{
	ll p,d;
}U,V;
struct cmp{
	bool operator()(P &p1,P &p2){
		return p1.d>p2.d;
	}
};
priority_queue<P,vector<P>,cmp>q;

ll d[xxx],pre[xxx];
void doit(){
	while (!q.empty()){
		U=q.top();q.pop();
		if (U.d>d[U.p]) continue;
		for (int i=hea[U.p];i>0;i=r[i].nex){
			V.p=r[i].to;
			V.d=U.d+r[i].val;
			if (V.d<d[V.p]){
				d[V.p]=V.d;
				pre[V.p]=pre[U.p];
				q.push(V);
			}
		}
	}
}

ll df1[xxx];
void djfrom1(){
	memset(df1,38,sizeof(df1));
	while (!q.empty()) q.pop();
	df1[1]=0;
	q.push((P){1,0});
	while (!q.empty()){
		U=q.top();q.pop();
		if (U.d>df1[U.p]) continue;
		if (bo[U.p]){
			st=U.p;
			ans=df1[U.p];
			return;
		}
		for (int i=hea[U.p];i>0;i=r[i].nex){
			V.p=r[i].to;
			V.d=U.d+r[i].val;
			if (V.d<df1[V.p]){
				df1[V.p]=V.d;
				q.push(V);
			}
		}
	}
}

bool cmp(E e1,E e2){
	return e1.val<e2.val;
}

int fa[xxx];
int GF(int x){
	return fa[x]==x ? x : fa[x]=GF(fa[x]);
}

int main(){
	scanf("%I64d%I64d",&n,&m);
	memset(hea,0,sizeof(hea));
	ll x,y,z;
	for (int i=1;i<=m;i++){
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		e[i]=(E){x,y,z};
		A(x,y,z);
	}
	scanf("%I64d",&g);
	memset(d,38,sizeof(d));
	for (int i=1;i<=g;i++){
		scanf("%I64d",&x);
		bo[x]=1;
		d[x]=0;
		pre[x]=i;
		q.push((P){x,0});
	}
	
	ans=0;
	doit();
	
	djfrom1();
	
	for (int i=1;i<=m;i++){
		e[i].val+= d[e[i].from]+d[e[i].to];
		e[i].from= pre[e[i].from];
		e[i].to= pre[e[i].to];
	}
	
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=g;i++){
		fa[i]=i;
	}
	int f1,f2;
	for (int i=1;i<=m;i++){
		f1=GF(e[i].from);f2=GF(e[i].to);
		if (f1!=f2){
			ans+=e[i].val;
			fa[f1]=f2;
		}
	}
	
	cout<<ans;
}