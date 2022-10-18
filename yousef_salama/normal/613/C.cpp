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

int n, c[30];
int main(){
    scanf("%d", &n);

    int m = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
        m += c[i];
    }
    

    for(int d = m; d >= 1; d--){
        bool f = true;
        for(int j = 0; j < n; j++)
            if((c[j] % d) != 0)f = false;

        if(f){
            if((d % 2) == 0){
                printf("%d\n", d);
                for(int i = 0; i < d; i++){
                    if((i % 2) == 0){
                        for(int j = 0; j < n; j++)
                        for(int k = 0; k < (c[j] / d); k++)
                            printf("%c", j + 'a');
                    }else{
                        for(int j = n - 1; j >= 0; j--)
                        for(int k = 0; k < (c[j] / d); k++)
                            printf("%c", j + 'a');
                    }
                }
                printf("\n");
                return 0;
            }else{
                int odd = 0;
                for(int i = 0; i < n; i++)
                    if(((c[i] / d) % 2) != 0)odd++;
                
                if(odd > 1)continue;
                else{
                    printf("%d\n", d);

                    int c_odd = -1;
                    for(int i = 0; i < n; i++)
                        if(((c[i] / d) % 2) != 0)c_odd = i;

                    for(int i = 0; i < d; i++){
                        for(int j = 0; j < n; j++)
                        for(int k = 0; k < ((c[j] / d) / 2); k++)
                            printf("%c", j + 'a');
                        if(c_odd != -1)printf("%c", c_odd + 'a');
                        for(int j = n - 1; j >= 0; j--)
                        for(int k = 0; k < ((c[j] / d) / 2); k++)
                            printf("%c", j + 'a');
                    }
                    printf("\n");

                    return 0;
                }
            }
        }
    }
    
    printf("0\n");
    for(int i = 0; i < n; i++)
    for(int j = 0; j < c[i]; j++)
        printf("%c", i + 'a');
    printf("\n");

    return 0;
}