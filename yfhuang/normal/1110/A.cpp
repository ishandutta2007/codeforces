#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];

int main(){
    int b, k;
    while(cin >> b >> k){
        int now = 1;
        int mod = 0;
        for(int i = 1;i <= k;i++){
            scanf("%d", a + i);
        }
        for(int i = k;i >= 1;i--){
            mod = (a[i] * now + mod) % 2;
            now = now * b % 2;
        }
        if(mod)
            cout << "odd" << endl;
        else
            cout << "even" << endl;
    }
    return 0;
}