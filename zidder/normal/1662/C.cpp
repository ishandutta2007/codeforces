#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

int n, m, k;

vector<vector<int> > matmul(const vector<vector<int> >& A, const vector<vector<int> >& B) {
	vector<vector<int> > C(A.size(), vector<int>(A.size()));
	for (int i=0;i<A.size();++i){
		for (int j=0;j<A.size();++j){
			for (int t=0;t<A.size();++t) {
				(C[i][j] += A[i][t] * 1ll * B[t][j] % MOD) %= MOD;
			}
		}
	}
	return C;
}

vector<vector<int> > binpow(const vector<vector<int> > &A, int p) {
	vector<vector<int> > I(A.size(), vector<int>(A.size())), B;
	for (int i=0;i<A.size();++i) I[i][i] = 1;
	B = I;
	if (p > 1) {
		B = binpow(matmul(A, A), p>>1);
	}
	if (p&1) {
		B = matmul(B, A);
	}
	return B;
}


int trace(const vector<vector<int> >& v) {
	int ans = 0;
	for (int i=0;i<n;++i) (ans += v[i][i]) %= MOD;
	return ans;
}

void solve(int test_ind){
	cin >> n >> m >> k;
	vector<vector<int> > N(n, vector<int>(n)), I(n, vector<int>(n)), D(n, vector<int>(n));
	for (int i=0;i<n;++i) I[i][i] = 1;
	for (int i=0;i<m;++i){
		int a, b;
		scanf("%d%d", &a, &b);
		a--;b--;
		N[a][b] = 1;
		N[b][a] = 1;
		D[a][a]++;
		D[b][b]++;
	}

	vector<vector<int> > L(2 * n, vector<int>(2*n));
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j) L[i][j] = N[i][j];
		for (int j=n;j<2*n;++j) L[i][j] = (I[i][j-n] + MOD - D[i][j-n]) % MOD;
	}
	for (int i=n;i<2*n;++i){
		for (int j=0;j<n;++j){
			L[i][j] = I[i-n][j];
		}
	}
	vector<vector<int> > B(2 * n, vector<int> (2 * n));
	for (int i=0;i<n;++i){
		B[i][i] = 1;
		for (int j=0;j<n;++j)
			B[i+n][j+n] = N[i][j];
	}

	auto print = [&](vector<vector<int> > &X){
		for (int i=0;i<X.size();++i) {
			for (int j=0;j<X.size();++j){
				cout << X[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	};
	// print(B);
	// print(L);
	// Aj = A(j-1) N + A(j-2) (I-D)

	// cout << trace(II) << endl;
	cout << (trace(matmul(binpow(L, k), B)) + MOD - trace(matmul(binpow(L, k-2), B))) % MOD << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}