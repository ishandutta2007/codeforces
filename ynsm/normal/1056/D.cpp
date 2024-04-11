#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, p[N], sz[N];
int main(){
	scanf("%d", &n);
	if(n == 1){
		cout << 1;
		return 0;
	}
	for(int i = 2; i <= n; i++)
		scanf("%d", &p[i]);
	for(int i = n; i >= 2; i--){
		if(sz[i] == 0)
			sz[i]++;
		sz[p[i]] += sz[i];
	}
	sort(sz + 1, sz + 1 + n);
	for(int i = 1; i <= n; i++)
		printf("%d ", sz[i]);
	return 0;
}