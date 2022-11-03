#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1e5 + 5;

int a[maxn];


int main(){
    int n, m, k;
    while(cin >> n >> m >> k){
        priority_queue<int> pq;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
            if(i > 1){
                pq.push(a[i] - a[i - 1] - 1); 
            }
        }
        int ans = a[n] - a[1] + 1;
        while(--k){
            ans -= pq.top();pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}