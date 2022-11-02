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
int n, m, k;

const int maxn = 5005;
int a[maxn];
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        k = min(k, m - 1);
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        int ret = 0;
        for(int pre = 0;pre <= k;pre++){
            int ans = 2e9 + 5;
            for(int i = 0;i <= m - 1 - k;i++){
                int front = pre + i + 1;
                int rear = n - (k - pre) - (m - 1 - k - i);
                //cout << front << " " << rear << endl;
                front = a[front];
                rear = a[rear];
                ans = min(ans, max(front, rear));
            }
            ret = max(ret, ans);
        }
        cout << ret << endl;
    }
    return 0;
}