#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> mx(10, -1);
        while(n--){
            int b, d;
            scanf("%d %d", &b, &d);
            d--;
            
            mx[d] = max(mx[d], b);
        }

        bool ok = true;
        int sum = 0;
        for(int i = 0; i < 10; i++){
            if(mx[i] == -1){
                ok = false;
                break;
            }
            sum += mx[i];
        }

        if(ok)printf("%d\n", sum);
        else printf("MOREPROBLEMS\n");
    }

    return 0;
}