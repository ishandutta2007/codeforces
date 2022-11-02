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

int n;
const int maxn = 105;
int a[maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        for(int i = n;i >= 1;i--){
            printf("%d%c", a[i], i == 1 ? '\n' : ' ');
        }
    }
    return 0;
}