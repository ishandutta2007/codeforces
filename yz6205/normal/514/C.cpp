#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 600005;
const int MOD = 1110111110111;
int base[N];
int n,m;

void hashInit(){
	base[0] = 1;
	for (int i=1;i<N;i++){
		base[i] = base[i - 1] * 11 % MOD;
	}
}

int hashString(string& s){
	int res = 0 ;
	for (int i=0;i<(int)s.length();i++){
		(res += (s[i] - 'a' + 1) * base[i] % MOD ) %= MOD;
	}
	return res;
}

set < int > st;

void init() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		string s;
		cin >> s;
		st.insert(hashString(s));
	}
}

void solve() {
	for (int i=1;i<=m;i++){
		string s;
		cin >> s;
		bool suc = 0;
		int hh = hashString(s);
		for (int j=0;j<(int)s.length();j++){
			for (char k='a';k<='c';k++){
				if (k != s[j]){
					int sub = (k - s[j]) * base[j] % MOD;
					if ( st.count((hh + sub + 5 * MOD) % MOD) ){
						suc = 1;
						break;
					}
				}
			}
		}
		puts(suc?"YES":"NO");
	}
}

#undef int
int main() {
	hashInit();
	init();
	solve();
	return 0;
}