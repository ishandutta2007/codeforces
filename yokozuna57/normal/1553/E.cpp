#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

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
int p[300010];

int cnt[300010];
void solve(){
	vector<int> ret;
	for(int i=0;i<n;i++)cnt[i]=0;
	for(int i=0;i<n;i++){
		if(p[i]<=i)cnt[i-p[i]]++;
		else {
			cnt[(i+n)-p[i]]++;
		}
	}
	for(int k=0;k<n;k++){
		if((n-cnt[k]+1)/2>m)continue;
		UF uf(n);
		for(int i=0;i<n;i++){
			uf.unit(i,(p[i]+k)%n);
		}
		int c=n;
		for(int i=0;i<n;i++){
			if(uf.find(i)==i)c--;
		}
		if(c<=m)ret.push_back(k);
	}
	printf("%d",(int)ret.size());
	for(int x: ret)printf(" %d",x);
	puts("");
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){ scanf("%d",&p[i]); p[i]--; }
		solve();
	}
}