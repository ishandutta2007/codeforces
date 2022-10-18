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

        int res = 0;
        for(int i = 0; i < n; i++)
            res += (1 + (a[i] == 0)) * (i + 1) * (n - i);

        printf("%d\n", res);
    }

    return 0;
}