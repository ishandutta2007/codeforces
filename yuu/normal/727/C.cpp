#include <stdio.h>
using namespace std;
int n, A[5001];
int main(){
    scanf("%i", &n);
    int p=n/3, a, b, c;
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d", &a);
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d", &b);
    printf("? 3 1\n");
    fflush(stdout);
    scanf("%d", &c);
    int s=a+b+c;
    A[1]=(a-b+c)/2;
    A[2]=a-A[1];
    A[3]=b-A[2];
    for(int i=4; i<=n; i++){
        printf("? %d %d\n", i, 1);
        fflush(stdout);
        scanf("%d", &A[i]);
        A[i]-=A[1];
    }
    printf("!");
    for(int i=1; i<=n; i++)
        printf(" %d", A[i]);
}