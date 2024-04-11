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

int n, cnt[10], ans;
string s;
int main(){
	cin >> n;
	cin >> s;
	for(int i = 0 ; i < n; i++)
		cnt[s[i] - '0']++;
	for(int i = 1; i <= cnt[8]; i++)
		if( i * 10 <= n - i)
			ans = i;
	cout << ans;
}