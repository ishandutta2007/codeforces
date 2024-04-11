#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int dum = 0; dum < t; dum++){
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        int r = 0, p = 0, s = 0;
        string S;
        cin >> S;
        for(int i = 0; i < n; i++){
            if(S[i] == 'R') r++;
            if(S[i] == 'P') p++;
            if(S[i] == 'S') s++;
        }
        string ans(n, 'a');
        int a_ = a-s, b_ = b-r, c_ = c-p;
        int win = min(r, b)+min(p, c)+min(s, a);
        if(win*2 >= n){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                if(S[i] == 'R'){
                    if(b > 0){
                        ans[i] = 'P';
                        b--;
                        win--;
                    }else{
                        if(c_ > 0 && c > 0){
                            ans[i] = 'S';
                            c--;
                            c_--;
                        }else{
                            ans[i] = 'R';
                            a--;
                            a_--;
                        }
                    }
                }
                if(S[i] == 'P') {
                    if(c > 0){
                        ans[i] = 'S';
                        c--;
                        win--;
                    }else{
                        if(a_ > 0 && a > 0){
                            ans[i] = 'R';
                            a--;
                            a_--;
                        }else{
                            ans[i] = 'P';
                            b--;
                            b_--;
                        }
                    }
                }
                if(S[i] == 'S') {
                    if(a > 0){
                        ans[i] = 'R';
                        a--;
                        win--;
                    }else{
                        if(b_ > 0 && b > 0){
                            ans[i] = 'P';
                            b--;
                            b_--;
                        }else{
                            ans[i] = 'S';
                            c--;
                            c_--;
                        }
                    }
                }
            }
            cout << ans << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}