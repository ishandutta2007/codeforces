#include <bits/stdc++.h>
using namespace std;

int n, k;

string num[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int a[2005];

int idx(string s){
    for(int i = 0;i < 10;i++){
        if(s == num[i])
            return i;
    }
    return -1;
}

string id2str(int id){
    string ans = "";
    for(int i = 6;i >= 0;i--){
        if(id & (1 << i))
            ans.push_back('1');
        else
            ans.push_back('0');
    }
    return ans;
}

int str2id(string s){
    int id = 0;
    for(int i = 0;i < 7;i++){
        if(s[i] == '1'){
            id = id * 2 + 1;
        }else{
            id = id * 2;
        }
    }
    return id;
}

int idx(int n){
    string s = id2str(n);
    return idx(s);
}

int trans[130][15];
bool dp[2005][2005];

void init(){
    memset(trans, -1, sizeof(trans));
    for(int i = 0;i < 128;i++){
        for(int j = 0;j < 128;j++){
            if(i & j)
                continue;
            int to = i | j;
            int id = idx(to);
            if(id == -1)
                continue;
            int add = __builtin_popcount(j);
            trans[i][add] = max(trans[i][add], id);
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    init();
    for(int i = 1;i <= n;i++){
        string s;
        cin >> s;
        a[i] = str2id(s);
    }
    memset(dp, 0, sizeof(dp));        
    dp[n + 1][0] = true;
    for(int i = n;i >= 1;i--){
        for(int j = 0;j <= k;j++){
            if(dp[i + 1][j] == false)
                continue;
            for(int digit = 0;digit <= 7;digit++){
                int to = trans[a[i]][digit]; 
                if(to == -1)
                    continue;
                dp[i][j + digit] = true;
            }
        }
    }
    if(dp[1][k]){
        string ans = "";  
        int num = k;
        for(int i = 1;i <= n;i++){
            int mx = -1;
            int mxadd = -1;
            for(int add = 0;add <= min(num, 7);add++){
                int to = trans[a[i]][add];
                if(to == -1)
                    continue;
                if(dp[i + 1][num - add]){
                    if(to > mx){
                        mx = to;
                        mxadd = add;
                    }
                }
            }
            num -= mxadd;
            ans.push_back('0' + mx);
        }
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}