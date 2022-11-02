#include <iostream>

using namespace std;

bool used[10];
void clear(){
    for(int i = 0; i < 10; i++){
        used[i] = false;
    }
}

int main(){
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r; i++){
        string s = to_string(i);
        clear();
        for(int j = 0; j < s.size(); j++){
            if(used[s[j] - '0']) break;
            used[s[j] - '0'] = true;
            if(j+1 == s.size()){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}