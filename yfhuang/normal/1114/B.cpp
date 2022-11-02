#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;
const int maxn = 2e5 + 5;
pair<int, int> a[maxn];
bool vis[maxn];
int main(){
    while(cin >> n >> m >> k){
        memset(vis, 0, sizeof(vis));
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        sort(a + 1,a + 1 + n);
        long long ans = 0;
        for(int i = n - m * k + 1;i <= n;i++){
            vis[a[i].second] = true;
            ans += a[i].first;
        }
        cout << ans << endl;
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(vis[i]){
                cnt++;
                if(cnt % m == 0 && cnt < m * k){
                    printf("%d ", i);
                }
            }
        }
        cout << endl;
    }
    return 0;
}