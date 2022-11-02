#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;
#define REP(i, n) for(int i=0;i<(int)n;i++)
#define REPS(i, n) for(int i=1;i<=(int)n;i++)
#define RREP(i, n) for(int i=n-1;i>=0;i--)
#define RREPS(i, n) for(int i=n;i>0;i--)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
string s;

int solve(string s){
	int n = s.size();
	if(n < 3){
		return -1;
	}
	s += "#";
	int c = 0;
	vector<pair<int, int>> d;
	REPS(i, n-1){
		if(s[i-1] == s[i+1]) c++;
		else{
			if(c) d.emplace_back(c, i - c);
			c = 0;
		}
	}
	vector<int> dp(n);
	dp[0] = 0;
	REPS(i, n-1){
		set<int> s;
		REP(j, i){
			int l = max(0, j - 1);
			int r = max(i - j - 2, 0);
			s.insert(dp[l]^dp[r]);
		}
		for(int j=0;;j++){
			if(!s.count(j)){
				dp[i] = j;
				break;
			}
		}
	}
	int ans = 0;
	REP(i, d.size()) ans ^= dp[d[i].first];
	if(!ans) return -1;
	REP(i, d.size()){
		int c = d[i].first;
		int x = ans ^ dp[c];
		REP(j, c){
			int l = max(0, j - 1);
			int r = max(c - j - 2, 0);
			if((x^dp[l]^dp[r]) == 0) return d[i].second + j;
		}
	}
	assert(false);
}

int main(){
	cin >> s;
	int res = solve(s);
	if(res == -1) cout << "Second" << endl;
	else{
		cout << "First" << endl;
		cout << res + 1 << endl;
	}
	return 0;
}