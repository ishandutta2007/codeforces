#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        cin >> s;
        sort(s.begin(), s.end());
        if(k == 1){
            cout << s << endl;
        }else if(k == n){
            cout << s[k - 1] << endl;
        }
        else{
            if(s[0] != s[k - 1]){
                cout << s[k - 1] << endl;
            }else{
                string s1 = s.substr(0, 1);
                string s2 = s.substr(k, n - k);
                bool flag = true;
                for(int i = 0;i < s2.length() - 1;i++){
                    if(s2[i] != s2[i + 1])
                        flag = false;
                }
                if(!flag)
                    cout << s1 + s2 << endl;
                else{
                    int len = (n - 1) / k; 
                    string s3 = s.substr(k, len);
                    cout << s1 + s3 << endl;
                }
            }
        }
    } 
    return 0;
}