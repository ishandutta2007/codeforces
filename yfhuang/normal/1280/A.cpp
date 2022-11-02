#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int t;
int x;
const int maxn = 6e6 + 5;
char s[maxn];
typedef long long LL;
const LL mod = 1e9 + 7;

int main(){
    cin >> t;
    while(t--){
        cin >> x;
        scanf("%s", s);
        LL cur = 0;
        long long len = strlen(s);
        bool flag = false;
        for(cur = 1;cur <= x;cur++){
            if(s[cur - 1] == '1'){
                //cout << len << endl;
                continue;
            }
            LL len1 = (len - cur + mod) % mod;
            if(len >= x)
                flag = true;
            if(flag){
                len = (len + (s[cur - 1] - '1') * len1) % mod;
                //cout << len << endl;
                continue;
            }
            len = (len + (s[cur - 1] - '1') * len1) % mod;
            for(int i = 1;i < s[cur - 1] - '0';i++){
                for(int j = cur;j < len;j++){
                    s[j + i * len1] = s[j];
                }
            }
            //cout << len << endl;
        }
        cout << len << endl;
    }
    return 0;
}