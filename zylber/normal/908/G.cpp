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


tint modexp(tint b, tint e) {
	if(e == 0) return 1;
	tint ans = modexp(b, e/2);
	ans = (ans*ans)%MOD;
	if(e%2) ans = (ans*b)%MOD;
	return ans;
}

tint calc(tint d, tint voy, tint quedan, vector<vector<tint>>& choose, vector<tint>& repuns) {
	
	tint mul = d, ans = 0;
	dforn(i, quedan+1) {
		//cout << i << " " << (((repuns[voy+i]*choose[quedan][i])%MOD)*mul)%MOD << endl;
		ans += (((repuns[voy+i]*choose[quedan][i])%MOD)*mul)%MOD;
		ans %= MOD;
		mul *= (9-d)*10+d;
		mul %= MOD;
	}
	//cout << d << " " << voy << " " << quedan << " " << ans << endl;
	return ans;
}

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<tint>> choose(n+1, vector<tint>(n+1, 0));
	
	forn(i, n+1) {
		choose[i][0] = 1;
		choose[i][i] = 1;
		forn(j, n+1) {
			if(i && j) choose[i][j] = (choose[i-1][j] + choose[i-1][j-1])%MOD;
		}
	}
	vector<tint> repuns(n+1,0);
	forn(i, n+1) if(i) repuns[i] = (repuns[i-1]*10+1)%MOD;
	
	vector<tint> voy(10, 0);
	vector<tint> base(10, 1);
	tint ans = 0;
	forn(i, n) {
		forn(cd, s[i]-'0') {
			forn(d, 10) {
				tint rb = base[d];
				if(cd > d) rb = (rb*10)%MOD;
				ans += (rb*calc(d, voy[d] + (cd == d), n-i-1, choose, repuns))%MOD;
				ans %= MOD;
			}
		}
		voy[s[i]-'0']++;
		forn(j, s[i]-'0') {
			base[j] *= 10;
			base[j] %= MOD;
		}
	}
	
	forn(d, 10) {
		//cout << base[d] << endl;
		ans += (base[d]*calc(d, voy[d], 0, choose, repuns))%MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	
	return 0;
}