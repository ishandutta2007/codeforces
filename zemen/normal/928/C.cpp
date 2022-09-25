#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 2001;

#define index huindex

int n;
string s[N];
int version[N];
vector<int> g[N];

vector<pair<string, int>> pg[N];
map<pair<string, int>, int> index;

int dist[N];

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
    	static char buf[100500];
    	scanf("%s%d", buf, &version[i]);
    	s[i] = string(buf);
    	int k; scanf("%d", &k);
    	for (int j = 0; j < k; j++) {
    		int cur; scanf("%s%d", buf, &cur);
    		pg[i].pb(mp(string(buf), cur));
    	}
    	index[mp(s[i], version[i])] = i;
    }
    for (int i = 0; i < n; i++) {
    	for (auto j : pg[i]) {
    		auto it = index.find(j);
    		assert(it != index.end());
    		g[i].pb(it->sc);
    	}
    }
    for (int i = 0; i < n; i++) {
    	sort(all(g[i]), [&](int a, int b) {
    		return version[a] > version[b];
    	});
    }
    set<tuple<int, int, int>> queue;
    set<string> used;
    fill_n(dist, n, inf);
    dist[0] = 0;
    queue.insert(make_tuple(dist[0], -version[0], 0));
    vector<pair<string, int>> result;
    while (!queue.empty()) {
    	int v; tie(ignore, ignore, v) = *queue.begin();
    	queue.erase(queue.begin());
    	if (used.count(s[v])) {
    		continue;
    	}
    	if (v != 0) {
    		result.emplace_back(s[v], version[v]);
    	}
    	used.insert(s[v]);
    	for (int to : g[v]) {
    		if (dist[to] > dist[v] + 1) {
    			dist[to] = dist[v] + 1;
    			queue.insert(make_tuple(dist[to], -version[to], to));
    		}
    	}
    }
    sort(all(result));
    cout << len(result) << endl;
    for (auto i : result) {
    	printf("%s %d\n", i.first.data(), i.second);
    }
    return 0;
}