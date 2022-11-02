#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

int n;
int a[maxn];
int b[maxn];
int cnt[maxn];
vector<int> G[maxn];
typedef long long LL;
int main(){
    while(cin >> n){
        int tot = 0;
        int N = n;
        for(int i = 1;i <= n;i++){
            cnt[i] = 0;
            G[i].clear();
        }
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
            if(a[i] != a[i - 1]){
                b[++tot] = a[i];
                G[b[tot]].push_back(tot);
            }
        }
        n = tot;
        LL now = 0;
        LL ans = 0;
        for(int i = N;i >= 1;i--){
            now += 1LL * (N - i + 1) * G[i].size(); 
            for(int j = 0;j < G[i].size();j++){
                int pos = G[i][j];
                if(pos > 1 && b[pos - 1] > b[pos]){
                    now -= 1LL * (N - b[pos - 1] + 1);
                }
                if(pos < n && b[pos + 1] > b[pos]){
                    now -= 1LL * (N - b[pos + 1] + 1);
                }
            }
            ans += now;
        }
        cout << ans << endl;
    }
    return 0;
}