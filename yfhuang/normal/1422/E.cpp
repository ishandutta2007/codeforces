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

string s;

string get(string &x){
    if(x.size() <= 10){
        string t = x;
        reverse(t.begin(), t.end());
        return t;
    }
    string ret = "";
    for(int i = 0;i < 5;i++){
        ret += x[x.size() - 1 - i];
    }
    ret += "...";
    ret += x[1];
    ret += x[0];
    return ret;
}

const int maxn = 1e5 + 5;

char pnx[maxn];
int len[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    string suf = "";
    int n = s.length();
    bool canpop = false;
    vector<string> ans;
    char nx = '\0';
    pnx[n] = nx;
    for(int i = n - 1;i >= 0;i--){
        if(suf.size() == 0){
            suf += s[i];
            canpop = true;
        }else if(suf.back() == s[i]){
            if(nx < suf.back() and canpop){
                canpop = false;
                nx = pnx[i + 2];
                suf.pop_back();
            }else{
                suf += s[i];
                canpop = true;
            }
        }else{
            nx = suf.back();
            suf += s[i];
            canpop = true;
        }
        len[i] = suf.length();
        ans.push_back(get(suf));
        pnx[i] = nx;
    }
    for(int i = n - 1;i >= 0;i--){
        cout << len[n - 1 - i] << " " << ans[i] << endl;
    }
    return 0;
}