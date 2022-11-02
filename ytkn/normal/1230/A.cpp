#include <iostream>

using namespace std;

int main(){
    int a[4];
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < 4; i++) {
        if(a[i]*2 == sum){
            cout << "YES" << endl;
            return 0;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < i; j++){
            int tmp = a[i]+a[j];
            if(tmp*2 == sum){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}