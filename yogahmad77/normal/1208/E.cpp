#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 1000003

long long nilai[mx], pref[mx];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; i++){
		int l, x;
		cin >> l;
		a[i].resize(l);
		for(int j = 0; j < l; j++){
			cin >> x;
			a[i][j] = x;
		}
		if(l + l <= m){
			int maks = 0;
			for(int j = 0; j < l; j++){
				maks = max(maks, a[i][j]);
				nilai[j] += maks;
			}
			int now = l - 1;
			maks = 0;
			for(int j = m - 1; now >= 0; now--, j--){
				maks = max(maks, a[i][now]);
				nilai[j] += maks;
				// debug(j);
			}
			pref[l] += maks;
			// debug(l);
			// debug(m - l);
			// debug(maks);
			pref[m - l] -= maks;
		}
		else{
			vector<int> kiri(m), kanan(m);
			for(int j = 0; j < l; j++){
				kanan[j] = j;
			}
			for(int j = l; j < m; j++)
				kanan[j] = l - 1;
			// debug(i);
			int aa = l;
			for(int j = m - 1; j >= m - l; j--)
				kiri[j] = --aa;
			for(int j = 0; j < m - l; j++)
				kiri[j] = 0;
			// for(int j = 0; j < m; j++){
				// cout << kiri[j] << ' ' << kanan[j] << endl;
			// }
			priority_queue<pair<int, int>> pq;
			int now = -1;
			for(int j = 0; j < m; j++){
				while(now + 1 < l && now + 1 <= kanan[j]){
					now += 1;
					pq.push({a[i][now], now});
				}
				while(!pq.empty() && pq.top().s < kiri[j])
					pq.pop();
				// debug(pq.top().f);
				if(pq.top().f < 0 && (j < m - l || j >= l)){
					nilai[j] += 0;
				}
				else nilai[j] += pq.top().f;
			}
		}

	}
	long long sum = 0;
	for(int i = 0; i < m; i++){
		sum += pref[i];
		nilai[i] += sum;
		cout << nilai[i] << ' ';
	}
}