# include <cstdio>
# include <algorithm>
using namespace std;
int a[100100];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
        scanf("%d", a+i);
    sort(a, a+n);
    int sum=0, res=0;
    for (int i=0; i<n; ++i)
        if (a[i]>=sum)
        {
            sum+=a[i];
            res++;
        }
    printf("%d\n", res);
}