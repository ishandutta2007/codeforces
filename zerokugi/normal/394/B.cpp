#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int p, x;

string check(int p, int k, int Z){
	string ret;
	int z = Z;
	int r = 0;
	REP(i, p){
		ret.push_back('0'+z);
		int t = z*k+r;
		z = t%10;
		r = t/10;
	}
	if(z != Z || *(ret.end()-1) == '0' || r) return "";
	reverse(ret.begin(), ret.end());
	return ret;
}

main(){
	while(cin >> p >> x){
		string ans = "";
		for(int i=1;i<10;i++){
			string ret = check(p, x, i);
			if(ret != "" && (ans == "" || ans > ret)) ans = ret;
		}
		if(ans == "") cout << "Impossible" << endl;
		else cout << ans << endl;
	}
	return 0;
}