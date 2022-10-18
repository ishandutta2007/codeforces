#include <bits/stdc++.h>
using namespace std;

int n, m, k;

bool win(int x){
    if(k == 1){
        if(m == 1)return false;
        else return true;
    }
    if(x % 2 == 0 && x / 2 >= k)return true;
    
    for(int d = 3; d * d <= x; d++){
        if(x % d == 0){
            if(d >= k && !win(d))return true;
            if(x / d >= k && !win(x / d))return true;
        }
    }
    return false;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    if(n % 2 == 0){
        printf("Marsel\n");
    }else{
        if(win(m))printf("Timur\n");
        else printf("Marsel\n");
    }
    return 0;
}