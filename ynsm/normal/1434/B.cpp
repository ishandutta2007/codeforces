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
 
int n, a[N];
char ch[N];
vector< int > ans;
set< int > st;
int main()
{
	scanf("%d\n", &n);
	for(int i = 1; i <= n + n; i++){
		scanf("%c ", &ch[i]);
		if(ch[i] == '-')
			scanf("%d\n", &a[i]);
	}
	for(int i = n + n; i >= 1; i--){
		if(ch[i] == '+'){
			if(st.empty()){
				printf("NO");
				return 0;
			}
			ans.pb(*st.begin());
			st.erase(st.begin());
		}else{
			if(!st.empty() && *st.begin()  < a[i]){
				printf("NO");
				return 0;
			}
			st.insert(a[i]);
		}
	}
	reverse(ans.begin(), ans.end());
	printf("YES\n");
	for(auto x : ans)
		printf("%d ", x);
}