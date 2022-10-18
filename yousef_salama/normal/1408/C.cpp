#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, l;
		scanf("%d %d", &n, &l);
		
		vector <int> a(n);
		for(int i = 0; i < n; i++)scanf("%d", &a[i]);
		
		double res = 0.0, x = 0.0, y = l;
		int i = 0, j = n - 1;
		
		while(true){
			while(i < n && a[i] <= x)i++;
			while(j >= 0 && a[j] >= y)j--;
			
			int vx = 1 + i, vy = n - j;
			
			if(i > j){
				res += (y - x) / (vx + vy);
				break;
			}
			
			if((a[i] - x) / vx  < (y - a[j]) / vy){
				res += (a[i] - x) / vx;
				y -= vy * (a[i] - x) / vx;
				x = a[i];
			}else{
				res += (y - a[j]) / vy;
				x += vx * (y - a[j]) / vy;
				y = a[j];
			}
		}
		printf("%.15f\n", res);
	}
	return 0;
}