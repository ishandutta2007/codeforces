#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
const int maxn = 1e5 + 5;
int t[maxn], d[maxn];
int rid[maxn];
struct dish{
    int num, id, cost;
    bool operator < (const dish & rhs) const{
        if(cost != rhs.cost){
            return cost < rhs.cost;
        }else{
            return id < rhs.id;
        }
    }
}a[maxn];

int main(){
    while(cin >> n >> m){
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i].num);
        }
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i].cost);
            a[i].id = i;
        }
        sort(a + 1,a + 1 + n);
        for(int i = 1;i <= n;i++){
            rid[a[i].id] = i;
        }
        int cheap = 1;
        for(int i = 1;i <= m;i++){
            scanf("%d%d", &t[i], &d[i]);
            long long ans = 0;
            int j = rid[t[i]];
            int eat = min(a[j].num, d[i]);
            ans += 1LL * a[j].cost * eat;
            a[j].num -= eat;
            d[i] -= eat;
            while(d[i] > 0){
                if(cheap == n + 1)
                    break;
                if(a[cheap].num == 0){
                    cheap++;
                    continue;
                }
                int eat1 = min(a[cheap].num, d[i]);
                ans += 1LL * a[cheap].cost * eat1;
                a[cheap].num -= eat1;
                d[i] -= eat1;
            }
            if(d[i] == 0){
                printf("%lld\n", ans);
            }else{
                printf("0\n");
            }
        } 
    } 
    return 0;
}