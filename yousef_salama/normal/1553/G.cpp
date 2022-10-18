#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150005;
const int MAXM = 1000005;

bool notprime[MAXM];
vector <int> primefactors[MAXM];

int par[MAXM + MAXN];
int findr(int u){
    if(u == par[u])return u;
    else return par[u] = findr(par[u]);
}

int main(){
    for(int i = 2; i < MAXM; i++){
        if(notprime[i])continue;
        for(int j = i + i; j < MAXM; j += i){
            notprime[j] = true;
            primefactors[j].push_back(i);
        }
        primefactors[i].push_back(i);
    }

    int n, q;
    scanf("%d %d", &n, &q);

    vector <int> a(n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);

    int m = MAXM + n;
    for(int i = 0; i < m; i++)par[i] = i;

    for(int i = 0; i < n; i++){
        for(int j : primefactors[a[i]]){
            int u = findr(MAXM + i);
            int v = findr(j);

            if(u != v){
                par[u] = v;
            }
        }
    }

    set < pair <int, int> > s;

    for(int i = 0; i < n; i++){
        vector <int> w;
        for(int j : primefactors[a[i]]){
            w.push_back(findr(j));
        }
        for(int j : primefactors[a[i] + 1]){
            w.push_back(findr(j));
        }

        sort(w.begin(), w.end());
        w.resize(unique(w.begin(), w.end()) - w.begin());

        for(int a = 0; a < (int)w.size(); a++)
        for(int b = a + 1; b < (int)w.size(); b++){
            s.insert(make_pair(min(w[a], w[b]), max(w[a], w[b])));
        }
    }

    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;

        int u = findr(MAXM + a);
        int v = findr(MAXM + b);

        if(u == v)printf("0\n");
        else if(s.count(make_pair(min(u, v), max(u, v))))printf("1\n");
        else printf("2\n");
    }

    return 0;
}