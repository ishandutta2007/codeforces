#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
const int maxn = 300000 + 5;
int c[maxn];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &c[i]);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(c[i] != c[1]){
            ans = max(ans, i - 1);
        }
        if(c[i] != c[n]){
            ans = max(ans, n - i);
        }
    }
    cout << ans << endl;
    return 0;
}