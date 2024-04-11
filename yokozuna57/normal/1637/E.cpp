#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

const int B=600;

int n,m;
int a[300010];
int u[300010],v[300010];

void solve(){
	set<pair<int,int>> bad;
	for(int i=0;i<m;i++){
		bad.insert(mp(u[i],v[i]));
		bad.insert(mp(v[i],u[i]));
	}
	map<int,int> cnt;
	for(int i=0;i<n;i++){
		cnt[a[i]]++;
	}
	vector<int> v1[B];
	vector<pair<int,int>> v2;
	for(auto p: cnt){
		if(p.sc<B){
			v1[p.sc].push_back(p.fr);
		}
		else v2.push_back(p);
	}
	for(int i=0;i<B;i++){
		reverse(v1[i].begin(),v1[i].end());
	}
	ll ret=0;
	for(int i=0;i<B;i++){
		for(int x: v1[i]){
			for(int j=0;j<B;j++){
				int s=0;
				while(s<v1[j].size()){
					int y=v1[j][s];
					if(x==y){ s++; continue; }
					if(bad.find(mp(x,y))==bad.end())break;
					s++;
				}
				if(s<v1[j].size()){
					int y=v1[j][s];
					ret=max(ret,(ll)(x+y)*(ll)(i+j));
				}
			}
			for(auto q: v2){
				if(bad.find(mp(x,q.fr))==bad.end()){
					int y=q.fr;
					ret=max(ret,(ll)(x+y)*(ll)(i+q.sc));
				}
			}
		}
	}
	for(auto p: v2){
		int i=p.sc;
		int x=p.fr;
		for(int j=0;j<B;j++){
			int s=0;
			while(s<v1[j].size()){
				int y=v1[j][s];
				if(bad.find(mp(x,y))==bad.end())break;
				s++;
			}
			if(s<v1[j].size()){
				int y=v1[j][s];
				ret=max(ret,(ll)(x+y)*(ll)(i+j));
			}
		}
		for(auto q: v2){
			if(p==q)continue;
			if(bad.find(mp(x,q.fr))==bad.end()){
				int y=q.fr;
				ret=max(ret,(ll)(x+y)*(ll)(i+q.sc));
			}
		}
	}
	printf("%lld\n",ret);
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<m;i++)scanf("%d%d",&u[i],&v[i]);
		
		solve();
	}
}