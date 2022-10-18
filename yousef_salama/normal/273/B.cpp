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

int n, m, comb[200005][3], c[200005];
pair <int, int> a[100005], b[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    scanf("%d", &m);
    
    for(int i = 0; i <= 2 * n; i++)
    for(int j = 0; j <= 2; j++){
        if(j == 0)comb[i][j] = 1;
        else if(i == 0)comb[i][j] = 0;
        else comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % m;
    }
    
    sort(a, a + n);
    sort(b, b + n);
    
    long long ans = 1;
    
    int i = 0, j = 0;
    while(i < n || j < n){
        bool f1 = false, f2 = false;
        
        if(i >= n)f2 = true;
        else if(j >= n)f1 = true;
        else{
            if(a[i].first < b[j].first)f1 = true;
            else if(a[i].first > b[j].first)f2 = true;
            else f1 = f2 = true;
        }
        
        int k = 0;
        if(f1){
            int na = a[i].first;
            while(a[i].first == na && i < n){
                c[k++] = a[i].second;
                i++;
            }
        }
        
        if(f2){
            int nb = b[j].first;
            while(b[j].first == nb && j < n){
                c[k++] = b[j].second;
                j++;
            }
        }
        
        sort(c, c + k);
        
        for(int L = 0; L < k; ){
            int R = L;
            while(R < k && c[L] == c[R]){
                R++;
            }
            
            ans = (ans * comb[k - L][R - L]) % m;
            L = R;
        }
    }
    printf("%d\n", ans);
    return 0;
}