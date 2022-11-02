#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

ll l[200000], r[200000], s;
typedef pair<ll, ll> P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int dum = 0; dum < t; dum++){
        int n;
        cin >> n >> s;
        for(int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
        }
        ll l_ = 0, r_ = 1e+10;
        while(r_ - l_ > 1){
            ll c = (r_+l_)/2;
            vector<P> p;
            ll tmp = 0;
            int cnt = 0;
            int r_cnt = 0;
            for(int i = 0; i < n; i++){
                if(r[i] < c) {
                    tmp += l[i];
                    cnt++;
                }
                else if(l[i] > c) tmp += l[i];
                else p.push_back(P(l[i], r[i]));
            }
            if(cnt > n/2) {
                r_ = c;
                continue;
            }
            sort(p.begin(), p.end());
            for(int i = 0; i < p.size(); i++){
                if(cnt < n/2)tmp += p[i].first;
                else tmp += c;
                cnt++;
            }
            //cout << tmp << endl;
            if(tmp > s) r_ = c;
            else l_ = c;
        }
        cout << l_ << endl;
    }
}