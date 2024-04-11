#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool useds[26], usedt[26];
void clear(){
    for(int i = 0; i < 26; i++) {
        useds[i] = false;
        usedt[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    for(int dummy = 0; dummy < q; dummy++){
        string s, t;
        cin >> s >> t;
        clear();
        for(int i = 0; i < s.size(); i++){
            useds[s[i]-'a'] = true;
        }
        for(int i = 0; i < t.size(); i++){
            usedt[t[i]-'a'] = true;
        }
        for(int i = 0; i < 26; i++){
            if(useds[i] && usedt[i]){
                cout << "YES" << endl;
                break;
            }
            if(i == 25){
                cout << "NO" << endl;
            }
        }
    }
}