#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

LL n, b;
vector<pair<LL,LL>> Div;

int main(){
    while(cin >> n >> b){
        Div.clear();
        LL tmp = b;
        for(LL i = 2;i * i <= b;i++){
            if(tmp % i == 0){
                LL now = 0;
                while(tmp % i == 0){
                    tmp /= i;
                    now++;
                }
                Div.push_back(make_pair(i, now));
            }
        }
        if(tmp > 1){
            Div.push_back(make_pair(tmp, 1));
        }
        if(Div.size() == 0){
            puts("1");
        }else{
            LL ans = 1e18;
            for(auto d: Div){
                LL num = d.first;
                LL pw = d.second;
                LL tmp = 1;
                LL ret = 0;
                while(n / num >= tmp){
                    tmp *= num;
                    ret +=  (n / tmp);
                }
                ans = min(ans, ret / pw);
            }
            cout << ans << endl;
        }
    }
    return 0;
}