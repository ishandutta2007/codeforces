#include<bits/stdc++.h>
using namespace std;
const int LG=30,M=2e5+10;
int ch[M*LG][2],tot,n;
vector<int> v[M*LG];
void ins(int x){
	int p=0;
	for (int i=30;~i;--i){
		bool o=x>>i&1;
		if (ch[p][o]) p=ch[p][o];
		else p=(ch[p][o]=++tot);
		v[p].push_back(x);
//		cout<<p<<" "<<i<<" "<<x<<"  build\n";
	}
}
int query(int p,int x,int dep){
	if (!dep) return 0;
	bool o=(x>>dep-1)&1;
//	cout<<p<<" "<<dep<<" "<<o<<" "<<ch[p][o]<<" "<<x<<"  dfs\n";
	if (ch[p][o]) return query(ch[p][o],x,dep-1);
	return (1<<dep-1)+query(ch[p][o^1],x,dep-1);
}
long long ans;
void solve(int x,int dep){
	int mincost=INT_MAX;	
	if (ch[x][0]) solve(ch[x][0],dep-1); 
	if (ch[x][1]) solve(ch[x][1],dep-1);
	if (!(v[ch[x][0]].size()) || !(v[ch[x][1]].size())) return ;
	bool o=0;
	if (v[ch[x][0]].size()>v[ch[x][1]].size()) o=1;
	for (int i=0;i<v[ch[x][o]].size();i++){
		mincost=min(mincost,query(ch[x][o^1],v[ch[x][o]][i],dep-1));
//		cout<<mincost<<" "<<v[ch[x][o]][i]<<" k\n";
	}
//	cout<<x<<" "<<dep<<" "<<mincost<<"    info\n";
	ans+=mincost+(1<<dep-1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cin>>n;
//	ins(0);
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		ins(x);
	}
//	cout<<query(1,7,2)<<"\n";
	solve(0,31);
	cout<<ans<<"\n";
	return 0;
}