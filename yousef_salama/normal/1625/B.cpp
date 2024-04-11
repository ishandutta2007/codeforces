#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        map <int, int> mp;

        int res = -1;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        
            if(mp.count(a[i])){
                int j = mp[a[i]];

                int cur = 1 + j + (n - i - 1);
                if(res == -1 || cur > res)res = cur;
            }
            mp[a[i]] = i;
        }

        printf("%d\n", res);
    }

    return 0;
}