#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int dum = 0; dum < t; dum++){
        string s;
        cin >> s;
        string s1, s2;
        for(int i = 0; i < s.size(); i++){
            int n = s[i]-'0';
            if(n%2 == 0) s1 += s[i];
            else s2 += s[i];
        }
        int i1 = 0, i2 = 0;
        for(int i = 0; i < s.size(); i++){
            if(i1 == s1.size()) {
                cout << s2[i2];
                i2++;
            }else if(i2 == s2.size()){
                cout << s1[i1];
                i1++;
            }else{
                if(s1[i1] < s2[i2]) {
                    cout << s1[i1];
                    i1++;
                }else{
                    cout << s2[i2];
                    i2++;
                }
            }
        }
        cout << endl;
    }
}