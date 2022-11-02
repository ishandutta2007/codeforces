#include <iostream>

using namespace std;

int cnt[200000];
typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string s;
        cin >> s;
        int c = 0;
        int ans = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '0'){
                c++;
                cnt[j] = 0;
            }else{
                cnt[j] = c;
                c = 0;
            }
        }
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '0') continue;
            int tmp = 0;
            for(int k = 0; k+j < s.size() && k < 20; k++){
                if(s[k+j] == '1') tmp++;
                if(cnt[j]+k+1 >= tmp) ans++;
                tmp *= 2;
            }
        }
        cout << ans << endl;
    }
}