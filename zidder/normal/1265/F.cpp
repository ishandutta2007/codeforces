#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define ll long long
using namespace std;
string s;
const int mod = 998244353;

void solve(int test_ind){
	cin >> s;
	vector<vector<pair<ll, ll> > > ans(s.size(), vector<pair<ll, ll> >(s.size()));
	for(int i=1;i<s.size();++i)
		ans[i][i-1] = {0, 1};
	for(int i=0;i<s.size();++i)
		ans[i][i] = {0, 1 + (s[i] == '?')};
	for(int d=1;d<s.size();++d){
		for(int st=0;st+d<s.size();++st){
			int en=st+d;
			if (s[st] == '(' && s[en] == ')'){
				ans[st][en] = {(ans[st+1][en-1].first + ans[st+1][en-1].second) % mod, ans[st+1][en-1].second};
				continue;
			}
			if (s[st] == ')'){
				ans[st][en] = ans[st+1][en];
				continue;
			}
			if (s[en] == '('){
				ans[st][en] = ans[st][en-1];
				continue;
			}
			ll cnt = ans[st+1][en-1].second * (1+(s[st]=='?')) * (1 + (s[en]=='?'));
			ll sm = 0;
			if (s[st] == '?' && s[en] == '?'){
				sm += ans[st+1][en-1].second;
				sm += ans[st][en-1].first;
				sm += ans[st+1][en].first;
			}
			else{
				if (s[st] == '?'){
					sm += ans[st+1][en].first;
				}
				else{
					sm += ans[st][en-1].first;
				}
					sm += ans[st+1][en-1].first + ans[st+1][en-1].second;
			}
			ans[st][en] = {sm%mod, cnt%mod};
		}
	}
	cout << ans[0][s.size()-1].first << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}