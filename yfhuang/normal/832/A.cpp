#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
long long n,k;
int main(){
    while(cin >> n >> k){
        long long t = (n) / k;
        if(t & 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}