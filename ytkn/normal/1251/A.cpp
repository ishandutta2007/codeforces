#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int dum = 0; dum < t; dum++){
        string s;
        bool flag[26];
        for(int i = 0; i < 26; i++) flag[i] = false;
        cin >> s;
       
        int cnt = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1]) {
                if(cnt%2 == 1) flag[s[i-1]-'a'] = true;
                cnt = 1;
            }else{
                cnt++;
            }
        }
        if(cnt%2 == 1) flag[s[s.size()-1]-'a'] = true;
        for(int i = 0; i < 26; i++) {
            if(flag[i]) cout << (char)('a'+i);
        }
        cout << endl;
    }
}