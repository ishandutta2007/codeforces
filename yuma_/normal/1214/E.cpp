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

//
// Hopcroft-Karp's maximum cardinality bipartite matching
//
// Description:
//   Compute the maximum cardinality matching for bipartite graph.
//
// Algorithm:
//   The algorithm iterates following procedures:
//     (1) BFS from the source to get the distance to the sink.
//         If not reachable, there are no augment path hence break.
//     (2) Find vertex disjoint shortest augment paths by DFS.
//   It can be shown that the outer-loop is atmost O(\sqrt{n}) times
//   therefore the whole complexity is O(m \sqrt{n}).
//   Note that this is a specialzation of Dinic's maximum flow.
//
//
// Complexity:
//   O(m \sqrt{n}) time
//
// Verified:
//   SPOJ 4206: Fast Maximum Matching
//
// References:
//   J. E. Hopcroft and R. M. Karp (1973):
//   An n^5/2 algorithm for maximum matchings in bipartite graphs.
//   SIAM Journal on Computing, vol.2, no.4, pp.225-231.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;
  vector<int>mate(int(2e5),-1);

struct graph {
  int L, R;
  vector<vector<int>> adj;
  graph(int L, int R) : L(L), R(R), adj(L+R) { }
  void add_edge(int u, int v) {
    adj[u].push_back(v+L);
    adj[v+L].push_back(u);
  }
  int maximum_matching() {
    vector<int> level(L);

    function<bool(void)> levelize = [&]() { // BFS
      queue<int> Q;
      for (int u = 0; u < L; ++u) {
        level[u] = -1;
        if (mate[u] < 0) {
          level[u] = 0;
          Q.push(u); 
        }
      }
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int w: adj[u]) {
          int v = mate[w];
          if (v < 0) return true;
          if (level[v] < 0) {
            level[v] = level[u] + 1;
            Q.push(v); 
          }
        }
      }
      return false;
    };
    function<bool(int)> augment = [&](int u) { // DFS
      for (int w: adj[u]) {
        int v = mate[w];
        if (v < 0 || (level[v] > level[u] && augment(v))) {
          mate[u] = w;
          mate[w] = u;
          return true;
        }
      }
      return false;
    };
    int match = 0;
    while (levelize()) 
      for (int u = 0; u < L; ++u) 
        if (mate[u] < 0 && augment(u)) 
          ++match;
    return match;
  }
};

// int main() {
//   int L, R, m; 
//   scanf("%d %d %d", &L, &R, &m);
//   graph g(L, R);
//   for (int i = 0; i < m; ++i) {
//     int u, v;
//     scanf("%d %d", &u, &v);
//     g.add_edge(u, v);
//   }
//   printf("%d\n", g.maximum_matching());
// }


struct Edge{
	int src;
	int dst;
	int id;
};
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;

// res: bridges
// v: current node
// from: parent node
int dfs(vector<vector<Edge>>& g, vector<int>& res, int v, int& count, int from_id, VI& low, VI& pre) {
  pre[v] = count++;
  low[v] = pre[v];
  for (auto it = g[v].begin(); it != g[v].end(); it++) {
    int to = it->dst;
    if (pre[to] == -1) {
      // destination has not been visited
      // visit destination and update low[v]
      low[v] = min(low[v], dfs(g, res, to, count, it->id, low, pre));
      if (low[to] == pre[to]) {
        // edge is not contained in a closed path -> bridge
        res.push_back(it->id);
      }
    } else {
      if (from_id == it->id) {
        // ignore a path to parent
        continue;
      }
      low[v] = min(low[v], low[to]);
    }
  }
  return low[v];
}

// Calculate bridges in a undirected graph.
// Assume graph is connected and has no parallel edges or self-loops.
// g: adjacency list
// V: number of nodes
vector<int> get_bridge(vector<vector<Edge>> g, int V,int M) {
  vector<int> res;
  if (V > 0) {
    // assume at least the first vertex exists
    VI low(V, -1);  // lowest reacheable index
    VI pre(V, -1);  // pre-order index
    int count = 0;  // pre-order index counter
	for(int x=0;x<V;++x){
		WHATS(pre[x])
    	if(pre[x]==-1)dfs(g, res, x, count, -1, low, pre);  // start dfs from vertex 0

	}
  }
  vector<int>nums(M);
  for(auto re:res)nums[re]=true;
  return nums;
}


int main() {
	//ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<pair<int,int>>ps;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		ps.emplace_back(a,i);
	}
	sort(ps.begin(),ps.end(),greater<pair<int,int>>());
	vector<int>lines(N,-1);
	vector<vector<int>>pluss(2*N);
	for(int i=0;i<ps.size();++i){
		int id=ps[i].second;
		int len=ps[i].first;
		if(i+len==lines.size()){
			lines.push_back(2*id+1);
		}else{
			pluss[i+len-1].push_back(2*id+1);
		}
		lines[i]=2*id;
	}
	vector<pair<int,int>>answers;
	for(int i=0;i<lines.size()-1;++i){
		answers.emplace_back(lines[i],lines[i+1]);
	}
	//WHATS(lines)
	//WHATS(pluss)
	for(int i=0;i<pluss.size();++i){
		if(!pluss[i].empty()){
			for(auto pl:pluss[i]){
				answers.emplace_back(lines[i],pl);
			}

		}
	}
	for(auto ans:answers){
		cout<<ans.first+1<<' '<<ans.second+1<<endl;
	}
	return 0;
}