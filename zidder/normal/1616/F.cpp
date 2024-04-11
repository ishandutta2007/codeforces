#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> inv3 = {0, 1, 2};

struct S{
	int ind;
	int k;
	int v1, v2;
	S(int ind, int a, int b, int c): ind(ind), k(a), v1(b), v2(c){}

	void apply(vector<int>& v){
		if (ind == 0){
			swap(v[k], v[v1]);
		} else if (ind == 1) {
			(v[k] *= v1) %= 3;
		} else {
			(v[v1] += v[k] * v2) %= 3;
		}
	}
};

int gauss (vector < vector<int> > a, vector<int> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;
 
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (a[i][col] > a[sel][col]){
				sel = i;
			}
		if (a[sel][col] == 0)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) {
				int c = (a[i][col] * inv3[a[row][col]]) % 3;
				if (c) for (int j=col; j<=m; ++j)
					(a[i][j] += 3 - a[row][j] * c % 3) %= 3;
			}
		++row;
	}
 
	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] * inv3[a[where[i]][i]] % 3;
	for (int i=0; i<n; ++i) {
		int sum = 0;
		for (int j=0; j<m; ++j){
			(sum += ans[j] * a[i][j]) %= 3;
		}
		if (sum%3 != a[i][m])
			return 0;
	}
 
	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return -1;
	return 1;
}

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	// 32 * 63 edges at most
	vector<pair<pair<int, int>, int> > c(m);
	vector<vector<int> > g(n, vector<int>(n, 0));
	vector<vector<int> > mp(n, vector<int>(n, 0));
	int cind = 0;
	// [a][b] == [a][c] == [b][c] || [a][b], [a][c] and [b][c] are pairwise distinct
	for (int i=0;i<m;++i){
		int ai, bi, ci;
		scanf("%d%d%d", &ai, &bi, &ci);
		ai--;bi--;
		c[i] = {{ai, bi}, ci};
		g[ai][bi] = ci;
		g[bi][ai] = ci;
		if (ci == -1) mp[ai][bi] = mp[bi][ai] = cind++;
	}

	vector<vector<int> > triangles;
	for (int i=0;i<n;++i){
		for (int j=i+1;j<n;++j){
			for (int k=j+1;k<n;++k){
				if (g[i][j] && g[i][k] && g[j][k]){
					vector<int> v(cind, 0);
					bool any = false;
					int o = 0;
					if (g[i][j] == -1){
						any = true;
						v[mp[i][j]] = 1;
					} else {
						(o += 3 - g[i][j]) %= 3;
					}
					if (g[i][k] == -1){
						any = true;
						v[mp[i][k]] = 1;
					} else {
						(o += 3 - g[i][k]) %= 3;
					}
					if (g[k][j] == -1){
						any = true;
						v[mp[k][j]] = 1;
					} else {
						(o += 3 - g[k][j]) %= 3;
					}
					if (any){
						v.push_back(o);
						triangles.push_back(v);
					} else {
						if (o) {cout << -1 << endl; return;}
					}
				}
			}
		}
	}

	// num triangles X cind @ edges = b
	// gauss

	vector<int> ans(cind, 0);
	if (!triangles.empty() && 0 == gauss(triangles, ans)){
		cout << -1 << endl;
		return;
	}
	for (int i=0;i<c.size();++i){
		if (c[i].second == -1){
			c[i].second = ans[mp[c[i].first.first][c[i].first.second]];
			if (c[i].second == 0) c[i].second = 3;
		}
	}
	for (auto &p: c)
		printf("%d ", p.second);
	printf("\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}