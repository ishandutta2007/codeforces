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

        bool is_sorted = true;
        for(int i = 1; i < n; i++)
            if(a[i] < a[i - 1])is_sorted = false;

        if(is_sorted)printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}