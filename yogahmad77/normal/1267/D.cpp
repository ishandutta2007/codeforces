#include "bits/stdc++.h"
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
const int mx = 270;
int n, a[mx], b[mx];

vector<int> g[mx];

int ada[mx], sudah[mx], ct[mx];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++){
			a[i] *= 2;
			int x;
			cin >> x;
			a[i] += x;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++){
			b[i] *= 2;
			int x;
			cin >> x;
			b[i] += x;
		}
	}
	ada[7] = 1;
	sudah[1] = 1;
	ct[1] = 1;
	while(1){
		bool change = 0;
		for(int i = 1; i <= n; i++){
			if(sudah[i]) continue;
			if(a[i] == 0) continue;
			if(ada[a[i]]){
				g[ada[a[i]]].push_back(i);
				ct[i] = 1;
				ada[a[i] & b[i]] = i;
				sudah[i] = 1;
				change = 1;
			}
		}
		if(change) continue;
		for(int i = 1; i <= n; i++){
			if(sudah[i]) continue;
			if(a[i] == 0) continue;
			if(__builtin_popcount(a[i]) == 2){
				int ya = 1;
				for(int j : {1, 2, 4}){
					if(!(j & a[i])) continue;
					if(!ada[j]) ya = 0;
				}
				if(!ya) continue;
				ct[i] = 0;
				ada[a[i]] = i;
				change = 1;
				sudah[i] = 1;
				for(int j : {1, 2, 4}){
					if(!(j & a[i])) continue;
					g[ada[j]].push_back(i);
				}
				break;
			}
		}
		if(!change) break;
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			sudah[i] = 1;
		}
		if(!sudah[i]){
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	for(int i = 1; i <= n; i++) cout << ct[i] << ' ';
	cout << endl;
	vector<pair<int, int>> ans;
	for(int i = 1; i <= n; i++) for(int j : g[i]) ans.pb({i, j});
	cout << sz(ans) << endl;
	for(auto i : ans) cout << i.f << ' ' << i.s << '\n';
}