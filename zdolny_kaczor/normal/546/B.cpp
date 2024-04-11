# include <cstdio>
# include <algorithm>
using namespace std;
const int MN=3010;
int a[MN];
int main()
{
    int n;
    
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    
        scanf("%d", a+i);
        
    sort(a, a+n);
    
    int res=0;
    
    for (int i=1; i<n; ++i)
    
        if (a[i]<=a[i-1])
        
        {
        
            res+=(a[i-1]+1)-a[i];
            a[i]=a[i-1]+1;
        
        }
        
    printf("%d\n", res);
}