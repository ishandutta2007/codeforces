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

int n, m, a[N];
int main()
{
	cin >> n >> m;
	if(n == 1 && m == 1){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < n + m; i++)
		a[i] = i + 1;
	if(n > m){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << a[m + i] * a[j] / __gcd(a[m + i], a[j]) << " ";
			cout << endl;
		}
	}else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << a[i] * a[n + j] / __gcd(a[i], a[n + j]) << " ";
			cout << endl;
		}
	}
	return 0;
}