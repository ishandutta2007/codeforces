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
using namespace std;

int n, k;
char s[105];
bool b[105];

int main(){
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    k--;
    
    if(k == 0){
        while(k < n){
            printf("PRINT %c\n", s[k]);
            if(k + 1 < n){
                printf("RIGHT\n");
                k++;
            }else break;
        }
    }else if(k == n - 1){
        while(k >= 0){
            printf("PRINT %c\n", s[k]);
            if(k - 1 >= 0){
                printf("LEFT\n");
                k--;
            }else break;
        }
    }else{
        if(k < (n - 1) - k){
            while(k >= 0){
                printf("PRINT %c\n", s[k]);
                b[k] = true;
                
                if(k - 1 >= 0){
                    printf("LEFT\n");
                    k--;
                }else break;
            }
            while(k < n){
                if(!b[k])printf("PRINT %c\n", s[k]);
                if(k + 1 < n){
                    printf("RIGHT\n");
                    k++;
                }else break;
            }
        }else{
            while(k < n){
                printf("PRINT %c\n", s[k]);
                b[k] = true;

                if(k + 1 < n){
                    printf("RIGHT\n");
                    k++;
                }else break;
            }
            while(k >= 0){
                if(!b[k])printf("PRINT %c\n", s[k]);
                
                if(k - 1 >= 0){
                    printf("LEFT\n");
                    k--;
                }else break;
            }
        }
    }
    return 0;
}