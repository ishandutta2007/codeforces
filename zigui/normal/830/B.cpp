#include<stdio.h>
#include<set>
#include<assert.h>
#include<queue>
#include<assert.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const double EPS = 1e-8;
const double PI = acos(-1);

const int MX = 1<<17;

int D[MX], E[MX];
vector<int> T[MX];

struct Tree{
	int t[MX];
	void update(int x, int v){
		while(x < MX) t[x] += v, x += x&-x;
	}
	int read(int x){
		int r = 0;
		while(x)r += t[x], x -= x&-x;
		return r;
	}
} tree;

int N;
int dist(int s, int e){
	if( e >= s ) return e-s;
	else return e+N-s;
}

int cards(int s, int e){
	if( e >= s ) return tree.read(e) - tree.read(s);
	else return tree.read(N) - tree.read(s) + tree.read(e);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);
	for(int i = 1; i <= N; i++){
		T[D[i]].push_back(i);
		tree.update(i, 1);
	}
	int cur = 0;
	ll ans = 0;
	for(int i = 1; i <= 100000; i++){
		if( T[i].empty() ) continue;
		int nxt = T[i][0];
		for(int c : T[i]) if(dist(cur, c) > dist(cur, nxt) ) nxt = c;
		ans += cards(cur, nxt);
		for(int c : T[i]) tree.update(c, -1);
		cur = nxt;
	}
	printf("%lld\n", ans);
}