#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int pmx[N], pmn[N], bmx[N], bmn[N], val[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		s.insert(0, " ");
		int x = 0;
		for(int i=1;i<=n;i++) {
			if(s[i] == '+')
				x++;
			else
				x--;
			val[i] = x;
			pmx[i] = max(x, pmx[i-1]);
			pmn[i] = min(x, pmn[i-1]);
		}
		x = 0;
		bmn[n + 1] = bmx[n + 1] = 0;
		for(int i=n;i>=1;i--) {
			int v = (s[i] == '+') ? 1 : -1;
			bmx[i] = max(v + bmx[i + 1], 0);
			bmn[i] = min(v + bmn[i + 1], 0);
		}
		while(m--) {
			int l,r;
			cin >> l >> r;
			cout << max(val[l - 1] + bmx[r + 1], pmx[l - 1]) - min(val[l - 1] + bmn[r + 1], pmn[l - 1]) + 1 << '\n';
		}
	}
}