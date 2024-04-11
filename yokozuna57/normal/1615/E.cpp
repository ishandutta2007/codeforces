#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int n,k;
vector<int> G[200010];

multiset<int> *s[200010];
void dfs(int v,int p){
	s[v]=new multiset<int>;
	for(int u: G[v]){
		if(u==p)continue;
		dfs(u,v);
		if(s[v]->size()<s[u]->size()){
			for(int x: *s[v])s[u]->insert(x);
			s[v]=s[u];
		}
		else {
			for(int x: *s[u])s[v]->insert(x);
		}
	}
	if(s[v]->size()==0)s[v]->insert(1);
	else {
		auto itr=s[v]->end(); --itr;
		int x=*itr; x++;
		s[v]->erase(itr);
		s[v]->insert(x);
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	ll ret=-1000000000000000000;
	int sum=0;
	for(int i=0;i<k;i++){
		if(s[0]->size()==0)break;
		auto itr=s[0]->end(); --itr;
		int x=*itr; s[0]->erase(itr);
		sum+=x;
		if(min(k,sum)>=n-sum){
			ll b=n-sum;
			ll r=max(i+1,min(min(k,sum),sum/2));
			ret=max(ret,(n-r-b)*(r-b));
		}
		else {
			ll r=min(k,sum);
			ll b=min(n-sum,n/2);
			ret=max(ret,(n-r-b)*(r-b));
		}
	}
	cout<<ret<<endl;
}