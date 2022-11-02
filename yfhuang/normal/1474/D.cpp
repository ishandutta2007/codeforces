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

int T;
int n;
const int maxn = 2e5 + 5;
int a[maxn];
int pre[maxn], suf[maxn];
bool pre1[maxn], suf1[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        pre[0] = 0;
        pre1[0] = 1;
        for(int i = 0;i <= n + 1;i++){
            pre1[i] = suf1[i] = true;
        }
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            pre[i] = a[i] - pre[i - 1];
            pre1[i] = pre1[i - 1] & (pre[i] >= 0); 
        }
        suf[n + 1] = 0;
        suf1[n + 1] = 1;
        for(int i = n;i >= 1;i--){
            suf[i] = a[i] - suf[i + 1];
            suf1[i] = suf1[i + 1] & (suf[i] >= 0);
        }
        if(pre1[n] and pre[n] == 0){
            cout << "YES" << endl;
        }else{
            bool ok = false;
            for(int i = 1;i < n;i++){
                int x = a[i + 1] - pre[i - 1];
                int y = a[i] - suf[i + 2];
                if(x == y and x >= 0 and pre1[i - 1] and suf1[i + 2]){
                    ok = true;
                }
            }
            if(ok){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}