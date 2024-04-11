#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

string s[50];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int Q;
    cin >> Q;
    for(int dum = 0; dum < Q; dum++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        int cnt = 0;
        int odd = 0;
        for(int i = 0; i < n; i++){
            if(s[i].size()%2 == 1) odd++;
            for(int j = 0; j < s[i].size(); j++){
                if(s[i][j] == '0') cnt++;
            }
        }
        if(cnt%2 == 1 && odd == 0){
            cout << n-1 << endl;
        }else{
            cout << n << endl;
        }
    }
}