#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;
int main(){
    int n;
    cin >> n;
    long long k, x;
    while(n--){
        cin >> k >> x;
        cout << (k - 1) * 9 + x << endl;
    }
    return 0;
}