#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n, d, e;

int main(){
    while(cin >> n >> d >> e){
        int ans = n;
        e *= 5;
        for(int i = 0;i <= e;i++){
            if(n >= i * d){
                ans = min(ans, (n - i * d) % e);
            }
        }
        cout << ans << endl;
    }
    return 0;
}