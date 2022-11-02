#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    int w, h, n;
    while(t--){
        cin >> w >> h >> n;
        int ww = 1, hh = 1;
        while(w % 2 == 0){
            ww *= 2;
            w /= 2;
        }
        while(h % 2 == 0){
            hh *= 2;
            h /= 2;
        }
        if(ww * hh >= n){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}