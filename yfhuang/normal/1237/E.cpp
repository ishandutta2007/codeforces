#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
const LL mod = 998244353;

int n;

const int maxn = 1e6 + 5;

int main(){
    cin >> n;
    int cnt = 1;
    while(cnt <= n){
        if(cnt == n or cnt + 1 == n){
            cout << 1 << endl;
            return 0;
        }
        if(cnt % 2){
            cnt = (cnt + 1) * 2;
        }else{
            cnt = cnt * 2 + 1;
        }
    }
    cout << 0 << endl; 
    return 0;
}