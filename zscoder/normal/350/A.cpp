#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 300 + 5;

int n, m, a[N], b[N]; 

int main()
{
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    
    sort(a, a + n);
    sort(b, b + m);

    int tmin = 2 * a[0];
    
    tmin = max(tmin, a[n - 1]);
    
    if (b[0] <= tmin)
        puts("-1");
    else
        printf("%d", tmin);
    
    return 0;   
}