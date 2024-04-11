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
char s[5005];
int N, Q;
vector <bool> v[5005];
vector <int> a[5005];
int main(){
    scanf("%s", s);
    N = strlen(s);
    
    for(int st = 0; st < N; st++)
        v[1].push_back(true);
    for(int st = 0; st < N - 1; st++)
        v[2].push_back(s[st] == s[st + 1]);
    for(int d = 3; d <= N; d++){
        for(int st = 0; st + d - 1 < N; st++){
            int en = st + d - 1;
            v[d].push_back((s[st] == s[en]) && v[d - 2][st + 1]);
        }
    }
    for(int st = 0; st < N; st++)
        a[1].push_back(1);
    for(int st = 0; st < N - 1; st++)
        a[2].push_back(2 + v[2][st]);
    for(int d = 3; d <= N; d++){
        for(int st = 0; st + d - 1 < N; st++){
            int en = st + d - 1;
            a[d].push_back(v[d][st] + a[d - 1][st] + a[d - 1][st + 1] - a[d - 2][st + 1]);
        }
    }
    scanf("%d", &Q);
    while(Q--){
        int xi, yi;
        scanf("%d %d", &xi, &yi);
        
        xi--, yi--;
        printf("%d\n", a[yi - xi + 1][xi]);
    }
}