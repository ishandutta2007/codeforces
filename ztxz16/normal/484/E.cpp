#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

struct Node;

Node *null;
 
const int N = 250005;
 
int a[N], b[N], c[N], tot;
int ansNow, now;

struct Node {
    int left, right;
    int lans, rans, ans;
    Node *lc, *rc;
 
    Node (int left, int right, int ans = 0, int lans = 0, int rans = 0, Node *lc = null, Node *rc = null) :
        left(left), right(right), ans(ans), lans(lans), rans(rans), lc(lc), rc(rc) {}
 
    void build() {
        if (left == right) {
            return;
        }
 
        int mid = (left + right) >> 1;
        lc = new Node(left, mid);
        rc = new Node(mid + 1, right);
        lc->build();
        rc->build();
    }
 
    Node *insert(int v) {
        if (v < left || v > right) {
            return this;
        }
 
        Node *temp = new Node(left, right, ans, lans, rans, lc, rc);
        if (left == right) {
            temp->ans = temp->lans = temp->rans = 1;
            return temp;
        }
        
        temp->lc = lc->insert(v);
        temp->rc = rc->insert(v);
        temp->ans = max(max(temp->lc->ans, temp->rc->ans), temp->lc->rans + temp->rc->lans);
        if (temp->lc->lans == temp->lc->right - temp->lc->left + 1) {
            temp->lans = temp->lc->lans + temp->rc->lans;
        } else {
            temp->lans = temp->lc->lans;
        }
        
        if (temp->rc->rans == temp->rc->right - temp->rc->left + 1) {
            temp->rans = temp->rc->rans + temp->lc->rans;
        } else {
            temp->rans = temp->rc->rans;
        }
        
        return temp;
    }
 
    void ask(int l, int r) {
        if (l > right || r < left) {
            return;
        }
 
        if (l <= left && r >= right) {
            ansNow = max(ansNow, now + lans);
            ansNow = max(ansNow, ans);
            if (lans == right - left + 1) {
                now += lans;
            } else {
                now = rans;
                ansNow = max(ansNow, now);
            }
            
            return;
        }
 
        lc->ask(l, r);
        rc->ask(l, r);
    }
} *root[N];

int get(int x) {
    return lower_bound(c + 1, c + tot + 1, x) - c;
}

int n, m;
vector <int> v[N];

int main() {
    null = new Node(0, 0);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    
    sort(c + 1, c + n + 1);
    tot = unique(c + 1, c + n + 1) - c - 1;
    root[tot + 1] = new Node(1, n);
    root[tot + 1]->build();
    for (int i = 1; i <= n; i++) {
        v[get(a[i])].push_back(i);
    }
    
    for (int i = tot; i >= 1; i--) {
        root[i] = root[i + 1];
        for (int j = 0; j < (int)v[i].size(); j++) {
            root[i] = root[i]->insert(v[i][j]);
        }
    }
    
    scanf("%d", &m);
    while (m--) {
        int l, r, w;
        scanf("%d %d %d", &l, &r, &w);
        int ll = 1, rr = tot;
        while (ll < rr) {
            int mid = (ll + rr + 1) >> 1;
            ansNow = 0, now = 0;
            root[mid]->ask(l, r);
            if (ansNow >= w) {
                ll = mid;
            } else {
                rr = mid - 1;
            }
        }
        
        printf("%d\n", c[ll]);
    }
    
    return 0;
}