#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		long long w;
		
		scanf("%d %lld", &n, &w);
		
		vector <long long> v(n);
		
		int mx = -1;
		for(int i = 0; i < n; i++){
			scanf("%lld", &v[i]);
			if(v[i] <= w && (mx == -1 || v[i] > v[mx]))mx = i;
		}
		
		if(mx == -1){
			printf("-1\n");
			continue;
		}
		
		if(v[mx] * 2 >= w){
			printf("1\n%d\n", mx + 1);
			continue;
		}
		
		long long sum = 0;
		vector <int> r;
		
		for(int i = 0; i < n; i++)if(v[i] <= w){
			r.push_back(i);
			sum += v[i];
			if(2 * sum >= w)break;
		}
		
		if(2 * sum >= w){
			printf("%d\n", (int)r.size());
			for(int i = 0; i < (int)r.size(); i++){
				if(i > 0)printf(" ");
				printf("%d", r[i] + 1);
			}
			printf("\n");
		}else printf("-1\n");
	}
	return 0;
}