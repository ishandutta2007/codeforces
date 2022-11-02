#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, m, c[10], a[10][N], tot;

map <int, int> tr[N*5];

struct Heap {
    int pos, id[10], val;

    bool operator < (const Heap tmp) const {
        return val < tmp.val;
    }
} A;

priority_queue <Heap> q;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);

        for (int j = 1; j <= c[i]; j++)
            scanf("%d", &a[i][j]);
    }

    scanf("%d", &m);

    for (int i = 1; i <= m; i++) {
        for (int x = 0, y, j = 0; j < n; j++) { 
            scanf("%d", &y);

            if (!tr[x].count(y))
                tr[x][y] = ++tot;
            
            x = tr[x][y];
        }
    }

    for (int i = 0; i < n; i++) 
        A.id[i] = c[i], A.val += a[i][c[i]];
    
    q.push(A);

    while (!q.empty()) {
        Heap tmp = q.top(); q.pop();

        bool ok = 0;

        for (int x = 0, i = 0; i < n; i++) {
            if (!tr[x].count(tmp.id[i])) {
                ok = 1;
                break;
            }

            x = tr[x][tmp.id[i]];
        }
        
        if (ok) {
            for (int i = 0; i < n; i++)
                printf("%d ", tmp.id[i]);
            
            return 0;
        }
        
        for (int i = tmp.pos; i < n; i++) {
            Heap cur = tmp;
            cur.pos = i;

            if (cur.id[i] > 1) {
                cur.val += a[i][cur.id[i] - 1] - a[i][cur.id[i]];
                cur.id[i]--;
                q.push(cur);
            }
        }
    }
}