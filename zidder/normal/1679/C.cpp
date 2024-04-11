#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 100005;

int STx[4*N];
int STy[4*N];

int n;
void insrt(int* ST, int x, int vl, int l=0, int r=-1, int v=1){
	if (r == -1) r=n;
	if (l + 1 == r) {
		ST[v] = vl;
		return;
	}
	int m = (l + r) / 2;
	if (x < m) insrt(ST, x, vl, l, m, 2*v);
	else insrt(ST, x, vl, m, r, 2*v+1);
	ST[v] = ST[2*v] + ST[2*v+1];
}

int qry(int* ST, int ql, int qr, int l=0, int r=-1, int v=1){
	if (r==-1)r=n;
	if (ql >= r || qr <= l) return 0;
	if (l >= ql && qr >= r) return ST[v];
	int m = (l + r) / 2;
	return qry(ST, ql, qr, l, m, 2*v) + qry(ST, ql, qr, m, r, 2*v+1);
}

void solve(int test_ind){
	cin >> n;
	int q;
	cin >> q;
	vector<int> X(n), Y(n);
	for (int i=0;i<q;++i){
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			if (X[x] == 0) insrt(STx, x, 1);
			X[x]++;
			if (Y[y] == 0) insrt(STy, y, 1);
			Y[y]++;
		}
		if (t == 2){
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			X[x]--;
			if (X[x] == 0) insrt(STx, x, 0);
			Y[y]--;
			if (Y[y] == 0) insrt(STy, y, 0);
		}
		if (t == 3){
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1--;y1--;
			if (qry(STx, x1, x2) == x2 - x1 || qry(STy, y1, y2) == y2 - y1) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}