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
int n;
const int maxn = 1e5 + 5;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        map<int, int> mp;
        for(int i = 1;i <= n;i++){
            int x;
            cin >> x;
            if(mp.count(x) == 0){
                mp[x] = 1;
            }else{
                mp[x + 1] = 1;
            }
        } 
        cout << mp.size() << endl;
    }
    return 0;
}