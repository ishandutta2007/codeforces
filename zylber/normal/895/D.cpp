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

tint inv(tint a) {
	return modexp(a, MOD-2);
}

tint calcGreat(string s, string t, vector<tint> fact, vector<tint> invfact) {
	tint n = s.size();
	vector<tint> count(32);
	forn(i, n) count[s[i]-'a']++;
	
	tint ans = 0;
	forn(i, n) {
		tint prod = 1;
		tint l = n-i-1;
		forn(j, 32) {
			tint m = l;
			if(j > t[i]-'a') m++;
			if(m < count[j]) prod = 0; else {
				prod = (prod*fact[m])%MOD;
				prod = (prod*invfact[count[j]])%MOD;
				prod = (prod*invfact[m-count[j]])%MOD;
			}
			l -= count[j];
		}
		ans = (ans+prod)%MOD;
		count[t[i]-'a']--;
		if(count[t[i]-'a']<0) break;
	}
	return ans;
}

int main()
{
	string a, b;
	cin >> a >> b;
	
	tint HIGH = 1000010;
	vector<tint> fact(HIGH);
	fact[0] = 1;
	forn(i, HIGH) if(i) fact[i] = (i*fact[i-1])%MOD;
	vector<tint> invfact(HIGH);
	forn(i, HIGH) invfact[i] = inv(fact[i]);
	
	tint ans = (calcGreat(a, a, fact, invfact) - calcGreat(a, b, fact, invfact) + MOD)%MOD;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(a==b) ans--;
	cout << max(0LL,ans) << endl;
	
    return 0;
}