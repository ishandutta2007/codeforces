#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, l;
        scanf("%d %d", &n, &l);

        vector <int> x(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &x[i]);

        int y = 0;
        for(int i = 0; i < l; i++){
            int c0 = 0, c1 = 0;
            for(int j = 0; j < n; j++){
                if(x[j] & (1 << i))c1++;
                else c0++;
            }

            if(c1 > c0)y |= 1 << i;
        }
        
        printf("%d\n", y);
    }

    return 0;
}