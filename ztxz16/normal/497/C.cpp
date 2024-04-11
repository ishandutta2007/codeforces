#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define PQ priority_queue

using namespace std;

int FASTBUFFER;

const int N = 1000005;

int n, m, tot, ans[N];

struct Node {
    int pos, type, p2, val, tag;
    
    Node () {}
    
    Node (int pos, int type, int p2, int val, int tag) :
        pos(pos), type(type), p2(p2), val(val), tag(tag) {}
        
    friend bool operator < (const Node &a, const Node &b) {
        return a.pos > b.pos || (a.pos == b.pos && a.type < b.type);
    }
} a[N];

set <pair <int, int> > s;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        a[++tot] = Node(l, 1, r, 0, i);
    }
    
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        a[++tot] = Node(l, 2, r, k, i);
    }
    
    sort(a + 1, a + tot + 1);
    for (int i = 1; i <= tot; i++) {
        if (a[i].pos == 2) {
            a[i].pos = 2;
        }
        
        if (a[i].type == 1) {
            s.insert(make_pair(a[i].p2, a[i].tag));
        } else {
            int k = a[i].val, v = a[i].p2;
            while (k && s.size()) {
                set <pair <int, int> > :: iterator it = s.upper_bound(make_pair(v + 1, -1));
                if (it == s.begin()) {
                    break;
                }
                
                --it;
                ans[it->second] = a[i].tag;
                s.erase(it);
                k--;
            }
        }
    }
    
    if (s.size()) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans[i]);
        }
        
        printf("\n");
    }
    
    return 0;
}