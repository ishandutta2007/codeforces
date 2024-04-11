#include <bits/stdc++.h>
using namespace std;

template <int N = 500010>
struct UF{
	int par[N],r[N];
	bool used[N];
	UF(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
			r[i] = 0;
			used[i]=false;
		}
	}
	void init(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
			r[i] = 0;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	void unit(int x,int y){
		if(same(x,y))return;
		x = find(x);
		y = find(y);
		if(r[x] < r[y]){
			par[x] = y;
			if(used[x])used[y]=true;
		}
		else {
			par[y] = x;
			if(used[y])used[x]=true;
			if(r[x] == r[y]){
				r[x] ++;
			}
		}
	}
};

UF<500010> uf;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> ret;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		if(k==1){
			int x;
			scanf("%d",&x);
			if(!uf.used[uf.find(x)]){
				ret.push_back(i+1);
				uf.used[uf.find(x)]=true;
			}
		}
		else {
			int x,y;
			scanf("%d%d",&x,&y);
			if(uf.same(x,y))continue;
			if(uf.used[uf.find(x)]&&uf.used[uf.find(y)])continue;
			ret.push_back(i+1);
			uf.unit(x,y);
		}
	}
	long long ans=1;
	long long MOD=1000000007;
	for(int i=0;i<ret.size();i++){
		ans*=2;
		if(ans>=MOD)ans-=MOD;
	}
	printf("%lld %d\n",ans,(int)ret.size());
	for(int i=0;i<ret.size();i++){
		printf("%d%c",ret[i],(i+1==ret.size())?'\n':' ');
	}
}