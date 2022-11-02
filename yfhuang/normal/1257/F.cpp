#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int n;
const int maxn = 105;

int a[maxn];
const int maxm = (1 << 15) * maxn;
map<int, int> trie[maxm];
int v[maxm];
int tot;

void insert(int x){
    int root = 0;
    for(int i = 1;i <= n;i++){
        int mask = (1 << 15) - 1;
        int val = a[i] & mask;
        int val1 = val ^ x;
        int cnt = __builtin_popcount(val1);
        if(trie[root].find(cnt) == trie[root].end()){
            trie[root][cnt] = ++tot;
            trie[tot].clear();
        }
        root = trie[root][cnt];
    }
    v[root] = x;
}

int search(int x, int sum){
    int root = 0;
    for(int i = 1;i <= n;i++){
        int mask = (1 << 15) - 1;
        mask <<= 15;
        int val = a[i] & mask;
        val >>= 15;
        int val1 = val ^ x;
        int cnt = __builtin_popcount(val1);
        int cnt1 = sum - cnt;
        if(trie[root].find(cnt1) == trie[root].end())
            return -1;
        root = trie[root][cnt1];
    }
    return v[root];
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", a + i);
    }
    tot = 0;
    for(int i = 0;i < (1 << 15);i++){
        insert(i); 
    }
    int ans = -1;
    for(int sum = 0;sum <= 30;sum++){
        for(int i = 0;i < (1 << 15);i++){
            int ret = search(i, sum);
            if(ret >= 0){
//                cout << i << " " << sum << endl;
//                cout << i << " " << ret << endl;
                ans = (i << 15) | ret;
            }
        }
    }
    cout << ans << endl;
    return 0;
}