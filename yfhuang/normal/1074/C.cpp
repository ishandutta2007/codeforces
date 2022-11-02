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

const int maxn = 3e5 + 5;

int n;
int x[maxn], y[maxn];

pair<int, pair<int, int> > p[maxn];

int U[maxn], D[maxn], L[maxn], R[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    int mxx = x[1], mix = x[1];
    int mxy = y[1], miy = y[1];
    for(int i = 2;i <= n;i++){
        mxx = max(mxx, x[i]);
        mix = min(mix, x[i]);
        miy = min(miy, y[i]);
        mxy = max(mxy, y[i]);
    }
    for(int i = 1;i <= n;i++){
        p[i] = make_pair(x[i], make_pair(y[i], i));
    } 
    sort(p + 1, p + 1 + n);
    int mx = p[1].second.first;
    int mi = p[1].second.first;
    for(int i = 1;i <= n;i++){
        mx = max(p[i].second.first, mx);
        mi = min(p[i].second.first, mi);
        int id = p[i].second.second;
        U[id] += mx - p[i].second.first;
        D[id] += p[i].second.first - mi;
    }
    mx = p[n].second.first;
    mi = p[n].second.first;
    for(int i = n;i >= 1;i--){
        mx = max(p[i].second.first, mx);
        mi = min(p[i].second.first, mi);
        int id = p[i].second.second;
        L[id] += mx - p[i].second.first;
        R[id] += p[i].second.first - mi;
    }
    for(int i = 1;i <= n;i++){
        p[i] = make_pair(y[i], make_pair(x[i], i));
    }
    sort(p + 1, p + 1 + n);
    mx = p[1].second.first;
    mi = p[1].second.first;
    for(int i = 1;i <= n;i++){
        mx = max(p[i].second.first, mx);
        mi = min(p[i].second.first, mi);
        int id = p[i].second.second;
        R[id] += mx - p[i].second.first;
        D[id] += p[i].second.first - mi;
    }
    mx = p[n].second.first;
    mi = p[n].second.first;
    for(int i = n;i >= 1;i--){
        mx = max(p[i].second.first, mx);
        mi = min(p[i].second.first, mi);
        int id = p[i].second.second;
        L[id] += mx - p[i].second.first;
        U[id] += p[i].second.first - mi;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans, 2*U[i]);
        ans = max(ans, 2*L[i]);
        ans = max(ans, 2*D[i]);
        ans = max(ans, 2*R[i]);
    }
    cout << ans;
    for(int i = 4;i <= n;i++){
        printf(" %d", 2 * ((mxx - mix) + (mxy - miy)));
    }
    puts("");
    return 0;
}