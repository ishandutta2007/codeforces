#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int Q=5;
const ll K=10000;
ll f[Q];
map<ll,ll> g[Q];

ll ask(ll l,int num,vector<ll> *las=NULL){
	if (num<0) return 0;
	if (las==NULL&&g[num].count(l)) return g[num][l];
	if (las==NULL&&l>=K) return f[num];
	ll res=0,p=l;
	for (ll i=1;i<=min(l,K)+1;i++){
		p+=ask(p,num-1);
		if (i!=min(l,K)+1){
			if (las!=NULL) las->push_back(p); p++;
		}
	}
	return g[num][l]=p-l;
}
int main(){
	f[0]=K;
	for (int i=1;i<Q;i++)
		f[i]=f[i-1]*(K+1)+K;
	ll l=1;
	for (int i=Q-1;i>=0;i--){
		vector<ll> list;
		ask(l,i,&list);
		printf("%d ",list.size());
		for (int j=0;j<list.size();j++)
			printf("%lld ",list[j]);
		puts("");
		fflush(stdout);
		int ans; scanf("%d",&ans);
		if (ans==-1) break;
		if (ans) l=list[ans-1]+1;
	}
}