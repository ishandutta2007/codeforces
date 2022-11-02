#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 3e5 + 5;
char s[maxn];

int main(){
    int n;
    cin >> n;
    scanf("%s", s + 1);
    if(n & 1){
        cout << ":(" << endl;
    }else{
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1;i <= n;i++){
            if(s[i] == '(')
                cnt1++;
            else if(s[i] == ')')
                cnt2++;
        }
        if(cnt1 > n / 2 || cnt2 > n / 2){
            cout << ":(" << endl;
        }else{
            for(int i = 1;i <= n;i++){
                if(s[i] == '?'){
                    if(cnt1 < n / 2){
                        s[i] = '(';
                        cnt1++;
                    }else{
                        s[i] = ')';
                    }
                }
            }
            int ans = 0;
            bool flag = true;
            for(int i = 1;i <= n;i++){
                if(s[i] == '(')
                    ans++;
                else
                    ans--;
                if(i < n && ans <= 0)
                    flag = false;
            }
            if(flag){
                printf("%s", s + 1);
            }else{
                cout << ":(" << endl;   
            }
        }
    }
    return 0;
}