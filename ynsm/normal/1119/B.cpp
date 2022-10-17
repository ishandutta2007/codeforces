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

int n, h, a[N];
int main()
{
	scanf("%d%d", &n, &h);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		sort(a + 1, a + 1 + i);
		int cur = 0;
		for(int j = i; j >= 1; j -= 2)
			cur += a[j];
		if(cur > h){
			cout << i - 1;
			return 0;
		}
	}
	cout << n;
	return 0;
}