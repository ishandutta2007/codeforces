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
 
int n;
char s[N];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%s", &s);
		for(int i = 0; i < n; i++){
			if(s[i] != '-'){
                i++;
				int ans = 0, x = 0;
			    for(int j = 0, q = 0; j < n; j = q){
					while(q < n && s[(i + j) % n] == s[(i + q) % n])
						q++;			    
			    	if(s[(i + j) % n] == '-')
			    		ans += q - j + 1;
			    	else if(s[(i + j) % n] == '<')
			    		x |= 1;
			    	else
			    		x |= 2;
			    }
			    if(x == 3)
			    	printf("%d\n", ans);
				else
					printf("%d\n", n);
				break;
			}
			if(i == n - 1){
				printf("%d\n", n);
				break;			
			}
		}
	}
}