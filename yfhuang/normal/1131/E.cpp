#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

LL ans[30];
int n;
string s, t;
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    for(char ch = 'a';ch <= 'z';ch++){
        LL now = 0;
        for(int i = 0;i < s.length();i++){
            if(s[i] == ch){
                now++;
                int id = ch - 'a';
                ans[id] = max(ans[id], now);
            }else{
                now = 0;
            }
        }
    }
    for(int i = 2;i <= n;i++){
        char l, r;
        int llen = 1, rlen = 1;
        cin >> s;
        int tmp = 0; 
        l = s[0];
        r = s[s.length() - 1];
        while(tmp + 1 < s.length()){
            if(s[tmp + 1] == s[tmp])
                tmp++;
            else
                break;
        }
        llen = tmp + 1;
        tmp = s.length() - 1;
        while(tmp - 1 >= 0){
            if(s[tmp - 1] == s[tmp])
                tmp--;
            else
                break;
        }
        rlen = s.length() - tmp;
        if(llen == s.length()){
            for(char ch = 'a';ch <= 'z';ch++){
                int id = ch - 'a';
                if(ch != l){
                    if(ans[id] > 0){
                        ans[id] = 1;
                    }
                }else{
                    ans[id] = 1LL * (ans[id] + 1) * (llen + 1) - 1; 
                    if(ans[id] > 1e9)
                        ans[id] = 1e9;
                }
            }
        }else{
            for(char ch = 'a';ch <= 'z';ch++){
                int id = ch - 'a';
                if(ans[id] == 0){
                    continue;
                }
                int tmp = 1;
                if(ch == l)
                    tmp += llen;
                if(ch == r)
                    tmp += rlen;
                ans[id] = tmp;
            }
            for(char ch = 'a';ch <= 'z';ch++){
                LL now = 0;
                for(int j = 0;j < s.length();j++){
                    if(s[j] == ch){
                        now++;
                        int id = ch - 'a';
                        ans[id] = max(ans[id], now);
                    }else{
                        now = 0;
                    }
                }
            }
        }
    } 
    LL ret = 0;
    for(int i = 0;i < 26;i++){
        ret = max(ret, ans[i]);
    }
    cout << ret << endl;
    return 0;
}