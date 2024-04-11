#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int q;
const int maxn = 2e5 + 5;

map<int, int> fa;
map<int, int> val;

int Find(int x){
    if(fa.count(x) == 0){
        fa[x] = x;
        val[x] = 0;
        return fa[x];
    }
    if(x == fa[x]){
        return fa[x];
    }
    int fx = Find(fa[x]);
    val[x] ^= val[fa[x]];
    fa[x] = fx;
    return fa[x];
}

int main(){
    cin >> q;
    int last = 0;
    int ans = -2;
    for(int i = 1;i <= q;i++){
        int t;
        scanf("%d", &t);
        if(ans == -1){
            last = 1;
        }else if(ans >= 0){
            last = ans;
        }else{
            last = 0;
        }
        if(t == 1){
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l = l ^ last, r = r ^ last, x = x ^ last;
            if(l > r)
                swap(l, r);
            //cout << l << " " << r << " " << x << endl;
            int fx = Find(l - 1);
            int fy = Find(r);
            if(fx == fy){
                if((val[l - 1] ^ val[r]) != x){

                }
            }else{
                val[fy] = val[r] ^ val[l - 1] ^ x;
                fa[fy] = fx;
            }
        }else{
            int l, r;
            scanf("%d%d", &l, &r);
            l = l ^ last, r = r ^ last;
            //cout << l << " " << r << endl;
            if(l > r)
                swap(l, r);
            int fx = Find(l - 1);
            int fy = Find(r);
            if(fx == fy){
                ans = val[r] ^ val[l - 1];
                printf("%d\n", val[r] ^ val[l - 1]);
            }else{
                ans = -1;
                puts("-1");
            }
        }
    } 
    return 0;
}