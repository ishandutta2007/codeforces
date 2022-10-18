#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int h = 1;
        for(int i = 0; i < n; i++){
            if(i > 0 && a[i] == 0 && a[i - 1] == 0){
                h = -1;
                break;
            }

            if(i > 0 && a[i] == 1 && a[i - 1] == 1){
                h += 5;
                continue;
            }

            if(a[i] == 1){
                h++;
            }
        }

        printf("%d\n", h);
    }

    return 0;
}