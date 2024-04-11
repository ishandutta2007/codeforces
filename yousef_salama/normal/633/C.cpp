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
#include <complex>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

int cn, trie[1000005][26], ind[1000005];

int n, m;
string s, w[100005], w_[100005];


void add(int i){
    int j = 0;
    for(int k = 0; k < w[i].size(); k++){
        if(trie[j][w_[i][k] - 'a'] == -1)trie[j][w_[i][k] - 'a'] = cn++;
        j = trie[j][w_[i][k] - 'a'];
    }
    ind[j] = i;
}

int dp[10005];
int main(){
    ios_base::sync_with_stdio(false);
    
    memset(trie, -1, sizeof trie);
    memset(ind, -1, sizeof ind);
    cn = 1;
    
    cin >> n >> s >> m;
    for(int i = 0; i < m; i++){
        cin >> w[i];
        
        w_[i] = w[i];
        reverse(w_[i].begin(), w_[i].end());
        for(int j = 0; j < w_[i].size(); j++)
            if(('A' <= w_[i][j]) && (w_[i][j] <= 'Z'))w_[i][j] = w_[i][j] - 'A' + 'a';
        
        add(i);
    }
    
    for(int i = n; i >= 0; i--){
        if(i == n){
            dp[i] = 0;
        }else{
            dp[i] = -1;
            
            int j = 0;
            for(int k = i; k < n; k++){
                if(trie[j][s[k] - 'a'] == -1)break;
                j = trie[j][s[k] - 'a'];
                
                if((ind[j] != -1) && (dp[k + 1] != -1)){
                    dp[i] = ind[j];
                    break;
                }
            }
        }
    }
    
    int i = 0;
    bool f = true;
    while(i < n){
        if(f)f = false;
        else cout << " ";
        
        int j = dp[i];
        cout << w[j];
        i += w[j].size();
    }
    cout << endl;
    
    return 0;
}