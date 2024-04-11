#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;


const int maxn = 2e5 + 5;
string t;
string s[maxn];

char T[maxn], P[maxn];

int fail[maxn];

int pre[2][maxn];

void init(int len){
    fail[0] = fail[1] = 0;
    int cur = 0;
    for(int i = 2;i <= len;i++){
        while(cur > 0 and P[cur + 1] != P[i]){
            cur = fail[cur];
        }
        if(P[cur + 1] == P[i]){
            cur++;
        }
        fail[i] = cur;
    }
}

void search(int n, int m, int id){
    init(m);
    int cur = 0;
    for(int i = 1;i <= n;i++){
        while(cur > 0 and P[cur + 1] != T[i]){
            cur = fail[cur];
        }
        if(P[cur + 1] == T[i]){
            cur++;
        }
        if(cur == m){
            cur = fail[cur];
            pre[id][i - m + 1]++;
        }
    }
}

int N;

int trie[maxn][30];
int val[maxn];
int tot;

void insert(string s, int len){
    int now = 0;
    for(int i = 1;i <= len;i++){
        int id = s[i - 1] - 'a';
        if(trie[now][id] == -1){
            trie[now][id] = ++tot;
        }
        now = trie[now][id];
    }
    val[now]++;
}

int query(string s, int len){
    int now = 0;
    int ret = 0;
    for(int i = 1; i <= len;i++){
        int id = s[i - 1] - 'a';
        if(trie[now][id] == -1){
            return ret;
        }
        now = trie[now][id];
        ret += val[now];
    }
    return ret;
}

int main(){
    //clock_t start, end;
    //start = clock();
    ios::sync_with_stdio(false);
    cin >> t;
    cin >> N; 
    int sum = 0;
    for(int i = 1;i <= N;i++){
        cin >> s[i];
        sum += s[i].length();
    }
    int VAL = sqrt(sum) + 1.0;
    int mx = 0;
    //int VAL = 4;
    //cout << VAL << endl;
    int len1 = t.length();
    for(int i = 1;i <= len1;i++){
        T[i] = t[i - 1];
    }
    for(int i = 1;i <= N;i++){
        if(s[i].length() > VAL){
            int len2 = s[i].length();
            for(int j = 1;j <= len2;j++){
                P[j] = s[i][j - 1];
            } 
            search(len1, len2, 0);
        }
    }
    for(int i = 1;i <= len1;i++){
        T[i] = t[len1 - i];
    }
    for(int i = 1;i <= N;i++){
        if(s[i].length() > VAL){
            int len2 = s[i].length();
            for(int j = 1;j <= len2;j++){
                P[j] = s[i][len2 - j];
            }
            search(len1, len2, 1);
        }
    }
    tot = 0;
    memset(trie, -1, sizeof(trie));
    memset(val, 0, sizeof(val));
    for(int i = 1;i <= N;i++){
        if(s[i].length() <= VAL){
            mx = max((int)s[i].length(), mx);
            insert(s[i], s[i].length());
        }
    }
    for(int i = 0;i < len1;i++){
        string sub = "";
        for(int j = 1;j <= mx and i + j - 1 < len1;j++){
            //string sub = t.substr(i, j);
            //cout << i << endl;
            sub.push_back(t[i + j - 1]);
        }
        pre[0][i + 1] += query(sub, sub.length());
    }
    tot = 0;
    memset(trie, -1, sizeof(trie));
    memset(val, 0, sizeof(val));
    for(int i = 1;i <= N;i++){
        if(s[i].length() <= VAL){
            //cout << i << endl;
            string tmp = s[i];
            reverse(tmp.begin(), tmp.end());
            insert(tmp, tmp.length());
        }
    }
    string t1 = t;
    reverse(t1.begin(), t1.end());
    for(int i = 0;i < len1;i++){
        string sub = "";
        for(int j = 1;j <= VAL and i + j - 1 < len1;j++){
            sub.push_back(t1[i + j - 1]);
        }
        pre[1][i + 1] += query(sub, sub.length());
    }
    long long ans = 0;
    for(int i = 1;i <= len1;i++){
        //cout << pre[0][i] << " " << pre[1][len1 + 2 - i] << endl;
        ans += 1LL * pre[0][i] * pre[1][len1 + 2 - i];
    }
    cout << ans << endl;
    //end = clock();
    //cout << "Run time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}