#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int sqr[1000];

int main(){
    int k;
    for(int i = 1;i < 1000;i++){
        sqr[i] = i * i;
    }
    cin >> k;
    string ans = "";
    if(k == 0){
        ans = "a";
        cout << ans << endl;
        return 0;
    }
    int now = 0;
    while(k >= 4){
        int id = upper_bound(sqr + 1,sqr + 990,k) - sqr;
        id--;
        for(int i = 1;i <= id;i++){
            ans += (char)('a' + now);
        }
        now++;
        for(int i = 1;i <= id + 1;i++){
            ans += (char)('a' + now);
        }
        now++;
        k -= sqr[id];
    }
    if(k == 1) {ans += (char)('a' + now);ans += (char)('a' + now);}
    else if(k == 2){
        ans += (char)('a' + now);
        ans += (char)('a' + now);
        now++;
        ans += (char)('a' + now);
        ans += (char)('a' + now);
    }else if(k == 3){
        ans += (char)('a' + now);
        ans += (char)('a' + now);
        ans += (char)('a' + now);
    }
    cout << ans << endl;
    return 0;
}