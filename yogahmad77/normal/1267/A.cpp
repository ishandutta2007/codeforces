#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char, int> pci;
#define sz(x) ((int)x.size())
#define f first
#define s second
#define mp make_pair

struct interval{
    long long l, r, t;
    bool operator < (interval other) const {
        return l < other.l;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<interval> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].l >> a[i].r >> a[i].t;
    sort(a.begin(), a.end());
    long long ans = 0;
    long long di = a[0].l;
    int now = 1;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({a[0].t, a[0].r});
    while(1){
        while(now < n && a[now].l <= di){
            pq.push({a[now].t, a[now].r});
            now += 1;
        }
        while(!pq.empty() && pq.top().s <= di) pq.pop();
        if(pq.empty()){
            if(now == n) break;
            di = a[now].l;
            pq.push({a[now].t, a[now].r});
            now += 1;
            continue;
        }
        if(now == n || pq.top().s <= a[now].l){
            long long brp = (pq.top().s - di) / pq.top().f;
            ans += brp;
            di += brp * pq.top().f;
            pq.pop();
            continue;
        }
        long long brp = (a[now].l - di) / pq.top().f;
        ans += brp;
        di += brp * pq.top().f;
        if(di + pq.top().f <= pq.top().s){
            pq.push({pq.top().f - (a[now].l - di), di + pq.top().f});
            di = a[now].l;
        }
        else pq.pop();
    }
    cout << ans << endl;
}