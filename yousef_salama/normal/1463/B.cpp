#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        long long x = 0, y = 0;
        
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);

            if(i % 2 == 0){
                x += a[i];
            }else{
                y += a[i];
            }
        }

        for(int i = 0; i < n; i++){
            if(x <= y && i % 2 == 0)a[i] = 1;
            if(x > y && i % 2 == 1)a[i] = 1;
        }

        for(int i = 0; i < n; i++){
            if(i > 0)printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}