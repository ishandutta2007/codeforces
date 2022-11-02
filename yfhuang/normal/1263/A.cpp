#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[5];

int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 1;i < 4;i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + 3);
        a[3] = min(a[3], a[1] + a[2]);
        cout << (a[1] + a[2] + a[3]) / 2 << endl;
    }
    return 0;
}