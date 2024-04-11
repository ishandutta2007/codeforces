#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	int prv = 0, c = 0;
	vector <int> total(n), v(n), d(n), ind(n + 1);
	
	for(int i = 0, j = 0; i < 2 * n; i++){
		char opr;
		scanf(" %c", &opr);
		
		if(opr == '+'){
			c++;
		}else{
			int x;
			scanf("%d", &x);
			
			v[j] = x;
			ind[x] = j;
			d[j] = c - prv;
			total[j] = c;
			j++;
			
			prv = c;
		}
	}
	
	set <int> ninjas, shuri;
	for(int i = 0; i < n; i++){
		ninjas.insert(i);
		shuri.insert(i);
	}
	
	vector <int> res(n);
	
	for(int i = 1; i <= n; i++){
		int j = ind[i];
		
		if(d[j] == 0){
			printf("NO\n");
			return 0;
		}
		
		
		auto k = prev(shuri.lower_bound(total[j]));
		res[*k] = i;
		shuri.erase(k);
		
		ninjas.erase(j);
		auto l = ninjas.lower_bound(j);
		if(l != ninjas.end())d[*l] += d[j] - 1;
	}
	
	printf("YES\n");
	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
	
	return 0;
}