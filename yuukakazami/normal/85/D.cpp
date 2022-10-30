/*
 * D. Sum of Medians.cpp
 *
 *  Created on: 2011-5-21
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

typedef long long int64;

struct Tree {
    int l, r;
    int cnt;
    int64 sum[5];
    Tree*L, *R;
    Tree() {
        memset(sum, 0, sizeof sum);
        cnt = 0;
    }
    void update() {
        int shift = L->cnt % 5;
        for (int rem = 0; rem < 5; ++rem) {
            sum[rem] = L->sum[rem] + R->sum[(rem + 5 - shift) % 5];
        }
        cnt = L->cnt + R->cnt;
    }
    void change(int at, int d);
    Tree(int _l, int _r);
}*null = new Tree;

Tree::Tree(int _l, int _r) :
    l(_l), r(_r) {
    memset(sum, 0, sizeof sum);
    cnt = 0;
    L = R = null;
}

void Tree::change(int at, int d) {
    if (l + 1 == r) {
        memset(sum, 0, sizeof sum);
        sum[0] = at * d;
        cnt = d;
        return;
    }
    int m = l + r >> 1;
    if (at < m) {
        if (L == null) {
            L = new Tree(l, m);
        }
        L->change(at, d);
    } else {
        if (R == null)
            R = new Tree(m, r);
        R->change(at, d);
    }
    update();
}

Tree*root = new Tree(0, int(1e9) + 1);

int main() {
    int nQ;
    scanf("%d", &nQ);
    for (int i = 0; i < nQ; ++i) {
        char buf[100];
        int x;
        scanf(" ");
        scanf("%s", buf);
        if (buf[0] == 'a') {
            scanf("%d", &x);
            root->change(x, 1);
        } else if (buf[0] == 'd') {
            scanf("%d", &x);
            root->change(x, 0);
        } else {
            int64 ret = root->sum[2];
            printf("%I64d\n", ret);
        }
    }
}