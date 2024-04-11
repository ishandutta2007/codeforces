#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<int> gap;
	if(s[0] == '#')	gap.emplace_back(0);
	for(int i=0;i<s.size();i++) {
		int j = i;
		while(j + 1 < s.size() && s[i] == s[j + 1])	j ++;
		gap.emplace_back(j - i + 1);
		i = j;
	}
	if(s.back() == '#')	gap.emplace_back(0);
	if(gap.size() == 1) {
		cout << 0 << endl;
		return 0;
	}
	int x = 1e9;
	for(int i=0;i<gap.size();i+=2) {
		if(i == 0 || i + 1 == gap.size())
			x = min(x, gap[i]);
		else
			x = min(x, gap[i] - 1);
	} 
	for(int d=x;d>=0;d--) {
		if(d == 0) {
			bool ok = true;
			for(int i=0;i<gap.size();i+=2) {
				if(i == 0 || i + 1 == gap.size())
					ok &= (gap[i] == 0);
				else
					ok &= (gap[i] == 1);
			}
			if(!ok)	break;
			cout << gap.size() / 2 << '\n';
			for(int i=1;i<gap.size();i+=2)
				cout << gap[i] << ' ';
			cout << '\n';
			return 0;
		}
		else if(d == 1) {
			bool ok = true;
			for(int i=0;i<gap.size();i+=2) {
				if(i == 0 || i + 1 == gap.size())
					ok &=  ((gap[i] - d) % 2 == 0);
				else
					ok &= ((gap[i] - 1 - d) % 2 == 0);
			}
			if(!ok)	continue;
			vector<int> res;
			for(int i=0;i<gap.size();i++) {
				if(i % 2 == 0) {
					int diff = gap[i];
					if(i == 0 || i + 1 == gap.size())
						diff -= d;
					else
						diff -= (d + 1);
					if(diff & 1) {
						diff -= 3;
						res.emplace_back(2);
					}
					while(diff) {
						diff -= 2;
						res.emplace_back(1);
					}
				}
				else {
					res.emplace_back(gap[i] + d);
				}
			}
			cout << res.size() << '\n';
			for(int i=0;i<res.size();i++)
				cout << res[i] << ' ';
			cout << endl;
			return 0;
		}
		else {
			bool ok = true;
			for(int i=0;i<gap.size();i+=2) {
				if(i == 0 || i + 1 == gap.size())
					ok &= (d != gap[i] - 1);
				else
					ok &= (d != gap[i] - 2);
			}
			if(!ok)	continue;
			vector<int> res;
			for(int i=0;i<gap.size();i++) {
				if(i % 2 == 0) {
					int diff = gap[i];
					if(i == 0 || i + 1 == gap.size())
						diff -= d;
					else
						diff -= (d + 1);
					if(diff & 1) {
						diff -= 3;
						res.emplace_back(2);
					}
					while(diff) {
						diff -= 2;
						res.emplace_back(1);
					}
				}
				else {
					res.emplace_back(gap[i] + d);
				}
			}
			cout << res.size() << '\n';
			for(int i=0;i<res.size();i++)
				cout << res[i] << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}