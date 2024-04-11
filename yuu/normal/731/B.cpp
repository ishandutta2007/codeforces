#include <stdio.h>
int a[200001], n;
int main(){
    scanf("%i%i", &n, &a[1]);
    for(int i=2; i<=n; i++){
        scanf("%i", &a[i]);
        if(a[i-1]%2){
            a[i]--;
            a[i-1]--;
            if(a[i]<0){
                printf("NO");
                return 0;
            }
        }
    }
    for(int i=1; i<=n; i++)
        if(a[i]%2){
            printf("NO");
            return 0;
        }
    printf("YES");
}