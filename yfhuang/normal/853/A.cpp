#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;


const int maxn = 300005;

priority_queue<pair<int,int> > pq;

int k,n;
int c[maxn];
int t[maxn * 2];
int ans[maxn];
int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d",&c[i]);
    }
    for(int i = 1;i <= k;i++){
        pq.push(make_pair(c[i],i));
    }
    for(int i = k + 1;i <= k + n;i++){
        if(i <= n){
            pq.push(make_pair(c[i],i));
        }
        pair<int,int> top = pq.top();
        pq.pop();
        t[i] = top.second;
        ans[top.second] = i;
    }
    long long res = 0;
    for(int i = 1;i <= n;i++){
        res += (ans[i] - i) * 1LL * c[i];
    }
    cout << res << endl;
    for(int i = 1;i <= n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}