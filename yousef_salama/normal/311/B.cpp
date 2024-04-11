#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXP = 105;

int n, m, p, d[MAXN], hi, t[MAXN];
long long sum[MAXN];

long long dp[MAXN], dp_prev[MAXN];

vector < pair <long long, long long> > lower_hull;
long long eval(int line, int i){
	return lower_hull[line].first * i + lower_hull[line].second;
}

int main(){
	scanf("%d %d %d", &n, &m, &p);
	for(int i = 1; i < n; i++)
		scanf("%d", &d[i]);

	for(int i = 1; i < n; i++)
		d[i] += d[i - 1];

	long long r = 0;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &hi, &t[i]);
		hi--;

		/*if(t[i] < d[hi]){
			r += d[hi] - t[i];
			t[i] = d[hi];
		}*/

		t[i] -= d[hi];
		t[i] = -t[i];
	}
	sort(t, t + m);

	for(int i = 0; i <= m; i++){
		if(i == 0)sum[i] = 0;
		else sum[i] = sum[i - 1] + t[i - 1];
	}

	for(int pr = 0; pr <= p; pr++){
		if(pr == 0){
			for(int i = 0; i <= m; i++){
				if(i == 0)dp[i] = 0;
				else dp[i] = 1LL << 60;
			}
		}else{
			lower_hull.clear();

			int j = 0;
			for(int i = 0; i <= m; i++){
				if(i == 0)dp[i] = 0;
				else{
					while(j + 1 < lower_hull.size() && eval(j + 1, i) < eval(j, i))
						j++;
					/*
					dp[i] = 1LL << 60;
					for(int k = 0; k < i; k++)
						dp[i] = min(dp[i], dp_prev[k] - sum[k] - 1LL * i * t[k] + 1LL * k * t[k]);
					dp[i] = sum[i] + dp[i];
					*/

					dp[i] = sum[i] + eval(j, i);
				}
				if(i < m){
					pair <long long, long long> l = {-t[i], dp_prev[i] - sum[i] + 1LL * i * t[i]};
					if(!lower_hull.empty() && lower_hull.back().first == l.first)continue;

					while(lower_hull.size() >= j + 2){
						pair <long long, long long> l1 = lower_hull.back();
						lower_hull.pop_back();
						pair <long long, long long> l2 = lower_hull.back();

						double x1 = 1.0 * (l1.second - l2.second) / (l2.first - l1.first);
						double x2 = 1.0 * (l.second - l1.second) / (l1.first - l.first);
						if(x1 < x2){
							lower_hull.push_back(l1);
							break;
						}
					}

					lower_hull.push_back(l);

					/*cout << i << ':';
					for(int k = 0; k < lower_hull.size(); k++)
						cout << lower_hull[k].first << ',' << lower_hull[k].second << ' ';
					cout << endl;*/
				}
			}
		}

		/*
		for(int i = 0; i <= m; i++)
			cout << dp[i] << ' ';
		cout << endl;
		*/
		memcpy(dp_prev, dp, sizeof dp);
	}

	printf("%I64d\n", dp[m] + r);

	return 0;
}