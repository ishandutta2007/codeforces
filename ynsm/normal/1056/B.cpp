#include <bits/stdc++.h>

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

ll n, m, ans;
ll get(int x){
	ll res = 0;
	for(int i = 0; i < m; i++)
		if(i * i % m == x){
			res += n / m;
			if(n / m != 0 && i == 0)
				res--;
		}
    for(int i = max(n / m * m, 1ll); i <= n; i++)
		if(1ll * i * i % m == x)
			res++;
	return res;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		ans += get(i) * get((m - i) % m);
	cout << ans;
	return 0;
}