#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        vector <int> cnt(26, 0);
        for(char c : s)
            cnt[c - 'a']++;
        
        int distinct = 0;
        for(int x : cnt)
            distinct += (x != 0);

        vector <int> cur(26, 0);
        bool found = false;

        for(int i = 0; i < (int)s.size(); i++){
            cur[s[i] - 'a']++;

            vector <int> vis(distinct, -1);
            bool ok = true;

            for(int j = 0; j < 26; j++){
                if(cnt[j] == 0)continue;
                if(cur[j] == 0){
                    ok = false;
                    break;
                }

                if(cnt[j] % cur[j] != 0){
                    ok = false;
                    break;
                }

                int ind = cnt[j] / cur[j] - 1;
                if(ind < 0 || ind >= distinct || vis[ind] != -1){
                    ok = false;
                    break;
                }

                vis[ind] = j;
            }


            if(ok){
                string t = s.substr(0, i + 1);
                string lst = t;
                string perm = "";

                for(int j = 0; j < distinct; j++){
                    string z = "";
                    for(char c : lst)
                        if(c - 'a' != vis[j])z += c;
                    
                    t += z;
                    swap(lst, z);
                    perm += (char)(vis[j] + 'a');
                }

                if(t == s){
                    cout << s.substr(0, i + 1) << ' ' << perm << '\n';
                    found = true;
                }

                break;
            }
        }

        if(!found){
            cout << "-1\n";
        }
    }
    return 0;
}