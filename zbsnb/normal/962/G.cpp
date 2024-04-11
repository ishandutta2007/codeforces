#include<bits/stdc++.h>
using namespace std;
#define ll long long
bitset<15010> L,R,U,D;
int x[15010],y[15010];
unordered_map<ll,int> mp;
int tot,ok[15010];
int a,b,c,d;
int ind(pair<int,int> p){
	ll tmp=p.first*150010+p.second;
	if(mp[tmp]) return mp[tmp];
	else {
		// cout<<"new:"<<p.first<<" "<<p.second<<endl;
		// ok[++tot]=p.first>a&&p.first<c&&p.second>b&&p.second<d;
		ok[++tot]=1;
		return mp[tmp]=tot;
	}
}
vector<int> e[100010];
void add(pair<int,int> p1,pair<int,int> p2){
	int a=ind(p1),b=ind(p2);
	// cout<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<endl;
	e[a].push_back(b);e[b].push_back(a);
}
int vis[150010];
int dfs(int u){
	int ret=ok[u];
	vis[u]=1;
	for(auto &v:e[u]){
		if(!vis[v])ret|=dfs(v);
	}
	return ret;
}
int main(){
	cin>>a>>d>>c>>b;a++,b++,c++,d++;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];x[i]++,y[i]++;
		if(x[i]<a)x[i]=a;if(x[i]>c)x[i]=c;
		if(y[i]<b)y[i]=b;if(y[i]>d)y[i]=d;
	}
	// for(int i=1;i<=n;i++)cout<<x[i]<<" "<<y[i]<<endl;
	x[n+1]=x[1];y[n+1]=y[1];
	bitset<15010> tmp;tmp.set();
	for(int i=1;i<=n;i++){
		if(x[i]==x[i+1]&&y[i]==y[i+1]) continue;
		if(x[i]==x[i+1]){
			if(x[i]==a)	L^=(tmp<<min(y[i],y[i+1]))&(tmp>>(15010-max(y[i],y[i+1])));
			else if(x[i]==c) R^=(tmp<<min(y[i],y[i+1]))&(tmp>>(15010-max(y[i],y[i+1])));
			else add({x[i],y[i]},{x[i+1],y[i+1]});
		}
		else if(y[i]==y[i+1]){
			if(y[i]==b) D^=(tmp<<min(x[i],x[i+1]))&(tmp>>(15010-max(x[i],x[i+1])));
			else if(y[i]==d) U^=(tmp<<min(x[i],x[i+1]))&(tmp>>(15010-max(x[i],x[i+1])));
			else add({x[i],y[i]},{x[i+1],y[i+1]});
		}
	}
	// cout<<"---------------"<<endl;
	int preL=0,preR=0,preU=0,preD=0;
	for(int i=1;i<15010;i++){
		if(!L[i]&&L[i-1]) add({a,preL+1},{a,i});
		if(!L[i]) preL=i;
		if(!R[i]&&R[i-1]) add({c,preR+1},{c,i});
		if(!R[i]) preR=i;
		if(!D[i]&&D[i-1]) add({preD+1,b},{i,b});
		if(!D[i]) preD=i;
		if(!U[i]&&U[i-1]) add({preU+1,d},{i,d});
		if(!U[i]) preU=i;
	}
	int ans=0;
	for(int i=1;i<=tot;i++){
		if(!vis[i]) ans+=dfs(i);
	}
	cout<<ans<<endl;
}
/*
5 7 16 3
16
0 0
18 0
18 6
16 6
16 1
10 1
10 4
7 4
7 2
2 2
2 6
12 6
12 12
10 12
10 8
0 8
*/