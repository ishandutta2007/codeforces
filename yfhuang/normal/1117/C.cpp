#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long LL;

LL x[2], y[2];
int n;
const int maxn = 1e5 + 5;
char s[maxn];

int main(){
    while(cin >> x[0] >> y[0]){
        cin >> x[1] >> y[1];
        x[1] -= x[0];
        y[1] -= y[0];
        cin >> n;
        scanf("%s", s);
        LL nx = 0, ny = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == 'U')
                ny++;
            if(s[i] == 'D')
                ny--;
            if(s[i] == 'L')
                nx--;
            if(s[i] == 'R')
                nx++;
        }
        LL tx = 0, ty = 0;
        LL ans = 1e18;
        for(int i = 0;i < n;i++){
            if(s[i] == 'U')
                ty++;
            if(s[i] == 'D')
                ty--;
            if(s[i] == 'L')
                tx--;
            if(s[i] == 'R')
                tx++;
            LL l = 0, r = 2e9;
            while(l < r){
                LL mid = (l + r) / 2;
                LL nowx = tx + nx * mid;
                LL nowy = ty + ny * mid;
                if(abs(x[1] - nowx) + abs(y[1] - nowy) <= mid * n + (i + 1)){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            if(l != 2e9)
                ans = min(ans, l * n + (i + 1));
        }
        if(ans == 1e18){
            printf("-1");
        }else{
            cout << ans << endl;
        }
    } 
    return 0;
}