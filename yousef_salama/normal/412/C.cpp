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

int n, m;
char s[100005];
char c[100005];

int main(){
    for(int i = 0; i < 100005; i++)
        c[i] = '-';
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        
        m = strlen(s);
        for(int j = 0; j < m; j++){
            if(s[j] == '?')continue;
            else{
                if(c[j] == '-')c[j] = s[j];
                else if(c[j] != s[j])c[j] = '?';
            }
        }
    }
    
    c[m] = 0;
    for(int j = 0; j < m; j++)
        if(c[j] == '-')c[j] = 'a';
    
    printf("%s\n", c);
    
    
    return 0;
}