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

const int N = 2005;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m, deg[N][N], s;
pair <int, int> que[N * N];
char str[N][N];

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s++;
            if (str[i][j] == '.') {
                for (int d = 0; d < 4; d++) {
                    int x = i + dx[d], y = j + dy[d];
                    if (x >= 1 && x <= n && y >= 1 && y <= m && str[x][y] == '.') {
                        deg[i][j]++;
                    }
                }
            } else {
                s--;
            }
        }
    }
    
    int h, t = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (deg[i][j] == 1) {
                que[++t] = make_pair(i, j);
            }
        }
    }
    
    for (h = 1; h <= t; h++) {
        int x = que[h].first, y = que[h].second, dd = -1;
        if (str[x][y] != '.') {
            continue;
        }
        
        for (int d = 0; d < 4; d++) {
            int xx = x + dx[d], yy = y + dy[d];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && str[xx][yy] == '.') {
                dd = d;
                break;
            }
        }
        
        if (dd == -1 ){
            printf("Not unique\n");
            return 0;
        }
         
        if (dd == 0) {
            str[x][y] = '^';
            str[x + 1][y] = 'v';
        } else if (dd == 1) {
            str[x][y] = 'v';
            str[x - 1][y] = '^';
        } else if (dd == 2) {
            str[x][y] = '<';
            str[x][y + 1] = '>';
        } else {
            str[x][y] = '>';
            str[x][y - 1] = '<';
        }
        
        x += dx[dd], y += dy[dd];
        for (int d = 0; d < 4; d++) {
            int xx = x + dx[d], yy = y + dy[d];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && str[xx][yy] == '.') {
                deg[xx][yy]--;
                if (deg[xx][yy] == 1) {
                    que[++t] = make_pair(xx, yy);
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str[i][j] == '.') {
                printf("Not unique\n");
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%s\n", str[i] + 1);
    }
    
    return 0;
}