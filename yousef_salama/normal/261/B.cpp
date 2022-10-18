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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

int n, p, a[55];
double fact[55], C[55][55][55];
int main(){
    fact[0] = 1;
    for(int i = 1; i <= 50; i++)
        fact[i] = fact[i - 1] * i;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    scanf("%d", &p);
    
    double ans = 0;
    for(int i = 0; i < n; i++)if(a[i] <= p){
        vector <int> v;
        for(int j = 0; j < n; j++)if(j != i)v.push_back(a[j]);
        
        for(int ind = 0; ind <= v.size(); ind++)
        for(int k = 0; k <= v.size(); k++)
        for(int j = 0; j <= p; j++){
            if(k == 0)C[ind][k][j] = 1;
            else if(ind == 0)C[ind][k][j] = 0;
            else{
                C[ind][k][j] = C[ind - 1][k][j];
                if(j >= v[ind - 1])C[ind][k][j] += C[ind - 1][k - 1][j - v[ind - 1]];
            }
        }
        
        for(int j = 0; j < n; j++)
            ans += C[v.size()][j][p - a[i]] * fact[j] * fact[n - j - 1];
    }
    printf("%.9f\n", ans / fact[n]);
    
    return 0;
}