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
#define sz(v) ((int)(v.size()))
using namespace std;
int n, x, a[100005], tree[4 * 100005], added[4 * 100005];
void refresh(int i){
    if(2 * i < 4 * 100005)added[2 * i] += added[i];
    if(2 * i + 1 < 4 * 100005)added[2 * i + 1] += added[i];
    
    tree[i] += added[i];
    added[i] = 0;
}
void add(int i, int L, int R, int Left, int Right, int value){
    refresh(i);
    
    if(Left <= L && R <= Right){
        added[i] += value;
        refresh(i);
        
        return;
    }
    if(R < Left && Right < L)return;
    
    int mid = (L + R) / 2;
    add(2 * i, L, mid, Left, Right, value);
    add(2 * i + 1, mid + 1, R, Left, Right, value);
    
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}
int find_min(int i, int L, int R, int Left, int Right){
    refresh(i);
    
    if(Left <= L && R <= Right)return tree[i];
    if(R < Left && Right < L)return 1 << 30;

    int mid = (L + R) / 2;
    return min(find_min(2 * i, L, mid, Left, Right), find_min(2 * i + 1, mid + 1, R, Left, Right));
}
int main(){
    scanf("%d %d", &n, &x);
    x--;

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    
    int Min = *min_element(a, a + n);
    
    int L = x - 1;
    while(L >= 0 && a[L] > Min)L--;
    int R = n - 1;
    while(R > x && a[R] > Min)R--;
    
    if(a[x] == Min){
        for(int i = 0; i < n; i++){
            if(i > 0)printf(" ");

            long long N = n;
            if(i == x){
                printf("%I64d", (long long)(N * a[i]));
            }else printf("%d", a[i] - Min);
        }
        printf("\n");
        return 0;

    }
    if(L >= 0){
        bool ok = true;
        
        vector <bool> marked(n);
        
        int p = L + 1;
        
        while(true){
            marked[p % n] = true;
            if(a[p % n] == Min)ok = false;
            
            if((p % n) == x)break;
            p++;
        }
        if(ok){
            for(int i = 0; i < n; i++){
                if(i > 0)printf(" ");
                
                long long N = n;
                if(i == L){
                    printf("%I64d", (long long)(N * a[i] + (p - L)));
                }else printf("%d", a[i] - Min - marked[i]);
            }
            printf("\n");
            return 0;
        }
    }
    if(R >= 0){
        bool ok = true;
        
        vector <bool> marked(n);
        
        int p = R + 1;
        while(true){
            marked[p % n] = true;
            if(a[p % n] == Min)ok = false;
            
            if((p % n) == x)break;
            p++;
        }
        if(ok){
            for(int i = 0; i < n; i++){
                if(i > 0)printf(" ");
                
                long long N = n;
                if(i == R){
                    printf("%I64d", (long long)(N * a[i] + (p - R)));
                }else printf("%d", a[i] - Min - marked[i]);
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}