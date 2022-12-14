#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const long long inf = 1e18;
vector<pair<int,int> > e[N];
long long dist[N][4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=1,u,v,w;i<=m;i++) {
		cin >> u >> v >> w;
		e[u].emplace_back(v, w), e[v].emplace_back(u, w);
	}
	typedef pair<long long, pair<int, int>> Dtype;
	priority_queue<Dtype, vector<Dtype>, greater<Dtype>> pq;
	for(int i=1;i<=n;i++)
		for(int j=0;j<4;j++)
			dist[i][j] = inf;
	dist[1][0] = 0;
	pq.emplace(make_pair(dist[1][0], make_pair(1, 0)));
	while(!pq.empty()) {
		auto cur = pq.top();pq.pop();
		long long d = cur.first;
		int x = cur.second.first;
		int y = cur.second.second;
		if(dist[x][y] != d)	continue;
		for(auto [z, wt]:e[x])
			for(int w=0;w<4;w++) {
				if((w | y) != w)	continue;
				long long nd = d + wt;
				if(!(y & 1) && (w & 1))
					nd += wt;
				if(!(y & 2) && (w & 2))
					nd -= wt;
				if(nd < dist[z][w])
					dist[z][w] = nd, pq.emplace(make_pair(dist[z][w], make_pair(z, w)));
			}
	}
	for(int i=2;i<=n;i++)
		cout << dist[i][3] << ' ';
}