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
    int n;
    while(t--){
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0;i < n;i++){
            cin >> a[i];
            if(a[i] == 1){
                cnt1++;
                sum += 1;
            }else{
                cnt2++;
                sum += 2;
            }
        }
        if(sum & 1){
            cout << "NO" << endl;
        }else{
            if(cnt1 >= 2){
                cout << "YES" << endl;
            }else{
                if(cnt2 & 1){
                    cout << "NO" << endl;
                }else{
                    cout << "YES" << endl;
                }
            }
        }
    }
    return 0;
}