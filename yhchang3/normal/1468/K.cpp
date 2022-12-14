#include<bits/stdc++.h>
using namespace std;

map<char,int> dir = {
	{'R', 0},
	{'U', 1},
	{'L', 2},
	{'D', 3}
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int,int> go(int x,int y,char op) {
	return make_pair(x + dx[dir[op]], y + dy[dir[op]]); 
}

string s;

bool check(int ox, int oy) {
	int x = 0, y = 0;
	for(char c:s) {
		auto [nx, ny] = go(x, y, c);
		if(nx != ox || ny != oy)
			x = nx, y = ny;
	}
	return x == 0 && y == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> s;
		int x = 0, y = 0;
		bool ok = false;
		for(int i=0;i<s.size();i++) {
			tie(x, y) = go(x, y, s[i]);
			if(check(x, y)) {
				ok = true;
				cout << x << ' ' << y << '\n';
				break;
			}
		}
		if(!ok)
			cout << 0 << ' ' << 0 << '\n';
	}
}