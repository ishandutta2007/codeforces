#include <bits/stdc++.h>
using namespace std;

struct node{
    int type, cnt_white, cnt_black, go[2];
    node(){
        type = 0;
        cnt_white = 0;
        cnt_black = 0;
        go[0] = -1;
        go[1] = -1;
    }
};
vector <node> trie;
vector < pair <long long, int> > res;

void solve(long long mask, int depth, int u){
    if(u == -1)return;
    if(trie[u].cnt_black == 0)return;

    if(trie[u].cnt_white == 0){
        res.push_back(make_pair(mask, depth));
        return;
    }

    solve((mask << 1), depth + 1, trie[u].go[0]);
    solve((mask << 1) | 1, depth + 1, trie[u].go[1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    trie.push_back(node());
    bool ok = true;

    for(int num = 0; num < n; num++){
        string s;
        cin >> s;

        char sign = s[0];
        int i = 0;
        long long mask = 0;
        for(int j = 0; j < 4; j++){
            i++;

            int cur = 0;
            while(i < (int)s.size() && s[i] != '.' && s[i] != '/'){
                cur = cur * 10 + s[i] - '0';
                i++;
            }
            mask = (mask << 8) + cur;
        }
        int x = 32;
        if(i != (int)s.size()){
            i++;
            x = 0;
            while(i < (int)s.size()){
                x = x * 10 + s[i] - '0';
                i++;
            }
        }
        /*
        for(int j = 31; j > 31 - x; j--){
            if(mask & (1LL << j))cout << '1';
            else cout << '0';
        }
        cout << endl;
        */
        if(!ok)continue;
        
        int cur = 0;
        for(int i = 31; i > 31 - x; i--){
            if(sign == '+'){
                if(trie[cur].type == -1){
                    ok = false;
                    break;
                }
                trie[cur].cnt_white++;
            }else{
                if(trie[cur].type == 1){
                    ok = false;
                    break;
                }
                trie[cur].cnt_black++;
            }
            
            int bit = (mask & (1LL << i)) != 0;
            if(trie[cur].go[bit] == -1){
                trie.push_back(node());
                trie[cur].go[bit] = (int)trie.size() - 1;
            }
            cur = trie[cur].go[bit];
        }
        if(ok){
            if(sign == '+'){
                if(trie[cur].cnt_black > 0){
                    ok = false;
                    continue;
                }
                trie[cur].type = 1;
                trie[cur].cnt_white++;
            }else{
                if(trie[cur].cnt_white > 0){
                    ok = false;
                    continue;
                }
                trie[cur].type = -1;
                trie[cur].cnt_black++;
            }
        }
    }

    if(!ok){
        cout << "-1\n";
        return 0;
    }

    solve(0, 0, 0);

    cout << res.size() << '\n';
    for(int i = 0; i < (int)res.size(); i++){
        long long mask = res[i].first, depth = res[i].second;
        mask = mask << (32 - depth);
        cout << (mask >> 24) << '.' << ((mask >> 16) & 255) << '.' << ((mask >> 8) & 255) << '.' << (mask & 255) << "/" << depth << '\n';
    }

    return 0;
}