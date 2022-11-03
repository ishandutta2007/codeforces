#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    long long sum = 0;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        sum += x;
        a.push_back(x - y);
    }
    sort(a.begin(), a.end());
    int batas = -1;
    for(int i = 0; i < n; i++){
        if(a[i] <= 0) batas = i;
    }
    // cout << batas << '\n';

    vector<long long> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];

    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        long long x0, y0, g;

        bool res = find_any_solution(a, b, n, x0, y0, g);
        // cout << x0 << ' ' << y0 << ' ' << g << endl;
        if(!res){
            cout << "-1\n";
            continue;
        }
        
        long long lo, hi, mid, ans = -1;
        if(x0 < 0) lo = (-x0 + b/g - 1) / (b / g);
        else{
            lo = -(x0 / (b / g));
        }

        if(y0 < 0) hi = -((-y0 + a / g - 1) / (a / g));
        else hi = y0 / (a / g);

        long long ll = lo, hh = hi;
        ll = ll - 1000000;
        hh = hh + 1000000;

        while(lo <= hi){
            mid = (lo + hi) / 2;
            assert(lo <= mid && mid <= hi);
            long long x1 = x0 + mid * b / g;
            long long y1 = y0 - mid * a / g;
            long long xx = x1 * a;
            long long yy = y1 * b;
            // cout << x1 << ' ' << y1 << ' ' << x0 << ' ' << y0 << ' ' << mid << endl;
            assert(xx + yy == n);
            if(x1 < 0){ 
                lo = mid + 1;
                continue;
            }
            if(y1 < 0){ 
                hi = mid - 1;
                continue;
            }
            long long i = yy - 1;
            if(i <= batas){
            // cout << "2 -> " << i << ' ' << sum << ' ' << pref[i] << endl;
                hi = mid - 1;
                long long jadi = sum;
                if(i >= 0) jadi -= pref[i];
                ans = max(ans, jadi);
            }
            else{
                lo = mid + 1;
            }
        }

        lo = ll;
        hi = hh;

        while(lo <= hi){
            mid = (lo + hi) / 2;
            long long x1 = x0 + mid * b / g;
            long long y1 = y0 - mid * a / g;
            long long xx = x1 * a;
            long long yy = y1 * b;
            assert(xx + yy == n);
            if(x1 < 0){ 
                lo = mid + 1;
                continue;
            }
            if(y1 < 0){ 
                hi = mid - 1;
                continue;
            }
            long long i = yy - 1;
            if(i > batas){
            // cout << "2 -> " << i << ' ' << sum << ' ' << pref[i] << endl;
                lo = mid + 1;
                long long jadi = sum - pref[i];
                ans = max(ans, jadi);
            }
            else{
                hi = mid - 1;
            }
        }

        cout << ans << '\n';

    }

    
}