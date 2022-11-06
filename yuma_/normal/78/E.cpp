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

    cin>>N>>T;
    vector<vector<int>>canmove(N,vector<int>(N,true));
    vector<vector<int>>ins(N,vector<int>(N)),outs(N,vector<int>(N));

    vector<string>in_sts(N),out_sts(N);

    int collapt_x,collapt_y;
    for(int i=0;i<N;++i){
        cin>>in_sts[i];
        for(int j=0;j<N;++j){
            if(in_sts[i][j]=='Y'){
                canmove[i][j]=false;
            }else if(in_sts[i][j]=='Z'){
                canmove[i][j]=false;
            }else{
                ins[i][j]=in_sts[i][j]-'0';
            }
        }
    }

    for(int i=0;i<N;++i){
        cin>>out_sts[i];
        for(int j=0;j<N;++j){
            if(out_sts[i][j]=='Y'){
            }else if(out_sts[i][j]=='Z'){
                collapt_x=j;
                collapt_y=i;
            }else{
                outs[i][j]=out_sts[i][j]-'0';
            }
        }
    }
    vector<vector<int>>collapt_times=get_time(canmove,collapt_y,collapt_x,vector<vector<int>>(0));

    vector<vector<vector<vector<int>>>>oks(N,vector<vector<vector<int>>>(N,vector<vector<int>>(N,vector<int>(N))));
    //WHATS(collapt_times)
    const int start=0;
    const int in_id=1;
    const int out_id=in_id+N*N;
    const int goal=out_id+N*N;
    Graph g(goal+1);
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            g[start].push_back(Edge{start,in_id+y*N+x,ins[y][x]});
            g[out_id+y*N+x].push_back(Edge{out_id+y*N+x,goal,outs[y][x]});
        }
    }
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            auto atimes=get_time(canmove,y,x,collapt_times);
            //WHATS(atimes)
            //WHATS(y)
            //WHATS(x)
            for(int ty=0;ty<N;++ty){
                for(int tx=0;tx<N;++tx){
                    if(atimes[ty][tx]<=collapt_times[ty][tx]&&atimes[ty][tx]<=T){
                        oks[y][x][ty][tx]=true;
                        int aid=in_id+y*N+x;
                        int bid=out_id+ty*N+tx;

                        g[aid].push_back(Edge{aid,bid,1000});
                        
                    }
                }
            }
        }
    }
    int answer=maximumFlow(g,start,goal);
    cout<<answer<<endl;
	return 0;
}