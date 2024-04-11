#include <bits/stdc++.h>
using namespace std;

int m, p, a[1 << 20];
long long t, C[25][25];

vector <long long> operator *(vector <long long> a, vector <long long> b){
	vector <long long> c(m + 1, 0);

	for(int i = 0; i <= m; i++)
	for(int j = 0; j <= m; j++)
	for(int k = 0; k <= min(i, j); k++){
	    if(i + j - 2 * k > m)continue;
	    int x = i + j - 2 * k;
	    
		long long r = (C[x][i - k] * C[m - x][k]) % p;
		long long q = (a[i] * b[j]) % p;

		c[x] = (c[x] + r * q) % p;
	}
	return c;
}

vector <long long> mpow(vector <long long> b, long long t){
	if(t == 0){
		vector <long long> r(m + 1, 0);
		r[0] = 1;

		return r;
	}else if(t % 2 == 1){
		return (b * mpow(b, t - 1));
	}else{
		vector <long long> r = mpow(b, t / 2);
		return (r * r);
	}
}

int dp[1 << 20][25];
int main(){
	scanf("%d %I64d %d", &m, &t, &p);
	for(int i = 0; i < (1 << m); i++){
		scanf("%d", &a[i]);
	    a[i] = a[i] % p;
	}

	vector <long long> b(m + 1);
	for(int i = 0; i <= m; i++){
		scanf("%I64d", &b[i]);
	    b[i] = b[i] % p;
	}

	for(int i = 0; i <= m; i++)
	for(int j = 0; j <= m; j++){
		if(j == 0)C[i][j] = 1;
		else if(i == 0)C[i][j] = 0;
		else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
	}

	b = mpow(b, t);

    for(int mask = 0; mask < (1 << m); mask++)
    for(int r = 0; r <= m; r++){
        if(r == 0)dp[mask][r] = a[mask];
        else dp[mask][r] = 0;
    }
    for(int i = 0; i < m; i++){
        for(int r = m; r > 0; r--)
        for(int mask = 0; mask < (1 << m); mask++){
            dp[mask][r] += dp[mask ^ (1 << i)][r - 1];
            if(dp[mask][r] >= p)dp[mask][r] -= p;
        }
    }

	for(int i = 0; i < (1 << m); i++){
		long long res = 0;
		for(int r = 0; r <= m; r++)
			res = (res + b[r] * dp[i][r]) % p;
		printf("%I64d\n", res);
	}

    return 0;
}