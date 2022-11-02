#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define REPS(i, n) for(int i=1;i<=(int)(n);i++)
typedef long long ll;
string s, t;

int parity(string s){
	int res = 0;
	REP(i, s.size()) res ^= s[i] == '1';
	return res;
}

int solve(string s, string t){
	REP(i, 1+min(t.size(), s.size())){
		int cur = s.size() - i;
		if(s.substr(cur, i) != t.substr(0, i)) continue;
		int spar = parity(s);
		int f = 1;
		int left = 0;
		for(int j = i;j<t.size();j++){
			if(spar != t[j]-'0'){
				while(left < cur && s[left] != '1') left++;
				if(left >= cur){
					f = 0;
					break;
				}
				spar ^= 1;
				left ++;
			}
			if(t[j] == '1') spar ^= 1;
		}
		if(f && left <= cur){
			return 1;
		}
	}
	return 0;
}

main(){
	cin >> s >> t;
	int ans = solve(s, t);
	if(parity(s) == 1) ans |= solve(s+"1", t);
	puts(ans ? "YES" : "NO");
	return 0;
}