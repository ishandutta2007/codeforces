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

const int maxn = 1e6 + 6;
bool ok[maxn];

void init(){
    ok[0] = 1;
    for(int i = 1;i < maxn;i++){
        if(i >= 2020){
            ok[i] |= ok[i - 2020];
        }
        if(i >= 2021){
            ok[i] |= ok[i - 2021];
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(ok[n]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}