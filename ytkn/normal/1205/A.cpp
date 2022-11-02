#include <iostream>

using namespace std;

int ans[200000];

int main(){
    int n;
    cin >> n;
    if(n%2 == 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if(i%2 == 0) cout << i*2+1 << ' ';
            else cout << (i+1)*2 << ' ';
        }
        for(int i = 0; i < n-1; i++){
            if(i%2 == 0) cout << (i+1)*2 << ' ';
            else  cout << (i+1)*2-1 << ' ';
        }
        if(n%2 == 1) cout << n*2 << endl;
        else cout << n*2-1 << endl;
    }
}