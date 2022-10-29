#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MAXN=100000+10;
const int SIZE=320;

vector<int> S[MAXN], big, bel[MAXN];
int is[SIZE][MAXN], lid[MAXN];
LL sum[MAXN], add[MAXN], a[MAXN];
int n, m, q;

void init() {
	fill(lid, lid+m, -1); fill(sum, sum+m, 0); fill(add, add+m, 0);
	memset(is, 0, sizeof(is)); big.clear();
	for (int i=0; i<n; i++) bel[i].clear();
	for (int i=0; i<m; i++) S[i].clear();
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i=0; i<n; i++) scanf("%I64d", &a[i]);
	init();
	for (int i=0, k, x; i<m; i++) {
		scanf("%d", &k);
		while (k--) {
			scanf("%d", &x); x--;
			S[i].push_back(x);
			sum[i]+=(LL)a[x];
			bel[x].push_back(i);
		}
		if ((int)S[i].size()>SIZE) {
			lid[i]=big.size();
			big.push_back(i);
		}
	}
	for (int i=0; i<(int)big.size(); i++) {
		int x=big[i];
		for (int j=0; j<(int)S[x].size(); j++) {
			int y=S[x][j];
			for (int k=0; k<bel[y].size(); k++) 
				is[i][bel[y][k]]++;
		}
	}
	fill(a, a+n, 0);
	while (q--) {
		char op[10]; scanf("%s", op);
		if (op[0]=='+') {
			int k, x; scanf("%d%d", &k, &x); k--;
			if (lid[k]==-1) {
				for (int i=0; i<(int)S[k].size(); i++) a[S[k][i]]+=x;
				for (int i=0; i<(int)big.size(); i++) {
					sum[big[i]]+=(LL)x*is[i][k];
				}
			}
			else {
				add[k]+=x;
			}
		}
		else if (op[0]=='?') {
			int k; scanf("%d", &k); k--;
			LL ans=sum[k];
			for (int i=0; i<(int)big.size(); i++) {
				ans+=(LL)is[i][k]*add[big[i]];
			}
			if (lid[k]==-1) {
				for (int i=0; i<(int)S[k].size(); i++) ans+=a[S[k][i]];
			}
			printf("%I64d\n", ans);
		}
	}
	return 0;
}