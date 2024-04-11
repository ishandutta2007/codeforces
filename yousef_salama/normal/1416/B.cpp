#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		vector < array <int, 3> > v;
		
		int sum = 0;
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			
			if(i == 0){
				sum = a;
			}else{
				if(a % (i + 1) == 0){
					v.push_back({i + 1, 1, a / (i + 1)});
				}else{
					int r = (i + 1) - a % (i + 1);
					v.push_back({1, i + 1, r});
					v.push_back({i + 1, 1, (a + r) / (i + 1)});
				}
				sum += a;
			}
		}
		
		if(sum % n != 0){
			printf("-1\n");
			continue;
		}
		
		int x = sum / n;
		for(int i = 1; i < n; i++){
			v.push_back({1, i + 1, x});
		}
		
		printf("%d\n", (int)v.size());
		for(auto p : v)
			printf("%d %d %d\n", p[0], p[1], p[2]);
	}
	return 0;
}