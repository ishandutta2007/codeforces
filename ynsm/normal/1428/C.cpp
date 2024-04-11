#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, k;
char s[N], a[N];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", &s);
		n = strlen(s);
		k = 0;
		for(int i = 0; i < n; i++){
			if(k && a[k - 1] == 'A' && s[i] == 'B')
				k--;
			else if(k && a[k - 1] == 'B' && s[i] == 'B')
				k--;
			else
				a[k++] = s[i];
		}
		printf("%d\n", k);
	}
}