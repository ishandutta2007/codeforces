#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        vector <int> v(4);
        scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);

        vector <int> p(4);
        iota(p.begin(), p.end(), 0);

        int res = 0;
        do{
            res = max(res, min(v[p[0]], v[p[1]]) * min(v[p[2]], v[p[3]]));
        }while(next_permutation(p.begin(), p.end()));

        printf("%d\n", res);
    }
    return 0;
}