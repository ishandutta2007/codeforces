#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N =  1010, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, a[N][N], b[N][N], c[N][N], B[N], C[N]; 
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

	for(int i = 0; i < n; i++){
		vector< int > v;
		for(int j = 0; j < m; j++)
			v.pb(a[i][j]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end()); 
    	B[i] = v.size();
		for(int j = 0; j < m; j++)
			b[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
	}

	for(int j = 0; j < m; j++){
		vector< int > v;
		for(int i = 0; i < n; i++)
			v.pb(a[i][j]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end()); 
    	C[j] = v.size();
		for(int i = 0; i < n; i++)
			c[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			printf("%d ", max(B[i] + max(0, c[i][j] - b[i][j]), C[j] + max(0, b[i][j] - c[i][j])));
		printf("\n");			
	}

	                                                     
												                         
	return 0;
}