#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector < vector <int> > a(n, vector <int> (n));
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        scanf("%d", &a[i][j]);

    vector <int> tree(n * n + 1);
    
    auto add = [&](int u, int val){
        while(u <= n * n){
            tree[u] += val;
            u += u & (-u);
        }
    };

    auto sum = [&](int u){
        int ret = 0;
        while(u > 0){
            ret += tree[u];
            u -= u & (-u);
        }
        return ret;
    };

    vector < vector <int> > U(n, vector <int> (n));
    vector < vector <int> > D(n, vector <int> (n));
    vector < vector <int> > L(n, vector <int> (n));
    vector < vector <int> > R(n, vector <int> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            L[i][j] = sum(a[i][j]);
            add(a[i][j], 1);
        }

        for(int j = 0; j < n; j++)
            add(a[i][j], -1);
    }

    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            R[i][j] = sum(a[i][j]);
            add(a[i][j], 1);
        }

        for(int j = 0; j < n; j++)
            add(a[i][j], -1);
    }

    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            U[i][j] = sum(a[i][j]);
            add(a[i][j], 1);
        }

        for(int i = 0; i < n; i++)
            add(a[i][j], -1);
    }

    for(int j = 0; j < n; j++){
        for(int i = n - 1; i >= 0; i--){
            D[i][j] = sum(a[i][j]);
            add(a[i][j], 1);
        }

        for(int i = 0; i < n; i++)
            add(a[i][j], -1);
    }

    long long res = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        res += L[i][j] * (i - U[i][j]);
        res += L[i][j] * (n - i - 1 - D[i][j]);
        res += R[i][j] * (i - U[i][j]);
        res += R[i][j] * (n - i - 1 - D[i][j]);
        res += (j - L[i][j]) * U[i][j];
        res += (j - L[i][j]) * D[i][j];
        res += (n - j - 1 - R[i][j]) * U[i][j];
        res += (n - j - 1 - R[i][j]) * D[i][j];
    }

    printf("%lld\n", res / 2);

    return 0;
}