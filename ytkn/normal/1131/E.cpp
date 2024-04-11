#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int n;
string p[100000];

bool all_same(string s){
    for(char c : s){
        if(c != s[0]) return false;
    }
    return true;
}

bool contains(string s, char c){
    for(char i : s){
        if(c == i) return true;
    }
    return false;
}

int head_len(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] != s[0]) return i;
    }
    return s.size();
}

int tail_len(string s){
    int sz = s.size();
    for(int i = 0; i < sz; i++){
        if(s[sz-i-1] != s[sz-1]) return i;
    }
    return s.size();
}

int calc_max_same(string s){
    char c = s[0];
    int cnt = 1;
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        if(c != s[i]){
            ans = max(ans, cnt);
            c = s[i];
            cnt = 1;
        }else{
            cnt++;
        }
    }
    ans = max(ans, cnt);
    return ans;
}

int calc_max_len(string s, char c){
    int cnt = 0;
    int ans = 0;
    for(char i : s){
        if(i == c) cnt++;
        else cnt = 0;
        ans = max(ans, cnt);
    }
    return ans;
}

void solve_all_same(){
    int cur = 0;
    for(int i = 1; i < n; i++){
        if(!all_same(p[i])) break;
        if(p[i][0] != p[0][0]) break;
        cur = i;
    }
    int len = p[0].size();
    for(int i = 1; i <= cur; i++){
        len = len*(p[i].size()+1)+p[i].size();
    }
    int ans = len;
    for(int i = cur+1; i < n; i++){
        int tmp = calc_max_len(p[i], p[0][0]);
        if(i == cur+1) ans = max(ans, len*(tmp+1)+tmp);
        else if(tmp != 0) ans = max(ans, 2*len+1);
    }
    cout << ans << endl;
}

void solve_same_head_tail(){
    int ans = calc_max_same(p[0]);
    int head = head_len(p[0]);
    int tail = tail_len(p[0]);
    for(int i = 1; i < n; i++){
        if(contains(p[i], p[0][0])){
            cout << head+tail+1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

void solve_else(){
    int ans = calc_max_same(p[0]);
    int head = head_len(p[0]);
    int tail = tail_len(p[0]);
    for(int i = 1; i < n; i++){
        if(contains(p[i], p[0][0])){
            ans = max(ans, head+1);
        }
        if(contains(p[i], p[0][p[0].size()-1])){
            ans = max(ans, tail+1);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[n-i-1];
    }
    int sz = p[0].size();
    if(all_same(p[0])){
        solve_all_same();
    }else if(p[0][0] == p[0][sz-1]){
        solve_same_head_tail();
    }else{
        solve_else();
    }
}