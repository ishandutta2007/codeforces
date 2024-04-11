//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <unordered_set>
using namespace std;

int n, f[100005], s[100005][65], bit[100005], r[100005];
long long x[100005];
//unordered_set <int> s[100005];

int main(){
    scanf("%d", &n);

    long long xt = 0, m = 0;
    for(int i = 0; i < n; i++){
        scanf("%I64d", &x[i]);
        r[i] = i;

        xt ^= x[i];
    }

    int i = 0;

    for(int b = 63; b >= 0; b--)if(!(xt & (1LL << b))){
        bool found = false;
        for(int j = i; j < n; j++)if(x[j] & (1LL << b)){
            swap(x[i], x[j]);
            swap(r[i], r[j]);
            found = true;
            
            break;
        }
        if(found){
            s[r[i]][i] = 1;
            bit[i] = b;
            for(int j = i + 1; j < n; j++)if(x[j] & (1LL << b)){
                x[j] ^= x[i];
                for(int k = 0; k <= i; k++)
                    s[r[j]][k] ^= s[r[i]][k];
            }
            i++;
        }
    }
    int st = 0;
    for(; st < i; st++)if(!(m & (1LL << bit[st]))){
        for(int k = 0; k < i; k++)
            f[r[k]] ^= s[r[st]][k];
        m ^= x[st];
    }

    for(int b = 63; b >= 0; b--)if(xt & (1LL << b)){
        bool found = false;
        for(int j = i; j < n; j++)if(x[j] & (1LL << b)){
            swap(x[i], x[j]);
            swap(r[i], r[j]);
            found = true;
            
            break;
        }
        if(found){
            s[r[i]][i] = 1;
            bit[i] = b;
            for(int j = i + 1; j < n; j++)if(x[j] & (1LL << b)){
                x[j] ^= x[i];
                for(int k = 0; k <= i; k++)
                    s[r[j]][k] ^= s[r[i]][k];
            }
            i++;
        }
    }
    for(; st < i; st++)if(!(m & (1LL << bit[st]))){
        for(int k = 0; k < i; k++)
            f[r[k]] ^= s[r[st]][k];
        m ^= x[st];
    }


    for(int j = 0; j < n; j++){
        if(j > 0)printf(" ");
        
        if(f[j])printf("2");
        else printf("1");
    }
    printf("\n");

    return 0;

}