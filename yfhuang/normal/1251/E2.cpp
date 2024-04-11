#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, n;
const int maxn = 2e5 + 5;

vector<int> b[maxn];
int pre[maxn];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i <= n;i++){
            b[i].clear();
        }
        for(int i = 1;i <= n;i++){
            int x, y;
            scanf("%d%d", &x, &y);
            b[x].push_back(y);
        }
        pre[0] = b[0].size();
        for(int i = 1;i <= n;i++){
            pre[i] = pre[i - 1] + b[i].size();
        } 
        priority_queue<int> pq;
        int buy = 0;
        long long ans = 0;
        for(int i = n;i >= 0;i--){
            for(auto x : b[i])
                pq.push(-x);
            while(pre[i - 1] + buy < i){
                ans += -pq.top();pq.pop();
                buy++; 
                //cout << i << " " << buy << " " << pre[i - 1] << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}