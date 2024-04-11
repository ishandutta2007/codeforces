#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    scanf("%d", &n);
    
    if((n % 4 == 2) || (n % 4 == 3)){ 
        printf("NO\n");
        return 0;
    }
    
    printf("YES\n");
    
    for(int i = 0; i < (n / 2); i++)
    for(int j = i + 1; j < (n / 2); j++){
        printf("%d %d\n", 2 * i + 1, 2 * j + 1);
        printf("%d %d\n", 2 * i + 2, 2 * j + 2);
        printf("%d %d\n", 2 * i + 1, 2 * j + 2);
        printf("%d %d\n", 2 * i + 2, 2 * j + 1);
    }
    
    if(n % 2 == 0){
        for(int i = 0; i < (n / 2); i++)
            printf("%d %d\n", 2 * i + 1, 2 * i + 2);
    }else{
        for(int i = 0; i < (n / 2); i++){
            printf("%d %d\n", 2 * i + 1, n);
            printf("%d %d\n", 2 * i + 1, 2 * i + 2);
            printf("%d %d\n", 2 * i + 2, n);
        }
    }
    
    return 0;
}