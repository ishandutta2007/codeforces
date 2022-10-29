#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN=60;
const double eps=1e-8;

vector<pair<int, double> > ret[MAXN];

bool solve(int n, int w, int m) {
	double need[MAXN], rest[MAXN];
	int times[MAXN];
	for (int i=0; i<m; i++) {
		need[i]=1.0*n*w/m;
	}
	for (int i=1; i<=n; i++) {
		times[i]=0; rest[i]=w;
	}
	for (int i=0; i<m; i++) {
		for (int j=1; j<=n; j++) {
			if (fabs(rest[j])<eps || fabs(need[i])<eps) continue;
			if (rest[j]>need[i]) {
				ret[i].push_back(make_pair(j, need[i]));
				rest[j]-=need[i]; need[i]=0; times[j]++;
			}
			else {
				ret[i].push_back(make_pair(j, rest[j]));
				need[i]-=rest[j]; rest[j]=0; times[j]++;
			}
			if (times[j]>2) return false;
		}
	}
	return true;
}

int main() {
	int n, w, m;
	scanf("%d%d%d", &n, &w, &m);
	if (solve(n, w, m)) {
		puts("YES");
		for (int i=0; i<m; i++) {
			for (int j=0; j<(int)ret[i].size(); j++) {
				printf("%d %.10f%c", ret[i][j].first, ret[i][j].second, (j==(int)ret[i].size()-1)?'\n':' ');
			}
		}
	}
	else {
		puts("NO");
	}
}