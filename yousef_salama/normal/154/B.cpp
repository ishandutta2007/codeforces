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
#define MAXN 100005
using namespace std;
int n, m, x;
bool f[MAXN];
char str[2];

vector <int> factorize(int i){
    vector <int> ret;
    for(int j = 2; j * j <= i; j++){
        while(i % j == 0){
            ret.push_back(j);
            i /= j;
        }
    }
    if(i > 1)ret.push_back(i);
    
    return ret;
}
int main(){
    scanf("%d %d", &n, &m);
    
    map <int, int> prime_factors;
    while(m--){
        scanf("%s %d", str, &x);
        if(str[0] == '+'){
            if(f[x]){
                printf("Already on\n");
                continue;
            }
            int conflict = -1;
            vector <int> v = factorize(x);
            for(int i = 0; i < v.size(); i++)
                if(prime_factors.count(v[i]))conflict = prime_factors[v[i]];
            
            if(conflict > 0){
                printf("Conflict with %d\n", conflict);
                continue;
            }
            printf("Success\n");
            f[x] = true;
            for(int i = 0; i < v.size(); i++)
                prime_factors[v[i]] = x;
        }else{
            if(!f[x]){
                printf("Already off\n");
                continue;
            }
            vector <int> v = factorize(x);
            for(int i = 0; i < v.size(); i++)
                if(prime_factors.count(v[i]))prime_factors.erase(v[i]);
            f[x] = false;
            printf("Success\n");
        }
    }
    return 0;
}