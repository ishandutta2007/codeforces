#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f)) 
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, m;
struct edges {
	int u, v;
} e[N];
int f[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
bool vis[N];
void Main() {
	cin >> n >> m;
	set < int > st;
	L(i, 1, n) f[i] = i;
	L(i, 1, m) {
		cin >> e[i].u >> e[i].v;
		vis[i] = false;
	}
	int cnt = 0;
	L(i, 1, m) {
		int x = find(e[i].u);
		int y = find(e[i].v);
		if(x != y) 
			f[x] = y, vis[i] = true;
		else 
			cnt += 1, st.insert(e[i].u), st.insert(e[i].v);
	} 
	if(cnt == 3 && sz(st) == 3) {
		L(i, 1, n) f[i] = i;
		L(i, 1, m) vis[i] = false;
		L(i, 1, m) {
			if(st.find(e[i].u) != st.end() && st.find(e[i].v) != st.end()) {
				f[find(e[i].u)] = e[i].v;
				vis[i] = true;
				break;
			}
		} 
		L(i, 1, m) {
			int x = find(e[i].u);
			int y = find(e[i].v);
			if(x != y) 
				f[x] = y, vis[i] = true; 
		}
	}
	L(i, 1, m) 
		cout << vis[i];
	cout << '\n'; 
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}