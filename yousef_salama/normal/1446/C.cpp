#include <bits/stdc++.h>
using namespace std;

vector <int> a;

int solve(int l, int r, int bit){
	if(bit == -1){
		return (r - l + 1);
	}
	
	int i = l;
	while(i <= r && ((a[i] & (1 << bit)) == 0))i++;
	
	if(i == l){
		return solve(l, r, bit - 1);
	}else if(i > r){
		return solve(l, r, bit - 1);
	}else{
		int x = solve(l, i - 1, bit - 1);
		int y = solve(i, r, bit - 1);
		
		return max(1 + x, 1 + y);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	
	a.resize(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end());
		
	printf("%d\n", n - solve(0, n - 1, 30));
	
	return 0;
}