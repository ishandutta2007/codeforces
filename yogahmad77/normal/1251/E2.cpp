#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> p(n), m(n);
		for(int i = 0; i < n; i++) cin >> m[i] >> p[i];
		vector<vector<int>> ve(n);
		for(int i = 0; i < n; i++) ve[m[i]].pb(i);
		priority_queue<int, vector<int>, greater<int>> pq;
		long long jaw = 0;
		int ada = 0, hit = n;
		for(int i = n - 1; i >= 0; i--){
			for(int j : ve[i]) pq.push(p[j]);
			hit -= sz(ve[i]);
			while(hit + ada < i){
				jaw += pq.top();
				pq.pop();
				ada += 1;
			}
		}
		cout << jaw << '\n';
	}
}