#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;

template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
int i=0;
for(auto it:v){
	if(i > 0){os << ' ';}
	os << it;
	i++;
} 
return os;
}


using ll=long long ;

void dfs(int now,int from,const vector<vector<int>>&graph,vector<int>&dists,int d){
	dists[now]=d;
	for(auto e:graph[now]){
		if(e!=from)dfs(e,now,graph,dists,d+1);
	}
}
vector<int>get_diamater(const vector<vector<int>>&graph){
	vector<int>dists(graph.size());
	dfs(0,-1,graph,dists,0);
	int k=max_element(dists.begin(),dists.end())-dists.begin();
	dfs(k,-1,graph,dists,0);
	int j=max_element(dists.begin(),dists.end())-dists.begin();

	vector<int>dias;
	int now=j;
	while(now!=k){
		dias.push_back(now);
		for(auto e:graph[now]){
			if(dists[e]==dists[now]-1){
				now=e;
				break;
			}
		}
	}
	dias.push_back(now);
	return dias;
}
vector<int>answers;
vector<int>depths;
using Graph=vector<vector<int>>;
void dfs(int now,int from,const Graph&g){
	depths[now]=1;
	for(auto e:g[now]){
		if(e==from)continue;
		else{
			dfs(e,now,g);
			depths[now]=max(depths[now],depths[e]+1);
		}
	}	
}
int K;
void dfs2(int tt,int now,int from,int c,bool flag,const Graph&g,vector<int>&cs){
	vector<int>max_ds(3);
	max_ds.push_back(tt);
	int mtt=tt+1;
	for(auto e:g[now]){
		if(e==from)continue;
		else{
			max_ds.push_back(depths[e]);
			mtt=max(mtt,depths[e]+1);
		}
	}
	sort(max_ds.begin(),max_ds.end());
	reverse(max_ds.begin(),max_ds.end());
	if(K>=3&&max_ds[2]&&max_ds[1]+max_ds[2]+1>=K){
		return ;
	}else{
		cs[now]=c;
	}
	if(flag)c++;
	else c--;
	if(c>=K)c-=K;
	if(c<0)c+=K;

	for(auto e:g[now]){
		if(e==from)continue;
		dfs2(mtt,e,now,c,flag,g,cs);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N>>K;
	answers.resize(N);
	depths.resize(N);
	vector<vector<int>>g(N);
	for(int i=0;i<N-1;++i){
		int u,v;cin>>u>>v;u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>dias=get_diamater(g);
	int l,r;
	if(dias.size()%2==0){
		l=dias[dias.size()/2-1];
		r=dias[dias.size()/2];
	}else{
		l=dias[dias.size()/2-1];
		r=dias[dias.size()/2];
	}
	
	dfs(l,r,g);
	dfs(r,l,g);
	vector<int>cs(N,-1);
	dfs2(depths[r],l,r,0,false,g,cs);
	dfs2(depths[l],r,l,1,true,g,cs);

	if(find(cs.begin(),cs.end(),-1)==cs.end()){
		cout<<"Yes"<<endl;
		for(auto c:cs)cout<<c+1<<' ';
		cout<<endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}