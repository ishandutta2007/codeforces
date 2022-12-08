#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

void inserts(vector<vector<pair<string, int>>> &c, vector<string> &hayc, string s, int eval) {
	if(hayc[eval] != "" && (hayc[eval].size() < s.size() || hayc[eval] < s)) return;
	hayc[eval] = s;
	if(c.size() < s.size()+1) c.resize(s.size()+1);
	c[s.size()].push_back(make_pair(s, eval));
}

int main()
{
	vector<vector<pair<string, int>>> e;
	vector<vector<pair<string, int>>> t;
	vector<vector<pair<string, int>>> f;
	
	vector<string> ans(1<<8, "");
	vector<string> haye(1<<8, "");
	vector<string> hayt(1<<8, "");
	vector<string> hayf(1<<8, "");
	int quedan = 1<<8, lact = 0;
	inserts(f, hayf, "x", 15);
	inserts(f, hayf, "y", 51);
	inserts(f, hayf, "z", 85);
	
	while(quedan > 0) {
		lact++;
		if((int)f.size() < lact+1) f.resize(lact+1);
		if((int)t.size() < lact+1) t.resize(lact+1);
		if((int)e.size() < lact+1) e.resize(lact+1);
		
		forn(i, f[lact-1].size()) {
			string s = "!";
			s += f[lact-1][i].first;
			inserts(f, hayf, s, 255-f[lact-1][i].second);
		}
		
		if(lact > 1) forn(i, e[lact-2].size()) {
			string s = "(";
			s += e[lact-2][i].first;
			s += ")";
			inserts(f, hayf, s, e[lact-2][i].second);
		}
		
		forn(i, lact-1) {
			forn(j, t[i].size()) {
				forn(k, f[lact-i-1].size()) {
					string s = t[i][j].first;
					s += "&";
					s += f[lact-i-1][k].first;
					inserts(t, hayt, s, t[i][j].second & f[lact-i-1][k].second);
				}
			}
		}
		
		forn(i, f[lact].size()) inserts(t, hayt, f[lact][i].first, f[lact][i].second);
		
		forn(i, lact-1) {
			forn(j, e[i].size()) {
				forn(k, t[lact-i-1].size()) {
					string s = e[i][j].first;
					s += "|";
					s += t[lact-i-1][k].first;
					inserts(e, haye, s, e[i][j].second | t[lact-i-1][k].second);
				}
			}
		}
		
		forn(i, t[lact].size()) inserts(e, haye, t[lact][i].first, t[lact][i].second);
		
		forn(i, e[lact].size()) {
			if(ans[e[lact][i].second] == "") {
				ans[e[lact][i].second] = e[lact][i].first;
				quedan--;
			}
			if((int) ans[e[lact][i].second].size() == lact)
			ans[e[lact][i].second] = min(ans[e[lact][i].second], e[lact][i].first);
		}
	}
	
	int n;
	cin >> n;
	forn(i, n) {
		string s;
		cin >> s;
		int k = 0 ;
		forn(i, 8) {
			k += (s[7-i]-'0')*(1<<i);
		}
		cout << ans[k] << endl;
	}
}