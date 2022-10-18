#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector <int> s(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);

    for(int m = 19; m >= 0; m--){
        vector <int> a, b;
        int k = 0;

        for(int x : s)if(x < (1 << m)){
            a.push_back(x);
            b.push_back(x);
        }

        for(int i = 0; i < m; i++){
            bool found = false;
            for(int j = k; j < (int)a.size(); j++)if(a[j] & (1 << i)){
                swap(a[j], a[k]);
                swap(b[j], b[k]);
                found = true;

                break;
            }

            if(found){
                for(int j = k + 1; j < (int)a.size(); j++)if(a[j] & (1 << i))
                    a[j] ^= a[k];
                k++;
            }
        }

        if(k == m){
            vector <int> v(1, 0);
            for(int i = 0; i < m; i++)
            for(int j = (int)v.size() - 1; j >= 0; j--)
                v.push_back(v[j] ^ b[i]);
            
            printf("%d\n", m);
            for(int i = 0; i < (int)v.size(); i++){
                if(i > 0)printf(" ");
                printf("%d", v[i]);
            }
            printf("\n");

            return 0;
        }
    }
    return 0;
}