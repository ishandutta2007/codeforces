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

char s[105];
char c[] = "CODEFORCES";
int main(){
    scanf("%s", s);
    
    int N = strlen(s);
    if(N < 10){
        printf("NO\n");
        return 0;
    }
    
    bool found = false;
    for(int a = 0; a <= 10; a++){
        int b = 10 - a;
        
        bool ok = true;
        for(int i = 0; i < a; i++)
            if(s[i] != c[i])ok = false;
        
        for(int i = 0; i < b; i++)
            if(s[N - b + i] != c[a + i])ok = false;
        if(ok)found = true;
    }
    if(found)printf("YES\n");
    else printf("NO\n");
    
    return 0;
}