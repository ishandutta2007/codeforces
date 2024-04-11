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

int n, cnt[1000];
int main()
{
	// lose if del heap
	// lose if a[i] == 1 > n / 2
	// win if 0 < a[i] == 1 <= n / 2 

	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		while(x <= 100)
			cnt[x++]++;
	}
	for(int i = 1; i <= 100; i++){
		if(0 < cnt[i]  && cnt[i] <= n / 2){
			printf("Alice");
			return 0;
		}
		if(n / 2 < cnt[i] && cnt[i] <= n){
			printf("Bob");
			return 0;
		}
	}
	return 0;
}