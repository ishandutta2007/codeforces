#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;
string none = "NONE", uniquee = "UNIQUE", mul = "MULTIPLE";

int calc(vector<vector<int> > &ans, int y, int x){
	int cnt = 0;
	for (int dx=-1; dx<2;dx++){
		for (int dy=-1;dy<2;dy++){
			if (dx*dx+dy*dy != 1)
				continue;
			if (dx + x >= n || dy + y >= n || dx+x<0 || dy+y<0)
				continue;
			cnt += ans[y][x] == ans[y+dy][x+dx];
		}
	}
	return cnt;
}

bool sett(vector<int> &line, int k, int v){
	k -= k%2;
	if (line[k] >= 0 && line[k] != v){
		return false;
	}
	line[k] = v;
	k++;
	if (line[k] >= 0 && line[k] != v){
		return false;
	}
	line[k] = v;
	return true;
}

pair<string, vector<vector<int> > > fun(vector<vector<int> > &init){
	vector<vector<int> > empty;
	if (n%2){
		return make_pair(none, empty);
	}

	vector<int> line(n, -1);
	for (int I=0;I<n;++I){
		for (int J=0;J<n;++J){
			int i=I, j=J;
			int elem = init[i][j];
			if (elem == -1)
					continue;
			int k, v;
			if (abs(i - j) % 2){
				i = max(I, J);
				j = min(I, J);
				k = i - j;
			} else {
				if (i + j >= n){
					i = n - 1 - i;
					j = n - 1 - j;
				}
				k = i + j;
			}
			if (j % 2)
				v = 1 - elem;
			else
				v = elem;
			if (!sett(line, k, v))
				return make_pair(none, empty);
		}
	}

	for (int i: line)
		if (i == -1)
			return make_pair(mul, empty);

	vector<vector<int> > ans;
	ans.push_back(line);

	for (int i=1;i<n;++i){
		ans.push_back(vector<int>(n, -1));
		for (int j=0;j<n;++j){
			int cnt = calc(ans, i-1, j);
			if (cnt < 1 || cnt > 2)
				return make_pair(none, empty);
			if (cnt == 1)
				ans[i][j] = ans[i-1][j];
			else
				ans[i][j] = 1 - ans[i-1][j];
		}
	}
	for (int j=0;j<n;++j)
		if (calc(ans, n-1, j) != 2)
			return make_pair(none, empty);

	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			if (ans[i][j] == -1 || init[i][j] != -1 && ans[i][j] != init[i][j])
				return make_pair(none, empty);
		}
	}
	
	return make_pair(uniquee, ans);
}

void solve(int test_ind){
	cin >> n;
	map<char, int> mp;
    map<int, char> imp;
	mp['S'] = 0;
	mp['G'] = 1;
	mp['.'] = -1;
	imp[1] = 'G';
	imp[0] = 'S';
	string s;
	vector<vector<int> > v(n, vector<int>(n));
	for (int i=0;i<n;++i){
		cin >> s;
		for (int j=0;j<n;++j){
			v[i][j] = mp[s[j]];
		}
	}

	auto ans = fun(v);
	cout << ans.first << endl;
	if (ans.first != uniquee)
		return;
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j)
			cout << imp[ans.second[i][j]];
		cout << endl;
	}
	cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}