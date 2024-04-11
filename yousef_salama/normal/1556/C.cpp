#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector <int> c(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    long long res = 0;
    for(int i = 0; i < n; i += 2){
        long long sum = 0, req = 0;
        for(int j = i + 1; j < n; j++){
            if(j % 2 != 0){
                if(c[i] >= req && c[j] >= sum + req){
                    res += min(c[i] - max(req, 1LL) + 1, c[j] - max(sum + req, 1LL) + 1);
                    //cout << i << ',' << j << ' ' << sum << ',' << req << ' ' << min(c[i] - max(req, 1LL) + 1, c[j] - max(sum + req, 1LL) + 1) << endl;
                }
            }

            if(j % 2 == 0){
                sum += c[j];
            }else{
                sum -= c[j];
                req = max(req, -sum);
            }
        }
    }
    printf("%lld\n", res);

    return 0;
}