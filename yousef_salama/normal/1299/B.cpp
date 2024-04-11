#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, x[MAXN], y[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
		
	if(n % 2 == 1){
		printf("NO\n");
		return 0;
	}
	
	bool ok = true;
	for(int i = 0; i < n / 2; i++){
		pair <int, int> a = make_pair(x[i + 1] - x[i], y[i + 1] - y[i]);
		pair <int, int> b = make_pair(-x[(i + n / 2 + 1) % n] + x[i + n / 2], -y[(i + n / 2 + 1) % n] + y[i + n / 2]);
		
		if(a != b){
			ok = false;
			break;
		}
	}
	
	if(ok)printf("YES\n");
	else printf("NO\n");
	
	return 0;
}