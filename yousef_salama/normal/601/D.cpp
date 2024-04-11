//In the name of Allah

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

const int MAXN = 300005;

int n, c[MAXN], ai, bi;
char s[MAXN];

vector <int> g[MAXN];

int cnodes, pntr[MAXN], trie[MAXN * 2][26], trie_count[MAXN * 2];
void merge(int node_a, int node_b){
    for(int z = 0; z < 26; z++){
        if(trie[node_b][z] == -1)continue;
        
        if(trie[node_a][z] == -1){
            trie[node_a][z] = trie[node_b][z];
        }else merge(trie[node_a][z], trie[node_b][z]);
    }
    
    trie_count[node_a] = 1;
    for(int z = 0; z < 26; z++)
        if(trie[node_a][z] != -1)trie_count[node_a] += trie_count[trie[node_a][z]];
}
void print(int node_a, string cur = ""){
   cout << node_a << ',' << cur << " :" << trie_count[node_a] << endl;
   for(int z = 0; z < 26; z++){
       if(trie[node_a][z] == -1)continue;
       cur += z + 'a';
       print(trie[node_a][z], cur);
       cur.erase(cur.size() - 1);
   }
}

int mx, c_mx;
void solve(int i, int parent){
    pntr[i] = cnodes++;
    trie_count[pntr[i]] = 1;
    
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u == parent)continue;
        
        solve(u, i);
        
        //if(trie_count[pntr[u]] > trie_count[pntr[i]])
            //swap(pntr[i], pntr[u]);
        merge(pntr[i], pntr[u]);
    }
    trie[cnodes][s[i] - 'a'] = pntr[i];
    trie_count[cnodes] = trie_count[pntr[i]] + 1;
    pntr[i] = cnodes++;
    
    if(trie_count[pntr[i]] + c[i] == mx)c_mx++;
    else if(trie_count[pntr[i]] + c[i] > mx){
        mx = trie_count[pntr[i]] + c[i];
        c_mx = 1;
    }
}

int main(){
    memset(trie, -1, sizeof trie);
    /*
    trie[1][0] = 2; trie_count[1] = 3;
    trie[2][0] = 3; trie_count[2] = 2;
    trie_count[3] = 1;
    
    trie[4][1] = 5; trie_count[4] = 7;
    trie[4][0] = 7; 
    trie[7][0] = 8; trie_count[7] = 4;
    trie[8][0] = 9; trie_count[8] = 3;
    trie[9][0] = 10; trie_count[9] = 2;
    trie_count[10] = 1;
    trie[5][2] = 6; trie_count[5] = 2;
    trie_count[6] = 1;
    
    print(1);
    cout << "*****" << endl;
    print(4);
    cout << "*****" << endl;
    
    merge(1, 4);
    print(1);
    cout << "******" << endl;*/
    
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    scanf("%s", s);
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    
    solve(0, -1);
    printf("%d\n%d\n", mx - 1, c_mx);
    
    return 0;
}