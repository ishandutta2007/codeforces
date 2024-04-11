#include <cstdio>
#include <memory.h>
#include <string>
using namespace std;

char to[256][256];

bool good(string s) {
    while (s.size() > 1) {
        char c;
        if ((c = to[s[s.size() - 1]][s[s.size() - 2]]) == -1)
            return false;
        s.pop_back();
        s.back() = c;
    }
    return (s.back() == 'a');
}

int n;
int ans = 0;

string cur;
void go(int i) {
    if (i == n) {
        if (good(cur))
            ans++;
        return;
    }
    for (char c = 'a'; c <= 'f'; c++) {
        cur.push_back(c);
        go(i + 1);
        cur.pop_back();
    }
        
}

int main() {
    int q;
    scanf("%d %d", &n, &q);
    memset(to, -1, sizeof(to));
    for (int i = 0; i < q; i++) {
        char buf[50];
        scanf("%s", buf);
        char t;
        scanf(" %c ", &t);
        to[buf[0]][buf[1]] = t; 
    }
    go(0);
    printf("%d\n", ans);
}