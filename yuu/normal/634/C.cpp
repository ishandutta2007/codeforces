#include <bits/stdc++.h>
using namespace std;
class fenwick_tree{
public:
	int ft[200001];
	int a[200001];
	int cap;
	void _update(int u, int x){
		for(; u<=200000; u+=u&-u) ft[u]+=x;
	}
	int get(int u){
		int res=0;
		for(; u>0; u-=u&-u) if(u<=200000) res+=ft[u];
		return res;
	}
	int get(int u, int v){
		if(u>v) return 0;
		return get(v)-get(u-1);
	}
	void update(int d, int x){
		_update(d, min(cap, a[d]+x)-a[d]);
		a[d]=min(a[d]+x, cap);
	}
} tA, tB;
int main(){
	int n, k, q;
	cin>>n>>k>>tA.cap>>tB.cap>>q;
	for(int i=0, t, d, a, p; i<q; i++){
		// cerr<<i<<'\n';
		cin>>t;
		if(t==1){
			cin>>d>>a;
			tA.update(d, a);
			tB.update(d, a);
		}
		else{
			cin>>p;
			cout<<tB.get(1, p-1)+tA.get(p+k, n)<<'\n';
		}
	}
}