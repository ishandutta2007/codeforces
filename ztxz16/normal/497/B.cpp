#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

const int N = 200005;

int n, s[3][N], a[N], win;
vector <pair <int, int> > ans;

int get(int ss) {
    int now = 0, s1 = 0, s2 = 0;
    while (1) {
        int x1 = lower_bound(s[1] + 1, s[1] + n + 1, s[1][now] + ss) - s[1];
        int x2 = lower_bound(s[2] + 1, s[2] + n + 1, s[2][now] + ss) - s[2];
        if (x1 < x2) {
            s1++;
            now = x1;
        } else {
            if (x2 == n + 1) {
                return 0;
            }
            
            s2++;
            now = x2;
        }
        
        if (now == n) {
            break;
        }
    }
    
    if (win == 1) {
        if (s1 > s2) {
            return s1;
        } else {
            return 0;
        }
    } else {
        if (s2 > s1) {
            return s2;
        } else {
            return 0;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[1][i] = s[1][i - 1];
        s[2][i] = s[2][i - 1];
        s[a[i]][i]++;
    }
    
    s[1][n + 1] = s[2][n + 1] = n + n + n;
    win = a[n];
    for (int ss = 1; ss <= n; ss++) {
        int now = get(ss);
        if (now) {
            ans.push_back(make_pair(now, ss));
        }
    }
    
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    
    return 0;
}