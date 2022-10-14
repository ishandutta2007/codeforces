#include <bits/stdc++.h>

const long long MOD = 1E9 + 7;

int N, Q;
std::string str;
int ssize = 1, len[25];
std::string T;
int iter[110000];
std::string match[110000];
char buf[1100000];
unsigned long long hash[5000000], mul[5000000];
unsigned long long match_hash[1100000];
const unsigned long long MUL = 41;
long long pow2[110000];
int count[30][110000];
std::unordered_map<int, int> mp[30];

int main() {
    scanf("%d%d", &N, &Q);
    scanf(" %s", buf); str = std::string(buf);
    scanf(" %s", buf); T = std::string(buf);
    for (int i = 0; i < Q; ++i) {
        scanf("%d %s", &iter[i], buf); match[i] = std::string(buf);
    }
    len[0] = str.size();
    while (str.size() < 2000000 && ssize <= N) {
        str = str + T[ssize - 1] + str;
        len[ssize++] = str.size();
    }
    hash[0] = 0; mul[0] = 1;
    for (int i = 0; i + 1 < 5000000; ++i) mul[i + 1] = mul[i] * MUL;
    for (int i = 0; i < str.size(); ++i)
        hash[i + 1] = hash[i] * MUL + (unsigned long long) (str[i] - 'a' + 2);
    for (int i = 1; i <= T.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (T[i - 1] - 'a' == j)
                count[j][i] = (count[j][i - 1] * 2ll + 1) % MOD; 
            else
                count[j][i] = count[j][i - 1] * 2ll % MOD; 
        }
    }
    pow2[0] = 1;
    for (int i = 0; i + 1 < 110000; ++i) pow2[i + 1] = pow2[i] * 2 % MOD;
    // printf("%d %s\n", ssize, str.c_str());
    // for (int i = 0; i < ssize; ++i) printf("%d\n", len[i]);
    for (int id = 0; id < Q; ++id) {
        for (int i = 0; i < match[id].size(); ++i)
            match_hash[i + 1] = match_hash[i] * MUL + (unsigned long long) (match[id][i] - 'a' + 2);
        int ans = 0, cursize = 1;
        while (match[id].size() >= len[cursize]) ++cursize;
        for (int j = 0; j + match[id].size() <= len[std::min(iter[id], cursize)]; ++j) {
            ans += (match_hash[match[id].size()] ==
                hash[j + match[id].size()] - hash[j] * mul[match[id].size()]);
        }
        if (iter[id] > cursize) {
            ans = 1ll * ans * pow2[iter[id] - cursize] % MOD;
            for (int i = 0; i < match[id].size(); ++i) {
                int other_len = match[id].size() - i - 1;
                if (match_hash[i] == hash[str.size()] - hash[str.size() - i] * mul[i] &&
                    match_hash[match[id].size()] - match_hash[match[id].size() - other_len] * mul[other_len] ==
                    hash[other_len]) {
                    (ans += (count[match[id][i] - 'a'][iter[id]] + MOD - 1ll * pow2[iter[id] - cursize] * count[match[id][i] - 'a'][cursize] % MOD) % MOD) %= MOD; 
                }
            }
        }
        printf("%d\n", ans);
    }
}