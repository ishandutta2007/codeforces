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

int n;
ll T;
string s;

ll cnt[30];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> T;
    cin >> s;
    for(int i = 0;i < n;i++){
        int k = s[i] - 'a';
        T -= (1LL << k) * ((i == n - 1) * 2 - 1);
        cnt[k] += i < n - 2;
    }
    if(T < 0){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 25;i >= 0;i--){
        ll w = min(T >> i + 1, cnt[i]);
        T -= w << (i + 1);
    }
    if(!T)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}