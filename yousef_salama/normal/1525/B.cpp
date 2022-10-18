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

        bool sorted = true;
        for(int i = 0; i + 1 < n; i++)
            sorted &= a[i] < a[i + 1];

        if(sorted){
            printf("0\n");
            continue;
        }

        if(a[0] == 1 || a[n - 1] == n){
            printf("1\n");
            continue;
        }

        if(a[0] == n && a[n - 1] == 1){
            printf("3\n");
            continue;
        }

        printf("2\n");
    }
    return 0;
}