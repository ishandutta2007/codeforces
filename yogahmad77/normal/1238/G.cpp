#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()

template <typename T>
void cetak(T t){cout << t << ']' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}

#define debug(x...) cout<< '[' << #x << "] = ["; cetak(x) 
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
#define MOD 1000000007 

const int mx = 5e5 + 10;

int lazy[mx * 4], mini[mx * 4];

void build(int idx, int l, int r, vector<int>&t, vector<int>&ve, int xx){
	lazy[idx] = 0;
	if(l == r){
		mini[idx] = t[ve[l]] + xx;
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * idx, l, mid, t, ve, xx);
	build(2 * idx + 1, mid + 1, r, t, ve, xx);
	mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
}

void upd(int idx, int l, int r, int fl, int fr, int val){
	if(fl > r || fr < l)
		return;
	if(fl <= l && r <= fr){
		mini[idx] -= val;
		lazy[idx] += val;
		return;
	}
	if(lazy[idx] > 0){
		lazy[idx * 2] += lazy[idx];
		mini[idx * 2] -= lazy[idx];
		lazy[idx * 2 + 1] += lazy[idx];
		mini[idx * 2 + 1] -= lazy[idx];
		lazy[idx] = 0;
	}
	int mid = (l + r) >> 1;
	upd(2 * idx, l, mid, fl, fr, val);
	upd(2 * idx + 1, mid + 1, r, fl, fr, val);
	mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
}

int cari(int idx, int l, int r, int fl, int fr){
	if(fl > r || fr < l)
		return 2e9;
	if(fl <= l && r <= fr)
		return mini[idx];
	
	if(lazy[idx] > 0){
		lazy[idx * 2] += lazy[idx];
		mini[idx * 2] -= lazy[idx];
		lazy[idx * 2 + 1] += lazy[idx];
		mini[idx * 2 + 1] -= lazy[idx];
		lazy[idx] = 0;
	}
	int mid = (l + r) >> 1;
	return min(cari(2 * idx, l, mid, fl, fr), cari(2 * idx + 1, mid + 1, r, fl, fr));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while(q--){
		int n, m, c, c0;
		cin >> n >> m >> c >> c0;
		vector<int> t(n), a(n), b(n);
		for(int i = 0; i < n; i++){
			cin >> t[i] >> a[i] >> b[i];
		}
		if(c0 >= m){
			cout << 0 << '\n';
			continue;
		}
		if(n == 0){
			cout << -1 << '\n';
			continue;
		}
		vector<int> ve(n);
		iota(ALL(ve), 0);
		sort(ALL(ve), [&](int x, int y){
			if(t[x] == t[y])
				return b[x] > b[y];
			return t[x] < t[y];
		});
		int idx = -1;
		build(1, 0, n - 1, t, ve, c - 1);
		upd(1, 0, n - 1, 0, n - 1, c0 - 1);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq, pq1;
		long long jaw = 0;
		while(c0 < m){
			// for(int i = 0; i < n; i++)
			// 	cout << cari(1, 0, n - 1, i, i) << ' ';
			// cout << endl;
			while(idx + 1 < n && t[ve[idx + 1]] <= c0){
				idx += 1;
				// debug("masuk ", ve[idx]);
				pq.push({b[ve[idx]], idx});
			}
			if(pq.empty() && pq1.empty())
				break;
			// debug(sz(pq1));
			if(pq.empty() || (!pq1.empty() && pq1.top().f <= pq.top().f)){
				int now = pq1.top().s; pq1.pop();
				int mini = cari(1, 0, n - 1, now, n - 1);
				// debug(mini);
				mini = min(mini, a[ve[now]]);
				mini = min(mini, m - c0);
				if(idx + 1 < n){
					mini = min(mini, t[ve[idx + 1]] - c0);
				}
				if(mini == 0) continue;
				upd(1, 0, n - 1, now, n - 1, mini);
				jaw = jaw + 1LL * mini * b[ve[now]];
				c0 += mini;
				a[ve[now]] -= mini;
				// debug(c0, ve[now], now, mini, jaw);
				pq1.push({b[ve[now]], now});
				continue;
			}
			// if(!pq1.empty()){
				// debug(pq.top().f, pq1.top().f);
			// }
			int now = pq.top().s; pq.pop();
			int mini = cari(1, 0, n - 1, now, n - 1);
			// debug(mini);
			mini = min(mini, a[ve[now]]);
			mini = min(mini, m - c0);
			if(idx + 1 < n){
				mini = min(mini, t[ve[idx + 1]] - c0);
			}
			upd(1, 0, n - 1, now, n - 1, mini);
			jaw = jaw + 1LL * mini * b[ve[now]];
			c0 += mini;
			a[ve[now]] -= mini;
			// debug(c0, ve[now], now, mini, jaw);
			pq1.push({b[ve[now]], now});
		}
		if(c0 >= m){
			cout << jaw << '\n';
			continue;
		}
		cout << -1 << '\n';
	}

}