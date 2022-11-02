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
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> x(n, 0);
        for(int i = 0;i < n;i++){
            cin >> x[i];
        }
        set<int> s;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                s.insert(x[j] - x[i]);
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}