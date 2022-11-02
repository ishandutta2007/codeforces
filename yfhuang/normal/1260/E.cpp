#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = (1 << 18) + 5;
typedef long long LL;
int n;
LL a[maxn];

priority_queue<LL> pq;

int main(){
    cin >> n;
    int t = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
    }
    LL ans = 0;
    int now = n;
    for(int len = n/2;len >= 1;len /= 2){
        for(int j = 1;j <= len;j++){
            if(a[now] == -1){
                cout << ans << endl;
                return 0;
            }
            pq.push(-a[now]);
            if(j == 1){
                ans += -pq.top();pq.pop();
            }
            now--;
        }
    } 
    cout << ans << endl;
    return 0;
}