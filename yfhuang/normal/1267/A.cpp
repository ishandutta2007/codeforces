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

typedef long long LL;
typedef pair<LL, int> pii;

const int maxn = 2e5 + 5;
int n;
LL a[maxn], b[maxn], t[maxn];

int main(){
    cin >> n;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld%lld", &a[i], &b[i], &t[i]);
        pq.push(make_pair(a[i] + t[i], i));
    }
    set<pii> active;
    LL ans = 0;
    LL curT = 0;
    while(!pq.empty()){
        pii item = pq.top(); pq.pop();
        LL time = item.first;
        int id = item.second;
        bool insert = (id > 0);
        id = abs(id);
        if(!active.empty()){
            LL v = (time - curT) / active.begin()->first;
            curT += 1LL * v * active.begin()->first;
            ans += v; 
        }
        if(insert){
            curT = max(curT, a[id]);
            active.insert(make_pair(t[id], id));
            pq.push(make_pair(b[id], -id));
        }else{
            active.erase(make_pair(t[id], id)); 
        }
    }
    cout << ans << endl;
    return 0;
}