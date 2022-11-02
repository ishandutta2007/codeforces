#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    if(s[0] != '1') cnt++;
    for(int i = 1; i < n; i++){
        if(s[i] != '0') cnt++;
    }
    if(n == 1){
        if(k == 0){
            cout << s << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }
    if(cnt <= k){
        cout << 1;
        for(int i = 1; i < n; i++){
            cout << 0;
        }
        cout << endl;
    }else{
        if(k == 0){
            cout << s << endl;
        }else{
            if(s[0] != '1'){
                k--;
            }
            cout << 1;
            for(int i = 1; i < n; i++){
                if(s[i] != '0'){
                    if(k > 0){
                        cout << 0;
                        k--;
                    }else{
                        //cout << k << endl;
                        cout << s[i];
                    }
                }else
                {
                    cout << 0;
                }
                
            }
            cout << endl;
        }
    }
}