#include <bits/stdc++.h>
using namespace std;
const int N = 50005;

int a[N];

int main() {
    int n , start , x;
    scanf("%d%d%d" , &n , &start , &x);
    for (int i = 0 ; i < n ; ++ i) {
        a[i] = i + 1;
    }
    random_shuffle(a , a + n);
    random_shuffle(a , a + n);
    vector< pair<int , int> > v;
    int w = -1, y = start;
    int res = 1 << 30;
    for (int i = 0 ; i < min(n , 1600) ; ++ i) {
        printf("? %d\n" , a[i]);
        fflush(stdout);
        int val , nxt;
        scanf("%d%d" , &val , &nxt);
        if (val <= x && val > w) {
          y = nxt;
          w = val;
        }
        if (val >= x) {
            res = min(res , val);
        }
    }
    while (w < x && y != -1) {
        printf("? %d\n" , y);
        fflush(stdout);
        int val , nxt;
        scanf("%d%d" , &w , &y);
        if (w >= x) {
            res = min(res , w);
        }
    }
    if (w < x) w = -1;
    printf("! %d\n" , w);
    fflush(stdout);

    return 0;
}