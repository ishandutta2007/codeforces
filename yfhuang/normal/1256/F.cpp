#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int q, n;
const int maxn = 2e5 + 5;

char s[2][maxn];
int cnt[2][30];
int p[maxn];
int main(){
    cin >> q;
    while(q--){
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", s[0] + 1);
        scanf("%s", s[1] + 1);
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < 2;j++){
                int idx = s[j][i] - 'a';
                cnt[j][idx]++;
            }
        }
        bool flag = true;
        for(int i = 0;i < 30;i++){
            if(cnt[0][i] != cnt[1][i]){
                flag = false;
            }
        }
        if(flag){
            bool flag = false;
            for(int i = 0;i < 30;i++){
                if(cnt[0][i] > 1)
                    flag = true;
            }
            if(flag){
                cout << "YES" << endl;
            }else{
                for(int i = 1;i <= n;i++){
                    int idx = s[0][i] - 'a';
                    cnt[0][idx] = i;
                }
                for(int i = 1;i <= n;i++){
                    int idx = s[1][i] - 'a';
                    p[i] = cnt[0][idx];
                }
                int rev = 0;
                for(int i = 1;i <= n;i++){
                    for(int j = i + 1;j <= n;j++){
                        if(p[j] < p[i]){
                            rev++;
                        }
                    }
                }
                if(rev % 2){
                    cout << "NO" << endl;
                }else{
                    cout << "YES" << endl;
                }
            }
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}