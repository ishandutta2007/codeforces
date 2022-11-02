#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

vector<string> a, b;
const int maxn = 105;
vector<string> s[maxn], t[maxn], e[maxn];
bool vis[maxn][maxn];
int n;
int cnt[maxn];
int cnt1[maxn];

vector<string> ask(int l, int r){
    cout << "? " << l << " " << r << endl;
    fflush(stdout);
    int num = (r - l + 1);
    vector<string> ans(0);
    for(int i = 1;i <= num * (num + 1) / 2;i++){
        string s;
        cin >> s;
        ans.push_back(s);
    }
    return ans;
}

void solve(){
    a = ask(1, n);
    if(n == 1){
        cout << "! " << a[0] << endl;
        fflush(stdout);
        return;
    }
    b = ask(2, n);
    for(auto str : a){
        int len = str.length();
        string x = str;
        sort(x.begin(), x.end());
        s[len].push_back(x);
    } 
    for(auto str : b){
        int len = str.length();
        sort(str.begin(), str.end());
        string x = str;
        sort(x.begin(), x.end());
        t[len].push_back(x);
    }
    for(int len = 1;len <= n;len++){
        for(auto str : s[len]){
            bool flag = false;
            for(int j = 0;j < t[len].size();j++){
                string now = t[len][j];
                if(vis[len][j])
                    continue;
                if(now == str){
                    flag = true;
                    vis[len][j] = true;
                    break;
                }
            }
            if(!flag){
                e[len].push_back(str);
                break;
            }
        }
    }
    string ans = "";
    for(int i = 1;i <= n;i++){
        memset(cnt, 0, sizeof(cnt));
        string s = e[i][0];
        for(int j = 0;j < s.length();j++){
            cnt[s[j] - 'a']++;
        }        
        for(int j = 0;j < 26;j++){
            if(cnt[j] != cnt1[j]){
                ans.push_back(j + 'a');
                cnt1[j] = cnt[j];
                break;
            }
        }
    }
    cout << "! " << ans << endl;
    fflush(stdout);
}

int main(){
    cin >> n;
    solve();
    return 0;
}