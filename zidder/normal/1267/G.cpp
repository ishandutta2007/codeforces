#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define dbl long double
#define ll long long

void solve(int test_ind){
	int n, x;
	cin >> n >> x;
	vector<int> cs;
	int sm = 0;
	for(int i = 0; i < n; ++i){
		int c;
		cin >> c;
		cs.push_back(c);
		sm += c;
	}
	vector<vector<dbl> > C(n + 1,  vector<dbl> (n + 1, 0));
	for(int i = 0;i<=n;++i){
		C[i][0] = 1;
		for(int j=1;j<=i;++j){
			C[i][j] = (C[i][j-1] * (i - j + 1)) / j;
		}
	}
	vector<vector<bool> > randm(n + 1, vector<bool>(10001, false));
	randm[n][sm] = true;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= sm; ++j){
			// for one (sm - j) / (n - i)
			// for rand A = (n - i) / n x + i / n * (A + x / 2)
			// (n-i) / n * A = x ((n-i)/n + i / 2n)
			// A = x (1 + i/2(n-i))
			// A = x/2 (2n-i) / (n-i)
			// (s - j) * 2(n-i) <=> x (2n-i) (n-i)
			ll forone = 1, forrand = 1;
			forone *= (sm - j);
			forone *= 2 * (n - i);
			forrand *= x;
			forrand *= (2 * n - i);
			forrand *= (n - i);
			if (forone <= forrand)
				randm[i][j] = true;
		}
	}
	vector<vector<dbl> > kn(n + 1, vector<dbl>(10001, 0));
	kn[0][0] = 1;
	for(int c: cs)
		for(int j=n;j>=0;j--)
			for (int sc=10000;sc>=0;sc--)
				if (kn[j][sc])
					kn[j + 1][sc + c] += kn[j][sc];
	dbl ans = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<=10000;++j){
			if (kn[i][j]==0)
				continue;
			dbl c = C[n][i];
			if (randm[i][j])
				ans += kn[i][j] * ((dbl)1) * (sm - j) / (n - i) / c;
			else
				ans += kn[i][j] * ((dbl)1) * x / 2 * (2 * n - i)/ (n - i) / c;
		}
	printf("%.10Lf\n", ans);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++)
		solve(i);
	return 0;
}