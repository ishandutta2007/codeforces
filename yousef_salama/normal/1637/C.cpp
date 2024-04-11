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

        if(n == 3){
            if(a[1] % 2 == 0)printf("%d\n", a[1] / 2);
            else printf("-1\n");
        }else{
            bool all_one = true;
            for(int i = 1; i < n - 1; i++)
                if(a[i] != 1)all_one = false;

            if(all_one)printf("-1\n");
            else{
                long long res = 0;
                for(int i = 1; i < n - 1; i++)
                    res += (a[i] + 1) / 2;
                printf("%lld\n", res);
            }
        }
    }

    return 0;
}