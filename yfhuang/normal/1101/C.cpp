#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 2e5 + 5;

struct seg{
    int l, r;
    int id;
    seg(int _l=0, int _r=0):l(_l), r(_r){}
    bool operator < (const seg &rhs) const{
        if(l != rhs.l){
            return l < rhs.l;
        }else{
            return r < rhs.r;
        }
    }
}p[maxn];

int t[maxn];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++){
            scanf("%d%d", &p[i].l, &p[i].r);
            p[i].id = i;
        }
        sort(p + 1, p + 1 + n);
        int pre = -1;
        int it = 0;
        for(int i = 1;i <= n;i++){
            if(pre == -1){
                t[p[i].id] = it + 1;
                it ^= 1;
                pre = i;
            }else{
                if(p[i].l <= p[pre].r){
                    t[p[i].id] = t[p[pre].id];
                }else{
                    t[p[i].id] = it + 1;
                    it ^= 1;
                    pre = i;
                }
                if(p[i].r>= p[pre].r){
                    pre = i;
                }
            }
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(t[i] == 1){
                cnt |= 1;
            }else{
                cnt |= 2;
            }
        }
        if(cnt == 3){
            for(int i = 1;i <= n;i++){
                printf("%d%c", t[i], i == n ? '\n' : ' ');
            }
        }else{
            puts("-1");
        }
    } 
    return 0;
}