#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int l = 0, r = 0;
    int N;
    cin >> N;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        ll a;
        cin >> a;
        sum += a;
        if(i%2 == 0) l += (a%2);
        if(i%2 == 1) r += (a%2);
    }
    cout << (sum-abs(r-l))/2 << endl;
}