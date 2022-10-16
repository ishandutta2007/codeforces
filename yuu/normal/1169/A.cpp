#include <bits/stdc++.h>
using namespace std;
int n, a, b, x, y;
int main(){
    cin>>n>>a>>x>>b>>y;
    while(true){
        if(a==b){
            puts("YES");
            return 0;
        }
        if(a==x||b==y) break;
        a++;
        if(a==n+1) a=1;
        b--;
        if(b==0) b=n;
    }
    puts("NO");
}