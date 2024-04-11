# include <cstdio>
int main()
{
    int n;
    
    scanf("%d", &n);
    
    for (int i=0; i<n; ++i)
    {
        for (int k=0; k<n; ++k)
            printf("%d ", k*n+(k+i)%n+1);
            
        printf("\n");
    }
}