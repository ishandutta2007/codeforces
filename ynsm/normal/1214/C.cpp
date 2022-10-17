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

int n, cur, ans = 1, ok;
char s[N];
int main()
{
	scanf("%d", &n);
	scanf("%s", &s);
	
	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			cur++;
		if(s[i] == ')')
			cur--;
		if(cur < 0){
			if(ok)
				ans = 0;
			else
				ok = 1, cur++;
		}
	}
	if(ok)                
		ans &= (cur == 1);
	else
		ans &= (cur == 0);
	if(ans)         
		puts("Yes");
	else
		puts("No");
	return 0;
}