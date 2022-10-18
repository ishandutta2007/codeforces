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
#include <cstring>
#include <sstream>
using namespace std;
int N, a[100005], res[100005];
pair <int, int> v[100005];
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v, v + N);

    int u = -1;
    for(int i = 0; i < N; i++){
        if(v[i].second > u){
            res[v[i].second] = -1;
        }else res[v[i].second] = u - v[i].second - 1;

        u = max(u, v[i].second);
    }
    for(int i = 0; i < N; i++){
        if(i > 0)printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}