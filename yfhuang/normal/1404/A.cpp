#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

int t;
int n, k;
const int maxn = 3e5 + 5;
string s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        bool flag = true;
        int cnt0 = 0, cnt1 = 0, cnt = 0;
        for(int i = 0;i < k;i++){
            int digit = -1;
            for(int j = i;j < n;j += k){
                if(s[j] != '?'){
                    if(digit == -1)
                        digit = s[j] - '0';
                    else{
                        if(digit != s[j] - '0')
                            flag = false;
                    }
                }
            }
            if(digit == -1){
                cnt++;
            }else if(digit == 0){
                cnt0++;
            }else{
                cnt1++;
            }
        }
        if(abs(cnt0 - cnt1) > cnt or !flag){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}