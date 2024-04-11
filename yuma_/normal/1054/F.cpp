#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



#define _GLIBCXX_DEBUG

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()


//const int INF = 2147483647;
//const long long int L_INF = 9223372036854775807;

typedef int Weight;

const Weight INF = 1e8;
const Weight ZERO = 0;
struct Edge {
	int src, dst;
	Weight weight;
	int id;
	Edge(int src_, int dst_, Weight weight_, const int id_) :
		src(src_), dst(dst_), weight(weight_), id(id_) { }
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
	Edge() :src(0), dst(0), weight(0) {

	}
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

Matrix flow,capacity;

//0
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
				g[d].push_back(Edge(d, s, ZERO));
			}
		}
	}
	int n = g.size();
	flow=Matrix(n, Array(n,ZERO)), capacity=Matrix(n, Array(n,ZERO));
	REP(u, n) FOR(e, g[u]) capacity[e->src][e->dst] =capacity[e->src][e->dst]+ e->weight;


	Weight total = ZERO;
	while (1) {
		queue<int> Q; Q.push(s);
		vector<int> prev(n, -1); prev[s] = s;
		while (!Q.empty() && prev[t] < 0) {
			int u = Q.front(); Q.pop();
			FOR(e, g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > ZERO) {
				prev[e->dst] = u;
				Q.push(e->dst);
			}
		}
		if (prev[t] < 0)break; // prev[x] == -1 <=> t-side
		Weight inc = INF;
		for (int j = t; prev[j] != j; j = prev[j]){
			auto v(RESIDUE(prev[j], j));
			if (inc > v) {
				inc = v;
			}
		}
		for (int j = t; prev[j] != j; j = prev[j])
			flow[prev[j]][j] =flow[prev[j]][j]+inc, flow[j][prev[j]] =flow[j][prev[j]]- inc;;
		total += inc;
	}

	return total;
}

using blue=pair<int,pair<int,int>>;
using red=pair<pair<int,int>,int>;

struct line {
	int u;
	int d;
	int l;
	int r;
};

bool intercept(blue&b, red&r) {
	if(b.second.second<=r.second||r.second<=b.second.first)return false;
	if(r.first.second<=b.first||b.first<=r.first.first)return false;
	return true;
}

void say(vector<line>ls) {
	cout<<ls.size()<<endl;
	for (auto l : ls) {
		printf("%d %d %d %d\n",l.l,l.u,l.r,l.d);
	}
}

int main() {
	int N;cin>>N;
	vector<pair<int,int>>sparks(N);
	map<int,vector<int>>ws,hs;
	for (int i = 0; i < N; ++i) {
		int x,y;cin>>x>>y;
		sparks[i]=make_pair(x,y);
		ws[x].push_back(y);
		hs[y].push_back(x);
	}

	vector<blue>blues;
	vector<red>reds;
	for (auto& wm : ws) {
		sort(wm.second.begin(),wm.second.end());
		for (int i = 0; i < wm.second.size() - 1; ++i) {
			blues.push_back(make_pair(wm.first,make_pair(wm.second[i],wm.second[i+1])));
		}
	}
	for (auto& hm : hs) {
		sort(hm.second.begin(),hm.second.end());
		for (int i = 0; i < hm.second.size() - 1; ++i) {
			reds.push_back(make_pair(make_pair(hm.second[i],hm.second[i+1]),hm.first));
		}
	}
	const int start_id=0;
	const int blue_id=start_id+1;
	const int red_id=blue_id+blues.size();
	const int goal_id=red_id+reds.size();

	Graph g(goal_id+1);
	for (int i = 0; i < blues.size(); ++i) {
		g[start_id].push_back(Edge(start_id,blue_id+i,1));
		g[blue_id+i].push_back(Edge(blue_id+i,goal_id,0));
	}
	for (int i = 0; i < reds.size(); ++i) {
		g[start_id].push_back(Edge(start_id,red_id+i,0));
		g[red_id+i].push_back(Edge(red_id+i,goal_id,1));
	}
	for (int i = 0; i < blues.size(); ++i) {
		for (int j = 0; j < reds.size(); ++j) {
			if (intercept(blues[i], reds[j])) {
				g[blue_id + i].push_back(Edge( blue_id + i,red_id + j,1e8 ));
			}
		}
	}
	int num=maximumFlow(g,start_id,goal_id);
	vector<int>comes(g.size());
	queue<int>que;
	que.push(start_id);
	while (!que.empty()) {
		int now(que.front());
		que.pop();
		comes[now]=true;
		for (int i = 0; i < g.size(); ++i) {
			if (RESIDUE(now, i)) {
				if (!comes[i]) {
					comes[i] = true;
					que.push(i);
				}
			}
		}
	}
	vector<int>blue_uses(blues.size()),red_uses(reds.size());
	for (int i = 0; i < blues.size(); ++i) {
		if(comes[blue_id+i])blue_uses[i]=true;
	}
	for (int i = 0; i < reds.size(); ++i) {
		if(!comes[red_id+i])red_uses[i]=true;
	}

	vector<line>blue_anss,red_anss;
	{
		int aa=0;
		for (auto wm : ws) {
			int pre_y=-1;
			for (int i = 0; i < wm.second.size()-1; ++i) {
				if (blue_uses[aa++]) {
					if (pre_y == -1)pre_y = wm.second[i];

				}
				else {
					if(pre_y==-1)pre_y=wm.second[i];
					blue_anss.push_back(line{ pre_y,wm.second[i],wm.first,wm.first });
					pre_y=-1;
				}
			}
			if (pre_y ==-1)pre_y=wm.second.back();
			blue_anss.push_back(line{ pre_y,wm.second[wm.second.size() - 1],wm.first,wm.first });
			

		}
	}
	{
		int aa = 0;
		for (auto hm :hs) {
			int pre_x = -1;
			for (int i = 0; i < hm.second.size() - 1; ++i) {
				if (red_uses[aa++]) {
					if(pre_x==-1)pre_x = hm.second[i];
				}
				else {
					if (pre_x == -1)pre_x = hm.second[i];
					red_anss.push_back(line{ hm.first,hm.first,pre_x,hm.second[i] });
					pre_x= -1;
				}
			}
			if (pre_x== -1) pre_x=hm.second[hm.second.size()-1];

			red_anss.push_back(line{ hm.first,hm.first,pre_x,hm.second[hm.second.size() - 1] });
			

		}
	}
	say(red_anss);
	say(blue_anss);
	return 0;
}