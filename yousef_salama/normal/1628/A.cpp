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

        vector < vector <int> > v(n + 1);
        for(int i = n - 1; i >= 0; i--)
            v[a[i]].push_back(i);

        vector <int> b;
        for(int i = 0; i < n; ){
            int j = i, mex = 0;
            set <int> s;

            while(!v[mex].empty()){
                int k = v[mex].back();
                while(j <= k){
                    s.insert(a[j]);
                    v[a[j]].pop_back();
                    j++;
                }

                while(s.count(mex))mex++;
            }

            b.push_back(mex);
            i = max(i + 1, j);
        }

        printf("%d\n", (int)b.size());
        for(int i = 0; i < (int)b.size(); i++){
            if(i > 0)printf(" ");
            printf("%d", b[i]);
        }
        printf("\n");
    }
    return 0;
}