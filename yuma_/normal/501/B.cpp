#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
using namespace std;
template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first1,
	BidirectionalIterator last1,
	BidirectionalIterator first2,
	BidirectionalIterator last2)
{
	if ((first1 == last1) || (first2 == last2)) {
		return false;
	}
	BidirectionalIterator m1 = last1;
	BidirectionalIterator m2 = last2; --m2;
	while (--m1 != first1 && !(*m1 < *m2)) {
	}
	bool result = (m1 == first1) && !(*first1 < *m2);
	if (!result) {
		// ?
		while (first2 != m2 && !(*m1 < *first2)) {
			++first2;
		}
		first1 = m1;
		std::iter_swap(first1, first2);
		++first1;
		++first2;
	}
	if ((first1 != last1) && (first2 != last2)) {
		// ?
		m1 = last1; m2 = first2;
		while ((m1 != first1) && (m2 != last2)) {
			std::iter_swap(--m1, m2);
			++m2;
		}
		// ?
		std::reverse(first1, m1);
		std::reverse(first1, last1);
		std::reverse(m2, last2);
		std::reverse(first2, last2);
	}
	return !result;
}

template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first,
	BidirectionalIterator middle,
	BidirectionalIterator last)
{
	return next_combination(first, middle, middle, last);
}



class Compare {
public:
	bool operator()(const pair<int,long long  int>&l, const pair<int, long long int >&r) {
		return l.second > r.second;
	}
};






#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

const int INF = 2147483647;

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

vector<pair<int, int>>uses;

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
		if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
		Weight inc = INF;
		for (int j = t; prev[j] != j; j = prev[j])
			inc = min(inc, RESIDUE(prev[j], j));
		for (int j = t; prev[j] != j; j = prev[j])
			flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
		total += inc;
	}
}

int main() {
	//while (1) {
	//	int H, W, C, M, Nw, Nc, Nm; cin >> H >> W >> C >> M >> Nw >> Nc >> Nm;
	//	if (H == -1)break;
	//	Graph g(H + W + C + M + 8);
	//	const int start = 0;
	//	const int goal = H + W + C + M + 1;
	//	const int nowarrior1 = H + W + C + M + 2;
	//	const int nowarrior2 = H + W + C + M + 3;
	//	const int nocleric1 = H + W + C + M + 4;
	//	const int nocleric2 = H + W + C + M + 5;
	//	const int nomage1 = H + W + C + M + 6;
	//	const int nomage2 = H + W + C + M + 7;


	//	//0:start 1~H hero H+1~H+W warrior H+W+1~H+W+C cleric H+W+C+1~H+W+C+M mage H+W+C+M+1 goal H+W+C+M+2 nowarr

	//	
	//	for (int i = 0; i < H; ++i) {
	//		g[start].push_back(Edge(start, i + 1, 1));
	//		g[i + 1].push_back(Edge(i + 1, nowarrior1, 1));
	//	}
	//	g[nowarrior1].push_back(Edge(nowarrior1, nowarrior2, Nw));
	//	for (int i = 0; i < W; ++i) {
	//		int n; cin >> n;
	//		for (int j = 0; j < n; ++j) {
	//			int  a; cin >> a;
	//			g[a].push_back(Edge(a, H + i+1, 1));
	//		}
	//		g[H+i + 1].push_back(Edge(H+i + 1, nocleric1, 1));
	//	}
	//	g[nocleric1].push_back(Edge(nocleric1, nocleric2, Nc));
	//	for (int i = 0; i < C; ++i) {
	//		g[nowarrior2].push_back(Edge(nowarrior2, H + i + 1, 1));
	//		int n; cin >> n;
	//		for (int j = 0; j < n; ++j) {
	//			int  a; cin >> a;
	//			g[a+H].push_back(Edge(a+H, H + W + i+1, 1));
	//		}
	//		g[H+W+i+1].push_back(Edge(H + W + i + 1, nomage1, 1));
	//	}
	//	g[nomage1].push_back(Edge(nomage1, nomage2, Nm));
	//	for (int i = 0; i < M; ++i) {
	//		g[nocleric2].push_back(Edge(nocleric2, H + W + i + 1, 1));
	//		g[H + W + C + i + 1].push_back(Edge(H + W + C + i + 1, goal, 1));
	//		int n; cin >> n;
	//		for (int j = 0; j < n; ++j) {
	//			int  a; cin >> a;
	//			g[a + H+W].push_back(Edge(a + H + W, H + W + C + i+1, 1));
	//		}
	//	}
	//	g[nomage2].push_back(Edge(nomage2, goal, 1));
	//	int ans = maximumFlow(g, start, goal);
	//	cout << ans << endl;

	//}
	//return 0;

	int M; cin >> M;
	map<string, string>mp;
	for (int i = 0; i < M; ++i) {
		string st1, st2; cin >> st1 >> st2;
		if (!mp.count(st1)) {
			mp[st2] = st1;
		}
		else {
			mp[st2] = mp[st1];
			mp.erase(st1);
		}
	}
	cout << mp.size() << endl;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		cout << (*it).second << " " << (*it).first << endl;
	}
	return 0;
}