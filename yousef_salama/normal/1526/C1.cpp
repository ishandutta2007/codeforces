#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    long long sum = 0;
    multiset <int> s;
    
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        
        while(sum + a < 0){
            if(*s.begin() >= a)break;
            sum -= *s.begin();
            s.erase(s.begin());
        }
        if(sum + a >= 0){
            s.insert(a);
            sum += a;
        }
    }
    printf("%d\n", (int)s.size());
    
    return 0;
}