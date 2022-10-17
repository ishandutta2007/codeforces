#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

const int INF = 1000000000;

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		int n,m,k;
		int a[4000];
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 0 ; i < n ; i ++){
			scanf("%d",&a[i]);
		}
		
		int ret = 0;
		k = min(k,m-1);
		int l = m-1-k;
		for(int x = 0 ; x <= k ; x ++){
			int ans = INF;
			for(int y = 0 ; y <= l ; y ++){
				ans = min( ans , max( a[x+y] , a[n-1-((m-1)-x-y)] ) );
			}
			ret = max( ret , ans );
		}
		printf("%d\n",ret);
	}
}