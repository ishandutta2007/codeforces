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
int n, m, ans[N];
char s[N], t[N];
int main()
{
	int q;
	scanf("%d", &q);
	while(q--){         
		scanf("%d", &n);
		scanf("%s", &s);
		scanf("%s", &t);
		m = 0;
		int l = 0, r = n - 1, k = 0;
		bool inv = 0;     
		while(k < n){
			if(inv){
				if(t[n - 1 - k] != s[l]){
					l++;
				}else{
					if(t[n - 1 - k] != s[r])
						ans[m++] = 1;
					ans[m++] = n - k;	
					r--;
					inv = 0;
				}
			}else{
				if(t[n - 1 - k] == s[r]){
					r--;
				}else{
					if(t[n - 1 - k] == s[l])
						ans[m++] = 1;
					ans[m++] = n - k;	
					l++;
					inv = 1;
				}
			}
			k++;	
		}
		printf("%d ", m);
		for(int i = 0; i < m; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}	
}