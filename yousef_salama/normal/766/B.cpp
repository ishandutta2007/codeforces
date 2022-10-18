#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    
    bool found = false;
    for(int i = 2; i < n; i++)
        if(a[i - 2] + a[i - 1] > a[i])found = true;
    
    if(found)printf("YES\n");
    else printf("NO\n");
    
        
    return 0;
}