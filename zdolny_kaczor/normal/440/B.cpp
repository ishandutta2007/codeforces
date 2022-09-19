# include <cstdio>
# define abs(a) ((a)>0?(a):-(a))
long long tab[50000];
long long int sum;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        scanf("%I64d", tab+i);
        sum+=tab[i];
    }
    sum/=n;
    long long res=0;
    for (int i=0; i<n-1; ++i)
    {
        res+=abs(tab[i]-sum);
        tab[i+1]+=tab[i]-sum;
    }
    printf("%I64d\n", res);
}