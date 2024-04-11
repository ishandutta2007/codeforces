#include <bits/stdc++.h>
using namespace std;

#define MOD 7340033

vector <int> dp[35];
void merge(vector <int> &p, vector <int> &q){
    vector <int> r(1001, 0);
    for(int i = 0; i <= 1000; i++)
    for(int j = 0; (i + j) <= 1000; j++){
        r[i + j] += ((long long)p[i] * q[j]) % MOD;
        if(r[i + j] >= MOD)r[i + j] -= MOD;
    }
    p = r;
}

void print(vector <int> v){
	for(int i = 0; i < min((int)v.size(), 10); i++)
		cout << v[i] << ' ';
	cout << endl;
}

int q, n, k;
int main(){
    for(int i = 0; i < 32; i++){
        if(i == 0){
            dp[i].resize(1001);
            dp[i][0] = 1;
        }
     
        dp[i + 1].resize(1001);
        dp[i + 1][1] = 1;
        
        for(int t = 0; t < 4; t++)
            merge(dp[i + 1], dp[i]);
    	dp[i + 1][0] = 1;
    }
    
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &n, &k);
        
        int m = 0;
        while(n > 1){
            if(n % 2 == 0)break;
            
            n /= 2;
            m++;
        }
        printf("%d\n", dp[m][k]);
    }
    
    return 0;
}