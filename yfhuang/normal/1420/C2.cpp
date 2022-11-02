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

int n, q;
int t;
const int maxn = 3e5 + 5;
int a[maxn];

int op[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        ll sum = 0;
        cin >> n >> q;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        } 
        a[n + 1] = 0;
        for(int i = 1;i <= n;i++){
            op[i] = 0;
            if(a[i] > a[i - 1] and a[i] > a[i + 1]){
                sum += a[i];
                op[i] = 1;
            }
            if(a[i] < a[i - 1] and a[i] < a[i + 1]){
                sum -= a[i];
                op[i] = 2;
            }
        }
        cout << sum << endl;
        for(int i = 1;i <= q;i++){
            int l, r;
            cin >> l >> r;
            if(l == r){
                cout << sum << endl;
                continue;
            }
            set<int> s;
            for(int j = max(1, l - 1);j <= min(l + 1, n);j++){
                s.insert(j);
            } 
            for(int j = max(1, r - 1);j <= min(r + 1, n);j++){
                s.insert(j);
            }
            for(auto j : s){
                if(op[j] == 1){
                    sum -= a[j];
                }else if(op[j] == 2){
                    sum += a[j];
                }
                op[j] = 0;
            }
            swap(a[l], a[r]);
            for(auto j : s){
                if(a[j] > a[j - 1] and a[j] > a[j + 1]){
                    sum += a[j];
                    op[j] = 1;
                }
                if(a[j] < a[j - 1] and a[j] < a[j + 1]){
                    sum -= a[j];
                    op[j] = 2;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}