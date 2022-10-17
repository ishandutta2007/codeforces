#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	string s;
	cin >> s;
	
	ll ret[30][30] = {};
	ll cnt[30] = {};
	for(int i = 0 ; i < s.size() ; i ++){
		for(int j = 0 ; j < 26 ; j ++){
			ret[j][s[i]-'a'] += cnt[j];
		}
		cnt[s[i]-'a'] ++;
	}
	
	ll RET = 0;
	for(int i = 0 ; i < 26 ; i ++){
		for(int j = 0 ; j < 26 ; j ++){
			RET = max( RET , ret[i][j] );
		}
		RET = max( RET , cnt[i] );
	}
	printf("%lld\n",RET);
}