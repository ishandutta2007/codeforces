#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;
int n;
set< ll > st;
void check(ll x){
	ll cnt = n / x;
	ll res = cnt * (cnt - 1) / 2;
	st.insert(res * x + cnt);	
}
int main(){
	cin >> n;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			check(i);
			check(n / i);
		}
	}
	for(auto it : st)
		cout << it << " ";
	return 0;
}