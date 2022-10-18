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
using namespace std;

struct node{
    node *child[26];
} *root;

char s[1505], good[30];
int k, a[1505];
int main(){
    root = new node();
    
    scanf("%s %s %d", s, good, &k);
    
    a[0] = 0;
    for(int i = 0; s[i]; i++)
        a[i + 1] += a[i] + (good[s[i] - 'a'] == '0');
    
    int res = 0;
    for(int i = 0; s[i]; i++){
        node *cur = root;
        bool distinct = false;
        
        for(int j = i; s[j]; j++){
            if(cur->child[s[j] - 'a'] == NULL){
                distinct = true;
                cur->child[s[j] - 'a'] = new node();
            }
            cur = cur->child[s[j] - 'a'];
            
            if(a[j + 1] - a[i] <= k)
                res += distinct;
        }
    }
    printf("%d\n", res);
    return 0;
}