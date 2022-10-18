#include <bits/stdc++.h>
using namespace std;

int main(){
    const int MOD = 998244353;
    const int MAX = 50;

    auto nxt = [&](int x){
        if(x == 1)return 2;
        else return 2 * x - 1;
    };

    int k, A, h;
    scanf("%d %d %d", &k, &A, &h);

    vector <long long> pw(MAX);
    pw[0] = 1LL;
    for(int i = 1; i < MAX; i++)
        pw[i] = A * pw[i - 1] % MOD;

    vector < vector <int> > v;
    v.push_back({1});

    for(int i = 0; i < k - 1; i++){
        vector < vector <int> > w;
        for(int a = 0; a < (int)v.size(); a++)
        for(int b = 0; b < (int)v.size(); b++)
        for(int win = 0; win <= 1; win++){
            vector <int> c(v[a].size() + v[b].size());
            
            for(int i = 0; i < (int)v[a].size(); i++){
                if(v[a][i] == 1 && win == 0)c[i] = 1;
                else c[i] = nxt(v[a][i]);
            }
            for(int i = 0; i < (int)v[b].size(); i++){
                if(v[b][i] == 1 && win == 1)c[(int)v[a].size() + i] = 1;
                else c[(int)v[a].size() + i] = nxt(v[b][i]);
            }

            w.push_back(c);
        }
        swap(v, w);
    }

    set <int> hash_won, hash_lost;
    vector <int> v_won, v_lost;

    for(int i = 0; i < (int)v.size(); i++){
        long long cur_won = 0, cur_lost = 0;
        for(int j = 0; j < (int)v[i].size(); j++){
            if(v[i][j] == 1){
                cur_won = (cur_won + 1LL * (j + 1) * pw[1]) % MOD;
                cur_lost = (cur_lost + 1LL * (j + 1) * pw[2]) % MOD;
            }else{
                cur_won = (cur_won + 1LL * (j + 1) * pw[nxt(v[i][j])]) % MOD;
                cur_lost = (cur_lost + 1LL * (j + 1) * pw[nxt(v[i][j])]) % MOD;
            }
        }

        hash_won.insert(cur_won);
        hash_lost.insert(cur_lost);

        v_won.push_back(cur_won);
        v_lost.push_back(cur_lost);
    }

    for(int i = 0; i < (int)v.size(); i++){
        long long cur_won = 0, cur_lost = 0;
        for(int j = 0; j < (int)v[i].size(); j++){
            if(v[i][j] == 1){
                cur_won = (cur_won + 1LL * ((int)v[i].size() + j + 1) * pw[1]) % MOD;
                cur_lost = (cur_lost + 1LL * ((int)v[i].size() + j + 1) * pw[2]) % MOD;
            }else{
                cur_won = (cur_won + 1LL * ((int)v[i].size() + j + 1) * pw[nxt(v[i][j])]) % MOD;
                cur_lost = (cur_lost + 1LL * ((int)v[i].size() + j + 1) * pw[nxt(v[i][j])]) % MOD;
            }
        }

        int target_won = (h - cur_lost + MOD) % MOD;
        int target_lost = (h - cur_won + MOD) % MOD;

        if(hash_won.count(target_won)){
            for(int j = 0; j < (int)v.size(); j++)if(v_won[j] == target_won){ 
                for(int k = 0; k < (int)v[j].size(); k++){
                    if(k > 0)printf(" ");
                    
                    if(v[j][k] == 1)printf("1");
                    else printf("%d", nxt(v[j][k]));
                }
                for(int k = 0; k < (int)v[i].size(); k++){
                    printf(" ");

                    printf("%d", nxt(v[i][k]));
                }
                printf("\n");
                
                return 0;
            }
        }
        if(hash_lost.count(target_lost)){
            for(int j = 0; j < (int)v.size(); j++)if(v_lost[j] == target_lost){
                for(int k = 0; k < (int)v[j].size(); k++){
                    if(k > 0)printf(" ");
                    
                    printf("%d", nxt(v[j][k]));
                }
                for(int k = 0; k < (int)v[i].size(); k++){
                    printf(" ");
                    
                    if(v[i][k] == 1)printf("1");
                    else printf("%d", nxt(v[i][k]));
                }
                printf("\n");
                
                return 0;
            }
        }
    }

    printf("-1\n");

    return 0;
}