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
char s[N];
bool solve(){
	int A, B;
	A = B = 0;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for(int i = 0; i < k; i++){
		bool a, b;
		a = b = 0;
		for(int j = i; j < n; j+=k){
			if(s[j] == '0')
				a = 1;			
			if(s[j] == '1')
				b = 1;
		}
		if(a & b)
			return 0;
		if(a)
			A++;
		if(b)
			B++;
	}
	return max(A, B) <= k / 2;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		if(solve())     
			puts("YES");
		else
			puts("NO");
	}
}