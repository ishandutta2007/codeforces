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

int n, ans[N];
int main()
{
	scanf("%d", &n);
	if(n & 1){
		printf("YES\n");
		for(int i = 1, j = 1; i <= n; i++)
			if(i & 1)                          
				ans[i] = j++, ans[i + n] = j++;
			else
				ans[i + n] = j++, ans[i] = j++;
		for(int i = 1; i <= n + n; i++)
			printf("%d ", ans[i]);
	}else
		printf("NO");
	return 0;
}