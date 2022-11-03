#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
#include <queue>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;
typedef long long LL;
multiset<int> unused,sold;
const LL INF = 1e18;
const int maxn = 3e5 + 5;
int main(){
    int n;
    cin >> n;
    LL ans = 0;
    for(int i = 1;i <= n;i++){
        int x;
        scanf("%d",&x);
        LL u = unused.empty() ? INF : *unused.begin();
        LL v = sold.empty() ? INF : *sold.begin();
        if(u < v){
           if(u < x){
                ans += x - u;
               sold.insert(x);
               unused.erase(unused.begin());
           } else unused.insert(x);
        }else{
            if(v < x){
                ans += x - v;
                unused.insert(v);
                sold.erase(sold.begin());
                sold.insert(x);
            }else unused.insert(x);
        }
    }
    cout << ans << endl;
    return 0;
}