#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

typedef long long LL;

LL n;
int t;

set<LL> s;

int main(){
    cin >> t;
    while(t--){
        s.clear();
        cin >> n;
        LL i;
        for(i = 0;(i + 1) * (i + 1) <= n;i++){

        }
        for(int j = 0;j <= i;j++){
            s.insert(j);
        }
        for(int j = i;j >= 1;j--){
            s.insert(n / j);
        }
        bool first = false;
        cout << s.size() << endl;
        for(auto it : s){
            if(!first){
                first = true;
            }else{
                printf(" ");
            }
            printf("%lld", it);
        }
        puts("");
    }
    return 0;
}