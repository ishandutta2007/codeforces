#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        vector < vector <int> > g(n);
        while(m--){
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        bool ok = true;
        for(int i = 0; i < n; i++)if(g[i].size() % 2 != 0){
            ok = false;
            break;
        }

        if(ok){
            printf("1\n");
            for(int i = 0; i < n; i++){
                if(i > 0)printf(" ");
                printf("1");
            }
            printf("\n");

            continue;
        }

        vector < bitset <2001> > v(n);
        for(int i = 0; i < n; i++){
            if(g[i].size() % 2 == 0){
                for(int j : g[i])
                    v[i].set(j);
            }else{
                for(int j : g[i])
                    v[i].set(j);
                v[i].set(i);
                v[i].set(n);
            }
        }
        
        int k = 0;
        vector <int> var(n, -1), label(n, 0);

        for(int i = 0; i < n; i++){
            bool found = false;
            for(int j = k; j < n; j++)if(v[j].test(i)){
                swap(v[k], v[j]);
                found = true;
                break;
            }

            if(!found)continue;

            for(int j = k + 1; j < n; j++)if(v[j].test(i)){
                v[j] ^= v[k];
            }
            var[k] = i;
            k++;
        }

        /*for(int i = 0; i < k; i++){
            for(int j = 0; j <= n; j++){
                if(v[i].test(j))cout << 1 << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }*/
        
        int l = n - 1;
        for(int i = k - 1; i >= 0; i--){
            while(l > var[i]){
                label[l] = 0;
                l--;
            }
            label[l] = v[i].test(n);
            for(int j = i - 1; j >= 0; j--)if(v[j].test(l))
                v[j] ^= v[i];
            l--;
        }

        printf("2\n");
        for(int i = 0; i < n; i++){
            if(i > 0)printf(" ");
            printf("%d", label[i] + 1);
        }
        printf("\n");
    }

    return 0;
}