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
string s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        int ans = 0;
        for(int i = 1;i < s.length();i++){
            if(i - 1 >= 0){
                if(s[i] == s[i - 1]){
                    s[i] = '!';
                    ans++;
                }
            }
            if(s[i] == '!')
                continue;
            if(i - 2 >= 0){
                if(s[i] == s[i - 2]){
                    s[i] = '!';
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}