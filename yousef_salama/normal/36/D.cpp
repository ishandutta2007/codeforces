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

int t, k, n, m;

bool win(int a, int b){
    if(b < a)swap(a, b);
    
    
    int part = a / (k + 1);
    
    if(a % (k + 1) == k)return true;
    
    if(k == 1){
        if((a + b) % 2 == 0)return false;
        else return true;
    }
    
    if(part % 2 == 0){
        if((a + b) % 2 == 0)return false;
        else return true;
    }else{
        if((a + b) % 2 == 0)return true;
        else return false;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d %d", &t, &k);
    while(t--){
        scanf("%d %d", &n, &m);
        
        if(win(n - 1, m - 1))printf("+\n");
        else printf("-\n");
    }
    return 0;
}