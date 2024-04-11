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
 
int n, k, a[N], b[N];
int main()
{
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++)
			cin >> a[i] >> b[i];				
		bool ok = 0;
		for(int i = 0; i < n; i++){
			bool cur = 1;
			for(int j = 0; j < n; j++)
				if(abs(a[i] - a[j]) + abs(b[i] - b[j]) > k)
					cur = 0;			
			ok |= cur;
		}
		if(ok)                
			cout << 1 << endl;
		else
			cout << -1 << endl;
	}
}