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

int n, m, x[N], y[N], x1[N], x2[N];
vector< int > v;
int main(){
	scanf("%d%d", &n, &m); 
	for(int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	
	sort(x, x + n);
    for(int i = 0; i < m; i++){
		scanf("%d%d%d", &x1[i], &x2[i], &y[i]);
    	if(x1[i] == 1){
    		v.pb(x2[i]);
    	}
    }
    sort(v.begin(), v.end());
    int ans = inf;
    //for(auto it : v)
    //	cerr << it << " "; cerr << endl;
    x[n] = 1e9;
    for(int i = -1; i < n; i++){
    	// v[j] >= a[i]
    	int id = lower_bound(v.begin(), v.end(), x[i + 1]) - v.begin();
    	//cerr << i << " " << id << " " << x[i + 1] << endl;
    	ans = min(ans, i + 1 + (int)v.size() - id);
    }
    printf("%d", ans);
	return 0;
}