#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x%2 == 0){
            cnt++;
        }
    }
    cout << min(cnt, n-cnt) << endl;
}