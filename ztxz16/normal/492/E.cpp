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

const int N = 2000005;

int n, m, dx, dy, pos[N];
map <int, int> s;

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d %d %d", &n, &m, &dx, &dy);
    pos[0] = 0;
    int x = 0, y = 0;
    while (1) {
        (x += dx) %= n;
        (y += dy) %= n;
        pos[x] = y;
        if (!x && !y) {
            break;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (y >= pos[x]) {
            s[y - pos[x]]++;
        } else {
            s[n - (pos[x] - y)]++;
        }
    }
    
    int ans = 0, ans2 = 0;
    for (map <int, int> :: iterator it = s.begin(); it != s.end(); ++it) {
        if (it->second > ans) {
            ans = it->second;
            ans2 = it->first;
        }
    }
    
    printf("%d %d\n", 0, ans2);
    return 0;
}