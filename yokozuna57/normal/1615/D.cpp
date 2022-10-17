#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int f(int x){
	int ret=0;
	while(x>0){
		ret+=x&1;
		x>>=1;
	}
	return ret&1;
}

struct UF{
	vector<int> par,r;
	UF(int n){ init(n); }
	UF(){}
	void init(int n=-1){
		if(n==-1)n=par.size();
		par.resize(n);
		r.resize(n);
		iota(par.begin(),par.end(),0);
		fill(r.begin(),r.end(),0);
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
 	bool same(int x,int y){ return find(x)==find(y); }
	void unit(int x,int y){
		if(same(x,y))return;
		x=find(x);
		y=find(y);
		if(r[x]>r[y])swap(x,y);
		par[x]=y;
		if(r[x]==r[y])r[y]++;
	}
};

int n,m;
int x[200010],y[200010],v[200010],a[200010],b[200010],p[200010];
void solve(){
	for(int i=0;i<n-1;i++){
		x[i]--; y[i]--;
	}
	UF uf(2*n);
	for(int i=0;i<m;i++){
		a[i]--; b[i]--;
		if(p[i]==0){
			uf.unit(a[i],b[i]);
			uf.unit(a[i]+n,b[i]+n);
		}
		else {
			uf.unit(a[i],n+b[i]);
			uf.unit(b[i],n+a[i]);
		}
	}
	for(int i=0;i<n-1;i++){
		if(v[i]!=-1){
			if(f(v[i])==0){
				uf.unit(x[i],y[i]);
				uf.unit(x[i]+n,y[i]+n);
			}
			else {
				uf.unit(x[i],y[i]+n);
				uf.unit(y[i],x[i]+n);
			}
		}
	}
	for(int i=1;i<n;i++){
		if(!uf.same(0,i))if(!uf.same(0,i+n)){
			uf.unit(0,i);
			uf.unit(n,i+n);
		}
	}
	for(int i=0;i<n;i++){
		if(uf.same(i,n+i)){
			puts("NO");
			return;
		}
	}
	puts("YES");
	for(int i=0;i<n-1;i++){
		if(v[i]==-1){
			if(uf.same(x[i],y[i]))v[i]=0;
			else v[i]=1;
		}
		printf("%d %d %d\n",x[i]+1,y[i]+1,v[i]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n-1;i++)scanf("%d%d%d",&x[i],&y[i],&v[i]);
		for(int i=0;i<m;i++)scanf("%d%d%d",&a[i],&b[i],&p[i]);
		solve();
	}
}