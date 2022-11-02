#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define INF 100000
static int l[1001][1001], dist[1001][1001];
int n,m;
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

typedef pair<int, int> pii;

void dijkstra(int s){
	queue<pii> dp;
	dp.push(pii(0, s));
	dist[s][s] = 0;
	while(!dp.empty()){
		pii p = dp.front();
		dp.pop();
		for(int i=0;i<n;i++){
			if(dist[s][i] <= p.first+1 || !l[p.second][i]) continue;
			dist[s][i] = p.first + 1;
			dp.push(pii(p.first+1, i));
		}
	}
}

Edges dijkstra2(int s){
	Edges e;
	queue<pii> dp;
	dp.push(pii(0, s));
	dist[s][s] = 0;
	while(!dp.empty()){
		pii p = dp.front();
		dp.pop();
		for(int i=0;i<n;i++){
			if(dist[s][i] <= p.first+1 || !l[p.second][i]) continue;
			dist[s][i] = p.first + 1;
			dp.push(pii(p.first+1, i));
			e.push_back(Edge(p.second, i, 1));
		}
	}
	return e;
}

main(){
	int i,j, rb=0,cb=0;
	char a;
	cin >> n >> m;
	memset(l, -1, sizeof(l));
	for(i=0;i<m;i++){
		int from, to;
		cin >> from >> to;
		l[from-1][to-1] = l[to-1][from-1] = 0;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dist[i][j] = (i==j)?0:INF;
	int center, min1=INF;
	for(i=0;i<n;i++){
		dijkstra(i);
		int max2=0;
		for(j=0;j<n;j++)
			max2=max(max2, dist[i][j]);
		if(max2 < min1){
			min1 = max2;
			center = i;
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dist[i][j] = (i==j)?0:INF;
	Edges e = dijkstra2(center);
	cout << e.size() << endl;
	for(i=0;i<e.size();i++){
		cout << e[i].src+1 << " " << e[i].dst+1 << endl;
	}
	
	return 0;
}