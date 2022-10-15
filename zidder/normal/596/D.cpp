// https://codeforces.com/problemset/problem/596/D

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

pair<double, double> dp[2001][2001][2][2]; // [l][r][l_in][r_in] -> (total distance inside, probability of l_in, r_in)
pair<int, int> lr[2001];
void solve(int test_ind){
	int n;
	cin >> n;
	int h;
	cin >> h;
	long double p;
	cin >> p;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	for (int i=0;i<n;++i){
		int j = i, prv=a[i];
		for (;j<n && a[j] - prv < h;++j){prv=a[j];}
		for (int k=i;k<j;++k) lr[k] = {i, j-1};
		i = j - 1;
	}
	for (int i=0;i<n;++i) {
		dp[i][i][1][0] = {0, 1-p};
		dp[i][i][0][1] = {0, p};
	}
	for (int d=1;d<n;++d){
		for (int i=0;i<n-d;++i){
			// [i, i+d]
			long double p1;
			// choose right
			{
				// in
				p1 = p / 2;
				int lft = lr[i+d].first;
				if (lft <= i){
					dp[i][i+d][0][1].second += p1;
					dp[i][i+d][0][1].first += (a[i+d] - a[i]) * p1;
					// [1][1] = 0
				} else {
					long double D, D1, D2, P;
					D1 = dp[i][lft-1][0][1].first + (a[i+d] - a[lft] + h);
					D2 = dp[i][lft-1][0][0].first + (a[i+d] - a[lft] + min(h * 2, a[lft] - a[lft-1]));
					D = dp[i][lft-1][0][1].second * D1 + dp[i][lft-1][0][0].second * D2;
					P = dp[i][lft-1][0][1].second + dp[i][lft-1][0][0].second;
					if (P > 1e-9) D /= P;
					dp[i][i+d][0][1].first  += D * P * p1;
					dp[i][i+d][0][1].second += p1 * P;

					D1 = dp[i][lft-1][1][1].first + (a[i+d] - a[lft] + h);
					D2 = dp[i][lft-1][1][0].first + (a[i+d] - a[lft] + min(h * 2, a[lft] - a[lft-1]));
					D = dp[i][lft-1][1][1].second * D1 + dp[i][lft-1][1][0].second * D2;
					P = dp[i][lft-1][1][1].second + dp[i][lft-1][1][0].second;
					if (P > 1e-9) D /= P;
					dp[i][i+d][1][1].first  += D * P * p1;
					dp[i][i+d][1][1].second += p1 * P;
				}
				// out
				p1 = (1 - p) / 2;
				{
					long double D, D1, D2, P;
					D1 = dp[i][i+d-1][0][0].first + min(h, a[i+d] - a[i+d-1]);
					D2 = dp[i][i+d-1][0][1].first;
					D = dp[i][i+d-1][0][0].second * D1 + dp[i][i+d-1][0][1].second * D2;
					P = dp[i][i+d-1][0][0].second + dp[i][i+d-1][0][1].second;
					if (P > 1e-9) D /= P;
					dp[i][i+d][0][0].first += D * P * p1;
					dp[i][i+d][0][0].second += p1 * P;

					D1 = dp[i][i+d-1][1][0].first + min(h, a[i+d] - a[i+d-1]);
					D2 = dp[i][i+d-1][1][1].first;
					D = dp[i][i+d-1][1][0].second * D1 + dp[i][i+d-1][1][1].second * D2;
					P = dp[i][i+d-1][1][0].second + dp[i][i+d-1][1][1].second;
					if (P > 1e-9) D /= P;
					dp[i][i+d][1][0].first += D * P * p1;
					dp[i][i+d][1][0].second += p1 * P;
				}

			}
			// choose left
			{
				// in
				p1 = (1 - p) / 2;
				int rght = lr[i].second;
				if (rght >= i+d){
					dp[i][i+d][1][0].second += p1;
					dp[i][i+d][1][0].first += (a[i+d] - a[i]) * p1;
					// [1][1] = 0
				} else {
					long double D, D1, D2, P;
					D1 = dp[rght+1][i+d][1][0].first + (a[rght] - a[i] + h);
					D2 = dp[rght+1][i+d][0][0].first + (a[rght] - a[i] + min(h * 2, a[rght+1] - a[rght]));
					D = dp[rght+1][i+d][1][0].second * D1 + dp[rght+1][i+d][0][0].second * D2;
					P = dp[rght+1][i+d][1][0].second + dp[rght+1][i+d][0][0].second;
					if (P > 1e-9) D /= P;
					dp[i][i+d][1][0].first  += D * p1 * P;
					dp[i][i+d][1][0].second += p1 * P;

					D1 = dp[rght+1][i+d][1][1].first + (a[rght] - a[i] + h);
					D2 = dp[rght+1][i+d][0][1].first + (a[rght] - a[i] + min(h * 2, a[rght+1] - a[rght]));
					D = dp[rght+1][i+d][1][1].second * D1 + dp[rght+1][i+d][0][1].second * D2;
					P = dp[rght+1][i+d][1][1].second + dp[rght+1][i+d][0][1].second;
					if (P > 1e-9) D /= P;
					dp[i][i+d][1][1].first  += D * P * p1;
					dp[i][i+d][1][1].second += p1 * P;
				}
				// out
				p1 = p / 2;
				{
					long double D, D1, D2, P;
					D1 = dp[i+1][i+d][0][0].first + min(h, a[i+1] - a[i]);
					D2 = dp[i+1][i+d][1][0].first;
					D = dp[i+1][i+d][0][0].second * D1 + dp[i+1][i+d][1][0].second * D2;
					P = dp[i+1][i+d][0][0].second + dp[i+1][i+d][1][0].second;
					if (P > 1e-9) D /= P;
					dp[i][i+d][0][0].first += D * P * p1;
					dp[i][i+d][0][0].second += p1 * P;

					D1 = dp[i+1][i+d][0][1].first + min(h, a[i+1] - a[i]);
					D2 = dp[i+1][i+d][1][1].first;
					D = dp[i+1][i+d][0][1].second * D1 + dp[i+1][i+d][1][1].second * D2;
					P = dp[i+1][i+d][0][1].second + dp[i+1][i+d][1][1].second;
					if (P > 1e-9) D /= P;
					dp[i][i+d][0][1].first += D * P * p1;
					dp[i][i+d][0][1].second += p1 * P;
				}
			}
			if (dp[i][i+d][0][0].second > 1e-9) dp[i][i+d][0][0].first /= dp[i][i+d][0][0].second;
			if (dp[i][i+d][0][1].second > 1e-9) dp[i][i+d][0][1].first /= dp[i][i+d][0][1].second;
			if (dp[i][i+d][1][0].second > 1e-9) dp[i][i+d][1][0].first /= dp[i][i+d][1][0].second;
			if (dp[i][i+d][1][1].second > 1e-9) dp[i][i+d][1][1].first /= dp[i][i+d][1][1].second;
		}
	}


	long double ans = 0;
	for (int rin=0;rin<=1;++rin){
		for (int lin=0;lin<=1;++lin){
			// cout << lin << " " << rin << " " << dp[0][n-1][lin][rin].first << " " << dp[0][n-1][lin][rin].second << endl;
			ans += dp[0][n-1][lin][rin].second * (dp[0][n-1][lin][rin].first + (1-rin) * h + (1-lin) * h);
		}
	}
	printf("%.13Lf\n", ans);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}