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
 
int a[4], b[4], p[4];
void solve(){
	for(int i = 0; i < 4; i++)
		b[i] = a[i];
	vector< int > ans;
	int last = -1;
	while(ans.size() < a[0] + a[1] + a[2] + a[3]){
		bool ok = 0;
		for(int i = 0; i < 4; i++){
			if(!b[p[i]])
				continue;
			if(last == -1 || abs(last - p[i]) == 1){
				ok = 1;
				ans.pb(p[i]);
				b[p[i]]--;
				last = p[i];
				break;
			}
		}
		if(!ok)
			return;
	}
	puts("YES");
	for(auto x : ans)
		printf("%d ", x);
	exit(0);
}
int main(){
	for(int i = 0; i < 4; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < 4; i++)
		p[i] = i;
	do{
		solve();	
	}while(next_permutation(p, p + 4));
	puts("NO");
	return 0;
}