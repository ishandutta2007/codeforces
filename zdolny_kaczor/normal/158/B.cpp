# include <cstdio>
# define max(a, b) ((a)>(b)?(a):(b))
# define min(a, b) ((a)<(b)?(a):(b))
int amo[5];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        int x;
        scanf("%d", &x);
        amo[x]++;
    }
    printf("%d\n", amo[4]+amo[3]+(amo[2]+1)/2+(3+max(0, amo[1]-amo[3]-2*(amo[2]%2)))/4);
}