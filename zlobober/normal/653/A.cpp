#include <cstdio>
using namespace std;

const int N = 1050;
bool was[N];


int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        was[x] = true;
    }

    bool ans = false;
    for (int i = 1; i + 2 < N; i++) {
        if (was[i] && was[i + 1] && was[i + 2])
            ans = true;
    }
    puts(ans ? "YES" : "NO");
}