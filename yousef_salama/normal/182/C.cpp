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

int n, len, a[100005], k;

struct cmp{
    bool operator ()(const int &x, const int &y) const{
        if(a[x] == a[y])return x < y;
        return a[x] > a[y];
    }
};

long long sum;
set <int, cmp> A, B;
void insert(int i){
    if(a[i] >= 0){
        B.insert(i);
        sum += a[i];
    }else{
        if(A.size() + 1 <= k){
            A.insert(i);
            sum -= a[i];
        }else if(k > 0 && a[*A.begin()] > a[i]){
            B.insert(*A.begin());
            sum += 2 * a[*A.begin()];
            
            A.erase(A.begin());
            A.insert(i);
            sum -= a[i];
        }else{
            B.insert(i);
            sum += a[i];
        }
    }
}
void remove(int i){
    if(B.count(i)){
        sum -= a[i];
        B.erase(i);
    }else{
        sum += a[i];
        A.erase(i);
        
        if(!B.empty()){
            set <int, cmp> :: iterator d = B.end();
            d--;
            
            if(a[*d] < 0){
                sum -= 2 * a[*d];
                
                A.insert(*d);
                B.erase(d);
            }
        }
    }
}
long long solve(){
    sum = 0;
    A.clear(), B.clear();
    
    for(int i = 0; i < len; i++)
        insert(i);
    
    long long res = sum;
    for(int i = len; i < n; i++){
        remove(i - len);
        insert(i);
        
        res = max(res, sum);
    }
    return res;
}

int main(){
    scanf("%d %d", &n, &len);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    
    long long res = solve();
    
    for(int i = 0; i < n; i++)
        a[i] *= -1;
    res = max(res, solve());
    
    printf("%I64d\n", res);
    return 0;
}