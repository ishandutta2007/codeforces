#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
const int N = 3e5 + 7, mod = 1e9 + 7;
typedef long long ll;
unordered_map<int, int> Hash;
void get_factor(int x)
{
    for(int i = 2; ; ++ i) {
        int even = i * i;
        while(x % even == 0 && x >= even) x /= even;
        if(x < even) break;
    }
    Hash[x] ++ ;////
    //x010x=1()1x=

    //
}
int n, m, t, q;
int main()
{
    scanf("%d", &t);
    while(t -- ) {
        Hash.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i) {
            int a;
            scanf("%d", &a);
            get_factor(a);
        }
        int ans1 = 0, ans2 = 0;
        for(auto it = Hash.begin(); it != Hash.end(); ++ it) {
            //0
            ans1 = max(ans1, it -> second);//second0
            //1
            if(it -> second % 2 == 0 || it -> first == 1)//( || )
                ans2 += it->second;//1
        }
        ans2 = max(ans2, ans1);//
        scanf("%d", &q);
        for(int i = 1; i <= q; ++ i) {
            ll w;
            scanf("%lld", &w);
            if(w == 0)
                printf("%d\n", ans1);
            else printf("%d\n", ans2);
        }
    }
    return 0;
}