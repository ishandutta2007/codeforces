#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n,k,s,t;

const int maxn = 2e5 + 5;

int c[maxn],v[maxn];
int g[maxn];

bool check(int V){
	long long ans = 0;
	for(int i = 1;i <= k;i++){
		int S = g[i] - g[i - 1];
		int t2 = min(S,V - S);
		if(t2 < 0) return false;
		int t1 = 2 * S - 2 * t2;
		if(t1 < 0) return false;
		ans += (t1 + t2);
	}
	return ans <= (long long)t;
}

int main(){
	cin >> n >> k >> s >> t;
	int l = 1e9 + 5,r = -1;
	for(int i = 1;i <= n;i++) scanf("%d%d",c + i,v + i),l = min(l,v[i]),r = max(r,v[i]);
	for(int i = 1;i <= k;i++) scanf("%d",g + i);
	sort(g + 1,g + 1 + k);
	g[k + 1] = s;
	k++;
	g[0] = 0;
	//cout << l << " " << r << endl;
	//cout << check(7) << endl;
	while(l < r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	//cout << l << endl;
	//cout << check(l) << endl;
	if(!check(l)){
		printf("-1\n");
	}else{
		int mc = 1e9 + 5;
		for(int i = 1;i <= n;i++){
			if(v[i] >= l) mc = min(mc,c[i]);
		}
		if(mc == 1e9 + 5) printf("-1\n");
		else printf("%d\n",mc);
	}
	return 0;
}