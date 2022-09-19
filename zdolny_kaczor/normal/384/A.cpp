# include <cstdio>
int main()
{
    int n;
    
    scanf("%d", &n);
    
    printf("%d\n", (n*n+1)/2);
    
    for (int i=0; i<n; ++i)
    
    {
    
        for (int k=0; k<n; ++k)
        
            if ((i+k)%2) putchar('.'); else putchar('C');
            putchar(10);
    }
}