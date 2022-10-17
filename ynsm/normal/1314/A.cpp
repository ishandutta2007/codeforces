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
 
int n;
pii a[N];
int main()
{
	scanf("%d", &n);         
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i].f);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i].s);
	sort(a, a + n);
	ll last = 0, sum = 0, ans = 0;
	multiset< int > st;
	for(int i = 0, j = 0; i < n; i = j){
		while(j < n && a[i].f == a[j].f)
			j++;
		while(last < a[i].f){
			if(!st.empty()){
				sum += *st.begin();
				st.erase(st.begin());
				ans += sum;
				last++;
			}else{
				last = a[i].f;	
			}
		}
		for(int q = i; q < j; q++){
			sum += a[q].s;
			st.insert(-a[q].s);
		}
	}
	while(!st.empty()){
		sum += *st.begin();
		st.erase(st.begin());
		ans += sum;
	}
	printf("%lld", ans);
}