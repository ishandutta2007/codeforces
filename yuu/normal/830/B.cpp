#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> pos[100001];
int ft[100001];
void update(int u, int x){
	for(; u<=n; u+=u&-u) ft[u]+=x;
}
int get(int u){
	int res=0;
	for(; u>0; u-=u&-u) res+=ft[u];
	return res;
}
int get(int u, int v){
	return get(v)-get(u-1);
}
int main(){
	cin>>n;
	for(int i=1, a; i<=n; i++){
		cin>>a;
		pos[a].push_back(i);
		update(i, 1);
	}
	long long ans=0;
	int now=1;
	for(int i=1; i<=100000; i++) if(!pos[i].empty()){
		if(pos[i][0]<now){
			ans+=get(now, n);
			while(pos[i].back()>=now){
				update(pos[i].back(), -1);
				pos[i].pop_back();
			}
			now=1;
		}
		ans+=get(now, pos[i].back());
		for(int x: pos[i]) update(x, -1);
		now=pos[i].back();
	}
	cout<<ans<<'\n';
}