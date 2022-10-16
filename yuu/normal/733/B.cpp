#include <stdio.h>
#include <algorithm>
using namespace std;
int l[100001], r[100001];
int L, R;
int abs(int x){
    return x<0?-x:x;
}
int main(){
    int n;
    scanf("%i", &n);
    for(int i=1; i<=n; i++){
        scanf("%i%i", &l[i], &r[i]);
        L+=l[i];
        R+=r[i];
    }
    int k=0;
    int maxb=abs(L-R);
    for(int i=1; i<=n; i++){
        if(abs((L-l[i]+r[i])-(R-r[i]+l[i]))>maxb){
            maxb=abs((L-l[i]+r[i])-(R-r[i]+l[i]));
            k=i;
        }
    }
    printf("%d", k);
}