//
//  main.cpp
//  E
//
//  Created by  on 16/1/1.
//  Copyright  2016 . All rights reserved.
//

// Musketeers
// AC, O(n log(n))
// by Errichto
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

const int nax = 1e6 + 5;
const int inf = 1e9 + 5;
int m[3];
multiset<int> enemies;

void greedy(int atLeast, int extra, int & ans) {
    while(!enemies.empty()) {
        auto it = enemies.end();
        --it;
        if(*it < atLeast) break;
        enemies.erase(it);
        ++ans;
        it = enemies.lower_bound(extra);
        if(it != enemies.begin()) {
            --it;
            enemies.erase(it);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 3; ++i) scanf("%d", &m[i]);
    sort(m, m + 3);
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        enemies.insert(x);
    }
    int all = m[0] + min(inf, m[1] + m[2]);
    auto it = enemies.end();
    --it;
    if(*it >= all) {
        puts("-1");
        return 0;
    }
    int ans = 0;
    greedy(m[1] + m[2], 0, ans);
    greedy(m[0] + m[2], m[0], ans);
    greedy(max(m[0]+m[1], m[2]), m[1], ans);
    int one = 0, two = 0;
    for(int x : enemies) {
        if(x < m[0] + m[1]) ++one;
        if(x < m[2]) ++two;
    }
    int best = inf;
    for(int rep = 0; rep < n + 5; ++rep) {
        if(max(one, two) == (int) enemies.size()) {
            if(2 * min(one, two) >= (int) enemies.size()) best = min(best, rep + ((int) enemies.size() + 1) / 2);
            else best = min(best, rep + (int) enemies.size() - min(one, two));
        }
        for(int i = 0; i < 3; ++i) {
            auto it = enemies.lower_bound(m[i]);
            if(it != enemies.begin()) {
                --it;
                if(*it < m[0] + m[1]) --one;
                if(*it < m[2]) --two;
                enemies.erase(it);
            }
        }
    }
    printf("%d\n", ans + best);
    return 0;
}