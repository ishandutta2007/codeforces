#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		int x;
		string s;
		cin >> x >> s;
		
		ll ret = s.size();
		ll RET = s.size();
		for(int i = 0 ; i < x ; i ++){
			if(s[i] >= '2'){
				for(int j = i+1 ; j < min(ret,(ll)s.size()) && s.size() < x ; j ++){
					s += s[j];
				}
			}
			if(s[i] == '3'){
				for(int j = i+1 ; j < min(ret,(ll)s.size()) && s.size() < x ; j ++){
					s += s[j];
				}
			}
			ret += (s[i]-'1')*(ret-i-1);
			if(ret >= MOD)ret = MOD;
			RET += (s[i]-'1')*(MOD+RET-i-1);
			RET %= MOD;
			//cout << s << " " << RET << endl;
		}
		printf("%lld\n",RET);
	}
}