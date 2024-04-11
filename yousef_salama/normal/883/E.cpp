#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    
    vector <bool> mark(26, false);
    for(int i = 0; i < n; i++)
        if(s[i] != '*')mark[s[i] - 'a'] = true;

    int m;
    cin >> m;

    vector <string> v(m);
    for(int i = 0; i < m; i++)cin >> v[i];

    int cnt = 0;
    for(char c = 'a'; c <= 'z'; c++)if(!mark[c - 'a']){
        bool feasible = true;
        for(int i = 0; i < m; i++){
            bool ok = true, found = false;
            for(int j = 0; j < n; j++){
                if(v[i][j] == c)found = true;

                if(s[j] == '*'){
                    if(mark[v[i][j] - 'a']){
                        ok = false;
                        break;
                    }
                }else{
                    if(s[j] != v[i][j]){
                        ok = false;
                        break;
                    }
                }
            }
            if(!ok)continue;
            if(!found){
                feasible = false;
                break;
            }
        }
        if(feasible)cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}