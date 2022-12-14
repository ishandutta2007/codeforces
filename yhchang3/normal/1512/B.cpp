#include<bits/stdc++.h>
using namespace std;

string s[400];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> s[i];
		vector<pair<int,int>> p;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(s[i][j] == '*')
					p.emplace_back(i, j);
		if(p[0].first == p[1].first) {
			if(p[0].first == 0)
				s[1][p[0].second] = s[1][p[1].second] = '*';
			else
				s[0][p[0].second] = s[0][p[1].second] = '*';
		}
		else if(p[0].second == p[1].second) {
			if(p[0].second == 0)
				s[p[0].first][1] = s[p[1].first][1] = '*';
			else
				s[p[0].first][0] = s[p[1].first][0] = '*';
		}
		else {
			s[p[0].first][p[1].second] = s[p[1].first][p[0].second] = '*';
		}
		for(int i=0;i<n;i++)
			cout << s[i] << '\n';
	}

}