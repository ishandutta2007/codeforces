#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
	int n, x, pos;
	scanf("%d %d %d", &n, &x, &pos);
	x--;
	
	vector < vector <long long> > C(n + 1, vector <long long> (n + 1));
	
	for(int i = 0; i <= n; i++)
	for(int j = 0; j <= n; j++){
		if(j == 0)C[i][j] = 1;
		else if(i == 0)C[i][j] = 0;
		else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
	
	vector <long long> fact(n + 1);
	
	fact[0] = 1;
	for(int i = 1; i <= n; i++)fact[i] = fact[i - 1] * i % MOD;
	
	int left = 0, right = n, t0 = x, t1 = n - x - 1, c0 = 0, c1 = 0;
	while(left < right){
		int middle = (left + right) / 2;
		
		if(middle == pos){
			left = middle + 1;
		}else if(middle > pos){
			c1++;
			right = middle;
		}else{
			c0++;
			left = middle + 1;
		}
	}
	
	long long res = C[t0][c0] * fact[c0] % MOD * C[t1][c1] % MOD * fact[c1] % MOD * fact[n - 1 - c0 - c1] % MOD;
	printf("%lld\n", res);

	return 0;
}