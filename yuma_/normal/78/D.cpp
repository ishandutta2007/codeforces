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
#include<memory>

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
//using Graph=vector<vector<int>>;
	
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()


const int INF = 2147483647;
const long long int L_INF = 9223372036854775807;

typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])

//0t
Weight maximumFlow(const Graph &ag, int s, int t) {

	Graph g(ag);
	for (int i = 0; i < ag.size(); ++i) {
		for (int j = 0; j < ag[i].size(); ++j) {
			int d = ag[i][j].dst;
			int s = ag[i][j].src;

			bool ok = false;
			for (int k = 0; k < ag[d].size(); ++k) {
				if (ag[d][k].src == s) {
					ok = true;
					break;
				}
			}
			if (!ok) {
				g[d].push_back(Edge(d, s, 0));
			}
		}
	}
	int n = g.size();
	Matrix flow(n, Array(n)), capacity(n, Array(n));
	REP(u, n) FOR(e, g[u]) capacity[e->src][e->dst] += e->weight;


	Weight total = 0;
	while (1) {
		queue<int> Q; Q.push(s);
		vector<int> prev(n, -1); prev[s] = s;
		while (!Q.empty() && prev[t] < 0) {
			int u = Q.front(); Q.pop();
			FOR(e, g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
				prev[e->dst] = u;
				Q.push(e->dst);
			}
		}
		if (prev[t] < 0)break; // prev[x] == -1 <=> t-side
		Weight inc = INF;
		for (int j = t; prev[j] != j; j = prev[j])
			inc = min(inc, RESIDUE(prev[j], j));
		for (int j = t; prev[j] != j; j = prev[j])
			flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
		total += inc;
	}

	return total;
}
	
using ll = long long int;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int N,T;
vector<vector<int>>get_time(const vector<vector<int>>&canmove,int sy,int sx,vector<vector<int>>c_times){
    vector<vector<int>>times(N,vector<int>(N,100000));
    if(c_times.empty()){
        c_times=times;
    }
    times[sy][sx]=0;
    queue<pair<int,int>>que;
    que.emplace(sx,sy);
    while(!que.empty()){
        auto p(que.front());
        que.pop();
        int x=p.first;
        int y=p.second;
        if(c_times[y][x]==times[y][x])continue;
        for(int way=0;way<4;++way){
            int nx=x+dx[way];
            int ny=y+dy[way];
            if(nx>=0&&nx<N&&ny>=0&&ny<N){
                if(canmove[ny][nx]!=false){
                    if(times[ny][nx]>times[y][x]+1&&c_times[ny][nx]>=times[y][x]+1){
                        times[ny][nx]=times[y][x]+1;
                        que.emplace(nx,ny);
                    }
                }
            }
        }
    }
    return times;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();

    ld K;cin>>K;
    ll answer=0;
    ld eps=1e-9;
    vector<pair<ld,ld>>ofs{make_pair(0.5,0.5*sqrt(3)),make_pair(1,0)};
    for(int i=0;i<  K+1;++i){
        int ok=-1;
        int ng=K+1;
        while(ok+1!=ng){
            int amid((ok+ng)/2);

            ld x=1.5*i;
            ld y=amid*sqrt(3);
            if(i%2==1)y+=sqrt(3)/2;

            bool aok=true;
            for(int i=0;i<2;++i){
                ld nx=x+ofs[i].first;
                ld ny=y+ofs[i].second;
                //WHATS(nx)
                //WHATS(ny)
                ld sum=nx*nx+ny*ny;
                //WHATS(sum)

                if(nx*nx+ny*ny>(K)*K+eps){
                    aok=false;
                }
            }
            //WHATS(aok)
            if(aok){
                ok=amid;
                
            }else{
                ng=amid;
            }
        }
        //WHATS(ok)
        ll plus=0;
        //WHATS(ok)
        if(i%2==0){
            plus=ok*2+1;
        }else{
            plus=ok*2+2;
        }
        if(i!=0)plus*=2;
        plus=max(0ll,plus);
        answer+=plus;
    }
    cout<<answer<<endl;
	return 0;
}