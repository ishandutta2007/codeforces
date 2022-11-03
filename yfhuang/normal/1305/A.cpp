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

using namespace std;

int t;

int n;
const int maxn = 1005;

int a[maxn], b[maxn];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        for(int j = 1;j <= n;j++){
            scanf("%d", &b[j]);
        }
        sort(a + 1,a + 1 + n);
        sort(b + 1,b + 1 + n);
        for(int i = 1;i <= n;i++){
            printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
        for(int i = 1;i <= n;i++){
            printf("%d%c", b[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}