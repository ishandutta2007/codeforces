#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int k, n;
const int maxn = 2e5 + 5;
int a[maxn];
char s[maxn];
priority_queue<int> pq;
int main(){
    while(cin >> n >> k){
        for(int i = 1;i <= n;i++){
            scanf("%d", a + i);
        }
        scanf("%s", s + 1);
        long long ans = 0;
        for(int i = 1, j = 1;i <= n;i = j + 1, j = i){
            while(j + 1 <= n && s[j + 1] == s[i])
                j++;
            for(int l = i;l <= j;l++){
                pq.push(a[l]);
            }
            int cnt = 0;
            while(!pq.empty() && cnt < k){
                ans += pq.top();
                pq.pop();
                cnt++;
            }
            while(!pq.empty()){
                pq.pop();
            }
        }
        cout << ans << endl;
    }
    return 0;
}