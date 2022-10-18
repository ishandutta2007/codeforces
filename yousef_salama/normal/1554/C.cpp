#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        int r = 0;
        for(int i = 30; i >= 0; i--){
            if(m & (1 << i)){
                if(n & (1 << i))continue;
                r |= (1 << i);
            }else{
                int mask = (1 << i) - 1;
                if(n & (1 << i)){
                    break;
                }else{
                    if((m & mask) == mask){
                        r |= (1 << i);
                        break;
                    }
                }
            }
        }
        printf("%d\n", r);
    }

    return 0;
}