#include <iostream>

using namespace std;

int main(){
    string x, y;
    int t;
    cin >> t;
    for(int j = 0; j < t; j++){
        cin >> x >> y;
        int a, b;
        for(int i = 0; i < y.size(); i++){
            if(y[y.size()-i-1] == '1'){
                b = i;
                break;
            }
        }
        for(int i = b; i < x.size(); i++){
            if(x[x.size()-i-1] == '1'){
                a = i;
                break;
            }
        }
        //cout << a << ' ' << b << endl;
        cout << a-b << endl;
    }
}