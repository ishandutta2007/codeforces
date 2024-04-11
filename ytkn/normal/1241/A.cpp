#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        long n;
        cin >> n;
        if(n <= 3){
            cout << 4-n << endl;
        }else{
            if(n%2 == 0){
                cout << 0 << endl;
            }else{
                cout << 1 << endl;
            }
        }
    }
}