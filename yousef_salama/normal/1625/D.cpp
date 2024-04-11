#include <bits/stdc++.h>
using namespace std;

int k;
vector <int> indices;

void solve(const vector < pair <int, int> >& a, int j){
    if(a.empty())return;

    if(j == -1){
        for(pair <int, int> u : a)
            indices.push_back(u.second);

        return;
    }

    vector < pair <int, int> > a0, a1;

    for(pair <int, int> u : a){
        if(u.first & (1 << j))a1.push_back(u);
        else a0.push_back(u);
    }

    if((1 << j) - 1 < k){
        if(a0.empty() || a1.empty()){
            indices.push_back(a[0].second);

            return;
        }

        vector < vector <int> > trie(1, vector <int> (2, -1));
        vector <int> index(1, -1);
        
        for(pair <int, int> u : a0){
            int cur = 0;
            for(int i = j; i >= 0; i--){
                int b;
                if(u.first & (1 << i))b = 1;
                else b = 0;

                if(trie[cur][b] == -1){
                    trie.push_back(vector <int> (2, -1));
                    index.push_back(-1);
                    
                    trie[cur][b] = (int)trie.size() - 1;
                }
                cur = trie[cur][b];
            }

            index[cur] = u.second;
        }

        for(pair <int, int> u : a1){
            int cur = 0, y = 0;
            for(int i = j; i >= 0; i--){
                int b;
                if(u.first & (1 << i))b = 1;
                else b = 0;

                if(trie[cur][b ^ 1] != -1){
                    cur = trie[cur][b ^ 1];
                    y |= 1 << i;
                }else{
                    cur = trie[cur][b];
                }
            }

            if(y >= k){
                indices.push_back(index[cur]);
                indices.push_back(u.second);

                return;
            }
        }

        indices.push_back(a[0].second);
    }else{
        solve(a0, j - 1);
        solve(a1, j - 1);
    }
}

int main(){
    int n;
    scanf("%d %d", &n, &k);

    vector < pair <int, int> > a(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }

    solve(a, 29);

    if((int)indices.size() < 2){
        printf("-1\n");
        return 0;
    }

    printf("%d\n", (int)indices.size());

    for(int i = 0; i < (int)indices.size(); i++){
        if(i > 0)printf(" ");
        printf("%d", indices[i]);
    }
    printf("\n");

    return 0;
}