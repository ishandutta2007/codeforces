#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500;

char s[N];
int n;
ll ans;
bool bad(int l, int r){
	for(int k = 1; r - k - k >= l; k++)
		if(s[r] == s[r - k] && s[r] == s[r - k - k])
			return 0;
	return 1;
}
int main()
{
	scanf("%s", s);
	n = strlen(s);
	ans = 1ll * n * (n + 1) / 2;
	for(int l = 0; l < n; l++)
		for(int r = l; r < n; r++)
			if(bad(l, r))
				ans--;
			else
				break;
	printf("%lld", ans);
	return 0;
}