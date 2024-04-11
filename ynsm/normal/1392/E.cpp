#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, q;
ll a[50][50];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i & 1)
				a[i][j] = (1ll << (i + j));
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cin >> q;
	while(q--){
		ll s;
		cin >> s;
		int x = 0, y = 0;
		cout << x + 1 << " " << y + 1 << endl;
		for(int i = 0; i < n + n - 2; i++){
			if(((s >> (x + y + 1)) & 1) ^ (x & 1))
				x++;
			else
				y++;
			cout << x + 1 << " " << y + 1 << endl;
		}
	}
}