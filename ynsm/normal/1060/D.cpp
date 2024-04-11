#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9, LOG = 18;

ll n, a[N], b[N], ans;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	sort(a , a + n);
    sort(b , b + n);
    for(int i = 0; i < n; i++)
    	ans += max(a[i], b[i]) + 1;
	cout << ans;
}