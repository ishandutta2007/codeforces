#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int main(){
	scanf("%d %d %d", &n, &l, &r);
	
	long long s0 = 0;
	for(int i = 0; i < l; i++){
		s0 += 1 << i;
	}
	for(int i = 0; i < n - l; i++){
		s0++;
	}
	
	long long s1 = 0;
	for(int i = 0; i < r; i++){
		s1 += 1 << i;
	}
	for(int i = 0; i < n - r; i++){
		s1 += 1 << (r - 1);
	}
	printf("%I64d %I64d\n", s0, s1);
	
	
	return 0;
}