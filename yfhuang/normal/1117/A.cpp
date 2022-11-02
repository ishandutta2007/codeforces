#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
const int maxn = 1e5 + 5;

int a[maxn];

int main(){
    while(cin >> n){
        int mx = -1;
        for(int i = 1;i <= n;i++){
            scanf("%d", a + i);
            mx = max(mx, a[i]);
        }
        int len = 0;
        int ans = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] == mx){
                len++;
            }else{
                len = 0;
            }
            ans = max(ans, len);
        }
        cout << ans << endl;
    } 
    return 0;
}