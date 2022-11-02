#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        string t;
        cin >> t;
        bool flag = true;
        int n = t.length();
        for(int i = 0;i < n - 1;i++){
            if(t[i] != t[i + 1]){
                flag = false;
            }
        }
        if(flag){
            cout << t << endl;
        }else{
            string s = "";
            for(int i = 0;i < n;i++){
                s.push_back('0');
                s.push_back('1');
            }
            cout << s << endl;
        }

    }
    return 0;
}