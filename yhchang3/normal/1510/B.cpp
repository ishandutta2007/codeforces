#include<bits/stdc++.h>
using namespace std;

const int N = 1030, inf = 1e9;
int vl[N], vr[N], fl[N], fr[N], pre[N], s, t, h, slk[N], a[N][N], n, hl[N], hr[N], q[N];

int check(int i) {
	if (vl[i] = 1, fl[i] != -1) {
		q[t ++] = fl[i]; vr[fl[i]] = 1;
		return 1;
	}
	while(i != -1)	swap(i, fr[fl[i] = pre[i]]);
	return 0;
}
void bfs(int s) {
	for(int i=1;i<=n;i++)
		vl[i] = vr[i] = 0, slk[i] = inf;
	for(vr[q[h=0]=s]=t=1;;) {
		for(long long d;h < t;) {
			for(int i=1,j=q[h++];i<=n;i++) {
				if(!vl[i] && slk[i] >= (d = hl[i] + hr[j] - a[i][j])) {
					if(pre[i] = j, d)	slk[i] = d;
					else if(!check(i))	return;
				}
			}
		}
		long long d = inf;
		for(int i=1;i<=n;i++)
			if(!vl[i] && d > slk[i])	d = slk[i];
		for(int i=1;i<=n;i++) {
			if(vl[i])	hl[i] += d;
			else	slk[i] -=d;
			if(vr[i])	hr[i] -= d;
		}
		for(int i=1;i<=n;i++)
			if(!vl[i] && !slk[i] && !check(i))	return;
	}
}
long long solve() {
	for(int i=1;i<=n;i++)	fl[i] = fr[i] = -1, hr[i] = 0;
	for(int i=1;i<=n;i++)	hl[i] = *max_element(a[i] + 1, a[i] + n + 1);
	for(int i=1;i<=n;i++)	bfs(i);
	long long ans = 0;
	for(int i=1;i<=n;i++)
		if(a[i][fl[i]])
			ans += a[i][fl[i]];
		else
			fl[i] = 0;
	return ans;
}

int rev[N];
int cnt[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int d;
	cin >> d >> n;
	map<int,int> m;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		int x = 0;
		for(int j=0;j<d;j++) {
			x <<= 1;
			x |= (s[j] == '1');
		}
		m[x] = 0;
	}
	int stp = 1;
	for(auto it=m.begin();it!=m.end();it++) {
		int x = it -> first;
		cnt[stp] = __builtin_popcount(x);
		rev[stp] = it -> first, it ->second = stp++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j] = 0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) {
			int x = rev[i], y = rev[j];
			if((x | y) == y)
				a[i][j] = cnt[i];
		}
	solve();
	for(int i=1;i<=n;i++)
		fr[i] = 0;
	for(int i=1;i<=n;i++)
		if(fl[i] != 0)
			fr[fl[i]] = i;
	vector<char> res;
	for(int i=1;i<=n;i++)
		if(fr[i] == 0) {
			if(res.size()) {
				res.emplace_back('R');
			}
			for(int j=0;j<d;j++)
				if((rev[i] >> j) & 1)
					res.emplace_back('0' + d - 1 - j);		
			int z = i;
			while(fl[z]) {
				int y = rev[z] ^ rev[fl[z]];
				for(int i=0;i<d;i++)
					if((y >> i) & 1)
						res.emplace_back('0' + d - 1 - i);
				z = fl[z];
			}
		}
	cout << res.size() << '\n';
	for(char c : res)
		cout << c << ' ';
	cout << '\n';
	
}