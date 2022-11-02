#include <bits/stdc++.h>
using namespace std;
int n;
typedef unsigned int uint;

void printIp(uint ip) {
   vector<int> vec;
   for (int i = 0; i < 4; i++) {
        vec.push_back((int)(ip & 255));
        ip >>= 8;
   }
   printf("%d", vec[3]);
   for (int i = 2; i >= 0; i--) printf(".%d",vec[i]);
}


vector<int> get(string s) {
    vector<int> res;
    int x = 0;
    s += ".";
    //cout << s << endl;
    for (auto ch: s) {
        if (isdigit(ch)) {
            x = x * 10 + ch - '0';
        }
        else {
            res.push_back(x);
            x = 0;
        }
    }
    return res;
}
char s[50];
void read(uint &ip, int &d, bool &f) {
    
    scanf("%s", s);
    if (s[0] == '-') f = false;
    else f = true;
    //printf("s:%s\n", s+1);
    vector<int> vec = get(string(s + 1));
    if (vec.size() == 4) vec.push_back(32);
    ip = 0;
    d = vec[4];
    //printf("d=%d\n", d);
    for (int i = 0; i < 4; i++) {
        ip <<= 8;
        ip += (uint) vec[i];
    }
}
const int N = 8e6+10;
struct node{
    int ch[2];
    bool flag[2], all[2];
}trie[N];
int tot, root;
void ins(uint ip, int len, bool f, int &v, int depth = 0) {
    if (v == 0) v = ++tot; 
 /*   puts("ins:");
    printIp(ip);
    printf("len=%d, f = %d, v = %d, depth=%d\n", len, f, v, depth);
    puts("ins end;");
    puts("");*/
    if (trie[v].all[f^1]) {
        puts("-1");
        exit(0);
    }
    
    
    if (trie[v].all[f]) return;
    trie[v].flag[f] = 1;
    if (len == depth) {
        if (trie[v].flag[f^1]) {
            puts("-1");
            exit(0);
        }
        trie[v].all[f] = 1;
        return;
    }
    int bit = (ip >> (31 - depth) & 1);
    ins(ip, len, f, trie[v].ch[bit], depth+1);
}

vector<pair<uint, int> > ansVec;
uint mask[33];


void print() {
    printf("%d\n", (int)ansVec.size());
    for (auto p: ansVec) {
       uint ip = p.first;
       
       int len = p.second;
       ip &= mask[len];
       printIp(ip);
       printf("/%d\n", len);
    }
}

void solve(uint ip = 0, int v = root, int depth = 0) {
 /*   puts("solve:");
    printIp(ip);
    printf("v = %d, depth=%d\n", v, depth);
    puts("solve end;");
    puts("");*/



    if (v == 0 || trie[v].all[1]) return;
    if (!trie[v].flag[1]) {
        ansVec.push_back(make_pair(ip, depth));
    }
    else {
        for (int i = 0; i < 2; i++)
            solve(ip ^ ((uint)i << (31 - depth)), trie[v].ch[i], depth+1);
    }
}

int main() {
    for (int i = 1; i <= 32; i++) {
        mask[i] = mask[i - 1] + ((uint)1 << (32 - i));
    }

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        uint ip;
        int d;
        bool f;
        read(ip, d, f);
        ins(ip, d, f, root);
    } 
    solve();
    print();
}