#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <double> a, b;
        for(int i = 0; i < 2 * n; i++){
            int x, y;
            scanf("%d %d", &x, &y);

            if(x == 0)a.push_back(1LL * y * y);
            else b.push_back(1LL * x * x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        double res = 0.0;
        for(int i = 0; i < n; i++)
            res += sqrt(a[i] + b[i]);
        printf("%.15f\n", res);
    }
    return 0;
}