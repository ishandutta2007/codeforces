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
using namespace std;

struct box{
    int apple, orange, index;
};
bool operator <(box a, box b){
    if(a.apple != b.apple)return a.apple < b.apple;
    if(a.orange != b.orange)return a.orange < b.orange;
    return a.index < b.index;
}

int T, N;
box A[200005];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 0; i < 2 * N - 1; i++){
            scanf("%d %d", &A[i].apple, &A[i].orange);
            A[i].index = i;
        }
        sort(A, A + (2 * N - 1));
        
        long long apple_total = 0, orange_total = 0, apple_even = 0, orange_even = 0;
        for(int i = 0; i < 2 * N - 1; i++){
            apple_total += A[i].apple;
            orange_total += A[i].orange;
            
            if(i % 2 == 0){
                apple_even += A[i].apple;
                orange_even += A[i].orange;
            }
        }
        
        printf("YES\n");
        if(apple_even * 2 >= apple_total && orange_even * 2 >= orange_total){
            bool first = true;
            for(int i = 0; i < 2 * N - 1; i++){
                if(i % 2 == 0){
                    if(first)first = false;
                    else printf(" ");
                    
                    printf("%d", A[i].index + 1);
                }
            }
            printf("\n");
        }else{
            bool first = true;
            for(int i = 0; i < 2 * N - 1; i++){
                if((i % 2 != 0) || (i == 2 * N - 2)){
                    if(first)first = false;
                    else printf(" ");
                    
                    printf("%d", A[i].index + 1);
                }
            }
            printf("\n");
        }
    }
    return 0;
}