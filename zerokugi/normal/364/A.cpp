#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

main(){
	int n;
	int m;
	string s;
	while(cin >> n >> s){
		m = s.size();
		map<int, ll> dic;
		ll nz = 0;
		for(int i=0;i<m;i++){
			ll sum = 0;
			for(int j=i;j<m;j++){
				sum += s[j] - '0';
				dic[sum] ++;
				nz ++;
			}
		}
		ll ans = 0;
		if(n == 0){
			ans = dic[0] * nz * 2 - dic[0]*dic[0];
		}else{
			FOR(it, dic)
				if(it->first && !(n % it->first) && dic.count(n / it->first)) ans += it->second * dic[n / it->first];
		}
		cout << ans << endl;
	}
	return 0;
}