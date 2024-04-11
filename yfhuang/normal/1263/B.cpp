#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

string s[15];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> s[i];
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            bool flag = false;
            for(int j = 1;j <= n;j++){
                if(j == i) continue;
                if(s[j] == s[i]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans++;
                bool changed = false;
                for(int k = 0;k < 4;k++){
                    for(int digit = 1;digit < 10;digit++){
                        string tmp = s[i];
                        tmp[k] = (s[i][k] - '0' + digit) % 10 + '0';
                        bool flag = false;
                        for(int j = 1;j <= n;j++){
                            if(j == i)
                                continue;
                            if(s[j] == tmp){
                                flag = true;
                                break;
                            }
                        }
                        if(!flag){
                            s[i] = tmp;
                            changed = true;
                            break;
                        }
                    }
                    if(changed)
                        break;
                }
            }
        }
        cout << ans << endl;
        for(int i = 1;i <= n;i++){
            cout << s[i] << endl;
        }
    }
    return 0;
}