#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500;

int n, a[N];

int ans[N];
int ul[N], dl[N];
int ur[N], dr[N];
int dpl[N], dpr[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        ans[i] = i;

    for(int i = 1; i <= n; i++){
        ul[i] = i;
        dl[i] = i;
        if(i > 1){
            if(a[i - 1] < a[i])
                dl[i] = dl[i - 1];
            else
                ul[i] = ul[i - 1];
        }
    }
    for(int i = n; i >= 1; i--){
        ur[i] = i;
        dr[i] = i;
        if(i < n){
            if(a[i] > a[i + 1])
                dr[i] = dr[i + 1];
            else
                ur[i] = ur[i + 1];
        }
    }
    for(int i = n - 1; i >= 1; i--){
        dpr[i] = i + 1;
        if(a[i] < a[i + 1]){
            dpr[i] = ur[i + 1];
            if(1 <= ur[i + 1] + 1 && ur[i + 1] + 1 <= n && a[i] > a[ur[i + 1] + 1])
                dpr[i] = dpr[ur[i + 1]];
        }else{
            dpr[i] = dr[i + 1];
            if(1 <= dr[i + 1] + 1 && dr[i + 1] + 1 <= n && a[i] < a[dr[i + 1] + 1])
                dpr[i] = dpr[dr[i + 1]];
        }
    }
    for(int i = 2; i <= n; i++){
        dpl[i] = i - 1;
        if(a[i - 1] < a[i]){
            dpl[i] = dl[i - 1];
            if(1 <= dl[i - 1] - 1 && dl[i - 1] - 1 <= n && a[dl[i - 1] - 1] > a[i])
                dpl[i] = dpl[dl[i - 1]];
        }else{
            dpl[i] = ul[i - 1];
            if(1 <= ul[i - 1] - 1 && ul[i - 1] - 1 <= n && a[ul[i - 1] - 1] < a[i])
                dpl[i] = dpl[ul[i - 1]];
        }
    }
    for(int i = 1; i <= n - 1; i++){
        int l = i, r = i + 1;
        r = dpr[i];
        if(a[i] < a[i + 1]){
            l = ul[i];
            if(1 <= ul[i] - 1 && ul[i] - 1 <= n && a[ul[i] - 1] < a[i + 1])
                l = dpl[ul[i]];
        }else{
            l = dl[i];
            if(1 <= dl[i] - 1 && dl[i] - 1 <= n && a[dl[i] - 1] > a[i + 1])
                l = dpl[dl[i]];
        }
        ans[l] = max(ans[l], r);
    }

    for(int i = 2; i <= n; i++){
        int l = i - 1, r = i;
        l = dpl[i];
        if(a[i - 1] < a[i]){
            r = dr[i];
            if(1 <= dr[i] + 1 && dr[i] + 1 <= n && a[i - 1] < a[dr[i] + 1])
                r = dpr[dr[i]];
        }else{
            r = ur[i];
            if(1 <= ur[i] + 1 && ur[i] + 1 <= n && a[i - 1] > a[ur[i] + 1])
                r = dpr[ur[i]];
        }
        ans[l] = max(ans[l], r);
    }
    for(int i = 1; i <= n; i++) {
        ans[i] = max(ans[i], ur[i]);
        ans[i] = max(ans[i], dr[i]);
    }
    ll s = 0;
    for(int i = 1, j = 0; i <= n; i++){
        j = max(j, ans[i]);
        s += j - i + 1;
    }
    cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
    int t = 1;
//    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}