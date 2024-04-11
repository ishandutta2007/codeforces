#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1523, inf = 1e9;
const ll INF = 1e18;


int n, s, m, k, cnt, a[N], b[N];
int pre[N], dp[N][N], DP[N];
bool was[N];
vector< pii > tmp, arr;
deque< int > dq[N];
bool check(int x){
	for(int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + (a[i] <= x);
	for(int i = 0; i < N; i++)
		while(!dq[i].empty())
			dq[i].pop_back();
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dp[i][j] = -inf;
	for(int i = 0; i < N; i++)
		DP[i] = -inf;
	
	int res = -inf;
	for(int i = 0; i < arr.size(); i++){
		int l = arr[i].s;
		int r = arr[i].f;
		//cerr << l << " " << r << endl;
		dp[i][1] = pre[r] - pre[l - 1];
		
		for(int j = 1; j < N; j++)
			while(!dq[j].empty() && arr[dq[j].front()].f < l){
				DP[j] = max(DP[j], dp[dq[j].front()][j]);
				dq[j].pop_front();
			}
		
		for(int j = 2; j < N; j++){
			dp[i][j] = max(dp[i][j], DP[j - 1] + pre[r] - pre[l - 1]);
			if(!dq[j - 1].empty())
            	dp[i][j] = max(dp[i][j], dp[dq[j - 1].front()][j - 1] + pre[r] - pre[arr[dq[j - 1].front()].f]);
		}

		for(int j = 1; j < N; j++){
			while(!dq[j].empty() && dp[dq[j].front()][j] - pre[arr[dq[j].front()].f] <= dp[i][j] - pre[r])
				dq[j].pop_front();
			dq[j].push_back(i);
		}
		for(int j = 1; j <= m; j++){
        	//cerr << i << " " << j << " " << dp[i][j] << endl;
        	res = max(res, dp[i][j]);
        }
	}	
    //cerr << res << endl;
	return res >= k;
}

int main(){
	cin >> n >> s >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
    for(int i = 1; i <= s; i++){
		int l, r;
		cin >> l >> r;
		tmp.pb({l, -r});
		for(int j = l; j <= r; j++)
			was[j] = 1;
	}
	for(int i = 1; i <= n; i++)
		if(was[i])
			cnt++;
	if(cnt < k){
		cout << -1;
		return 0;
	}
	sort(tmp.begin(), tmp.end());
	for(int i = 0, mx = -1; i < tmp.size(); i++){
		int l = tmp[i].f;
		int r = -tmp[i].s;
		if(r <= mx)
			continue;
		mx = r;
		arr.pb({r, l});
	}
	sort(arr.begin(), arr.end());

	//cerr << check(1);
	//return 0;
	
	sort(b + 1, b + 1 + n);
	b[n + 1] = inf + 666;
	int l = 1, r = n + 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(!check(b[m]))
			l = m + 1;	
		else
			r = m - 1;
	}
	if(l > n)
		cout << -1;
	else
		cout << b[l];
	return 0;
}