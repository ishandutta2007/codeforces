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

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    ll n;
    cin >> t;
    while(t--){
        cin >> n;
        while(n % 2 == 0){
            n /= 2;
        }
        if(n > 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}