#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
    int q;
    cin >> q;
    for(int i = 1;i <= q;i++){
        long long l, r, d;
        cin >> l >> r >> d;
        long long a = (l - 1) / d;
        if(a >= 1){
            cout << d << endl;
            continue;
        }else{
            long long b = r / d;
            cout << (b + 1) * d << endl;
            continue;
        }
    }
    return 0;
}