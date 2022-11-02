#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];
int n;

void dfs(int u){
    if(u == n){
        printf("%d\n", u);
        return;
    }
    if(s[u] == 'l'){
        dfs(u + 1);
        printf("%d\n", u);
    }else{
        printf("%d\n", u);
        dfs(u + 1);
    }
}

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    dfs(1);
    return 0;
}