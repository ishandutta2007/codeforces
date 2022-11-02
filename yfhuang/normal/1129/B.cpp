#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
vector<LL> ans;
int main(){
    LL K;
    cin >> K;
    LL S = -1;
    ans.push_back(-1);
    while(S < K){
        LL diff = K - S;
        LL mod;
        if(diff < 1000000){
            mod = diff + 1;
        }else{
            mod = 1000000;    
        }
        ans.push_back(mod);
        S += mod - 1;
    }
    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x << " ";
    }
    return 0;
}