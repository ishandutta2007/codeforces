#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", a + i, b + i);
    }
    a[0] = 0;
    b[0] = 0;
    long long ans = 0;
    for(int i = 0;i < n;i++){
        if(a[i] <= b[i] && a[i + 1] >= b[i + 1]){
            ans += (b[i + 1] - b[i] + 1);
        }else{
            if(a[i] >= b[i] && a[i + 1] <= b[i + 1]){
                ans += (a[i + 1] - a[i] + 1);
            }else{
                ans += max(min(b[i + 1], a[i + 1]) - max(a[i], b[i]) + 1, 0);
            }
        } 
    }
    for(int i = 1;i < n;i++){
        if(a[i] == b[i])
            ans--;
    }
    cout << ans << endl;
    return 0;
}