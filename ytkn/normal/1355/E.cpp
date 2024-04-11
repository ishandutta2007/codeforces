#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int N;
ll A, R, M;
ll h[100000];
vector<ll> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N >> A >> R >> M;
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> h[i];
        sum += h[i];
        v.push_back(h[i]);
    }
    sort(h, h+N);
    ll ave = sum/N;
    v.push_back(ave); v.push_back(ave+1);
    sort(v.begin(), v.end());
    ll suml = 0;
    ll sumr = sum;
    int idx = 0;
    ll ans = 2e18;
    M = min(M, A+R);
    for(ll i : v){
        while(h[idx] < i && idx < N){
            suml += h[idx];
            sumr -= h[idx];
            idx++;
        }
        ll tmp;
        ll sl = (i*(idx)-suml);
        ll sr = sumr-i*(N-idx);
        if(sl < sr){
            tmp = sl*M+(sr-sl)*R;
        }else{
            tmp = sr*M+(sl-sr)*A;            
        }
        // cout << i << ' ' << idx << ' ' << h[idx] << ' ' << tmp << ' ' << suml << ' ' << sumr << endl;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}