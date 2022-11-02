#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

const int N = 100500;
int Trie[N][26];
char s[N];
int n,k;
int tot = 1;

void insert(char* s) {
    int pos = 0;
    while (*s) {
        see(pos);
        see(*s);
        int id = *s - 'a';
        if (Trie[pos][id] == -1) Trie[pos][id] = tot++;
        pos = Trie[pos][id];
        s++;
    }
}

void init(){
    memset(Trie , -1 , sizeof(Trie));
    scanf("%d%d",&n,&k);
    rep (i,n) {
        scanf("%s",s);
        insert(s);
    }
}

bool toWin (int pos) {
    rep (i,26) {
        if (Trie[pos][i] == -1) continue;
        if (!toWin(Trie[pos][i])) return 1;
    }
    return 0;
}

bool toLose (int pos) {
    rep (i,26) if (~Trie[pos][i]) goto nxt;
    return 1;
    nxt:;
    rep (i,26) {
        if (Trie[pos][i] == -1) continue;
        if (!toLose(Trie[pos][i])) return 1;
    }
    return 0;
}

int main(){
    init();
    bool win = toWin(0);
    bool lose = toLose(0);
    see(win);
    see(lose);
    puts( ((win && lose) || (win && (k % 2 == 1))) ? "First" : "Second");
    return 0;
}