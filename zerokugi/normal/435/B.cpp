#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
string s;

string change(string str, int s, int n){
	if(!n || str.begin()+s == str.end()) return str;
	auto it = max_element(str.begin()+s, min(str.begin()+s+1+n, str.end()));
	n -= (it-str.begin())-s;
	char c = *it;
	str.erase(it);
	str.insert(str.begin() + s, c);
	return change(str, s+1, n);
}

main(){
	cin >> s >> n;
	cout << change(s, 0, n) << endl;
	return 0;
}