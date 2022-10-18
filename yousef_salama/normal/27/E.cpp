#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#define INF 1000000000000000000ULL
using namespace std;
int n, p[60];
unsigned long long dp[55][1005];
bool isprime(int d){
    for(int i = 2; i * i <= d; i++)
        if(d % i == 0)return false;
    return true;
}
int main(){
    cin >> n;
    for(int i = 0, j = 2; i < 55;){
        if(isprime(j))p[i++] = j;
        
        j++;
    }
    
    dp[0][1] = 1;
    for(int j = 2; j <= n; j++)
        dp[0][j] = INF;
    for(int i = 1; i <= 7; i++)
    for(int j = 1; j <= n; j++){
        dp[i][j] = INF;
        for(int k = 0; k + 1 <= j; k++){
            if(pow(p[i - 1], k) > INF)break;
            if(dp[i - 1][j / (k + 1)] > 1000000000 && pow(p[i - 1], k) > 1000000000)break;
            if(j % (k + 1) == 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j / (k + 1)] * (unsigned long long)pow(p[i - 1], k));
        }
    }
    cout << dp[7][n] << endl;
    return 0;
}