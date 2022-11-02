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
#include <chrono>
using namespace std;

int n, q;
const int maxn = 2e5 + 5;

int L[maxn], R[maxn];
int zero[maxn];
char t[maxn];
int tot;
int id[maxn];

template<int P>
struct Hash {
    const int BASE;
    std::vector<int> pow, h;
    Hash(std::string s) : BASE(std::chrono::steady_clock::now().time_since_epoch().count() % 100000 + 233) {
        pow.resize(s.length() + 1);
        h.resize(s.length() + 1);
        pow[0] = 1;
        for (int i = 1; i <= int(s.length()); ++i)
            pow[i] = 1ll * pow[i - 1] * BASE % P;
        for (int i = 0; i < int(s.length()); ++i)
            h[i + 1] = (1ll * h[i] * BASE + s[i] + 99) % P;
    }
    int hash(int l, int r) {
        return (h[r] + 1ll * h[l] * (P - pow[r - l])) % P;
    }
};

void precompute(){
    zero[0] = 0;
    int pre = 0, suf = n + 1;
    for(int i = 1;i <= n;i++){
        zero[i] = zero[i - 1];
        zero[i] += (t[i] == '0');
        if(t[i] == '0')
            pre = i;
        L[i] = pre;
    }
    for(int i = n;i >= 1;i--){
        if(t[i] == '0')
            suf = i;
        R[i] = suf;
    }
}

int main(){
    cin >> n;
    scanf("%s", t + 1);
    precompute();
    tot = 0;
    int cur = 0;
    string s = "";
    for(int i = 1;i <= n;i++){
        if(t[i] == '1'){
            cur++;
        }else{
            id[i] = tot;
            s.push_back('0' + (cur & 1));
            cur = 0;
            tot++;
        }
    } 
    Hash<998244353> h1(s);
    Hash<1000000007> h2(s);
    cin >> q;
    for(int i = 1;i <= q;i++){
        int l1, l2, len;
        scanf("%d%d%d", &l1, &l2, &len);
        int r1 = l1 + len - 1;
        int r2 = l2 + len - 1;
        if(zero[r1] - zero[l1 - 1] != zero[r2] - zero[l2 - 1]){
            puts("No");
            continue;
        }
        int z0 = zero[r1] - zero[l1 - 1];
        if(z0 == 0){
            puts("Yes");
            continue;
        }
        int front1 = R[l1] - l1, rear1 = r1 - L[r1], front2 = R[l2] - l2, rear2 = r2 - L[r2];
        front1 &= 1;
        rear1 &= 1;
        front2 &= 1;
        rear2 &= 1;
        if(front1 != front2 or rear1 != rear2){
            puts("No");
            continue;
        }
        if(z0 == 1){
            puts("Yes");
            continue;
        }
        int l10 = id[R[l1]] + 1, r10 = id[L[r1]];
        int l20 = id[R[l2]] + 1, r20 = id[L[r2]];  
        if(r10 - l10 == r20 - l20 and h1.hash(l10, r10) == h1.hash(l20, r20) and h2.hash(l10, r10) == h2.hash(l20, r20)){
            puts("Yes");
            continue;
        }else{
            puts("No");
            continue;
        }

    }
    return 0;
}