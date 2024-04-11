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

int n, a[500005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int i = 1, res = 0;
    while(i + 1 < n){
        int j = i;
        while((j + 1 < n) && (a[j - 1] != a[j]) && (a[j] != a[j + 1]))j++;
        
        if(j == i){
            i++;
            continue;
        }
        //cout << i << ' ' << j << endl;
        if((j - i) % 2 == 0){
            res = max(res, (j - i) / 2);
            for(int k = i; k < (i + j) / 2; k++)
                a[k] = a[i - 1];
            for(int k = (i + j) / 2; k < j; k++)
                a[k] = a[j];
        }else{
            res = max(res, (j - i + 1) / 2);
            for(int k = i; k < j; k++)
                a[k] = a[j];
        }
        i = j;
    }
    
    printf("%d\n", res);
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    
    return 0;
}