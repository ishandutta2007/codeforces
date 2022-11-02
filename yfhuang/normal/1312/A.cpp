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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        if(n % m){
            puts("NO");
        }else{
            puts("YES");
        }
    }
    return 0;
}