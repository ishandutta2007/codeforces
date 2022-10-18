#include <bits/stdc++.h>
using namespace std;

char s[100005], r[100005];
int n, m;

int main(){
    scanf("%s %s", s, r);
    
    n = strlen(s);
    m = strlen(r);
    
    if(strcmp(s, r) == 0)printf("-1\n");
    else printf("%d\n", max(n, m));
    
    return 0;
}