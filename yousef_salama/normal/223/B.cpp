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
using namespace std;
char s[200005], t[200005];
int n, m, Left[200005], Right[200005], c[30][200005];
int main(){
    scanf("%s %s", &s, &t);
    n = strlen(s), m = strlen(t);
    
    Left[0] = 0;
    for(int i = 1; i < n; i++){
        if(s[i - 1] == t[Left[i - 1]])Left[i] = Left[i - 1] + 1;
        else Left[i] = Left[i - 1];
    }
    Right[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--){
        if(s[i + 1] == t[m - Right[i + 1] - 1])Right[i] = Right[i + 1] + 1;
        else Right[i] = Right[i + 1];
    }
    for(int x = 0; x < 26; x++)
        c[x][0] = t[0] == ('a' + x);
    for(int x = 0; x < 26; x++)
    for(int i = 1; i < m; i++)
        c[x][i] = c[x][i - 1] + ((t[i] - 'a') == x);
    for(int i = 0; i < n; i++){
        int lowbound = max(m - Right[i] - 1, 0);
        int uppbound = min(Left[i], m - 1);
        if(lowbound > uppbound){
            printf("No\n");
            return 0;
        }
        assert((c[s[i] - 'a'][uppbound] - c[s[i] - 'a'][lowbound] + (t[lowbound] == s[i])) == 
               (c[s[i] - 'a'][uppbound] - (lowbound ? c[s[i] - 'a'][lowbound - 1] : 0)));
        int ti = c[s[i] - 'a'][uppbound] - c[s[i] - 'a'][lowbound] + (t[lowbound] == s[i]);
        if(ti == 0){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}