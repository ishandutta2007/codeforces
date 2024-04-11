#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
    LL m,b;
    cin >> m >> b;
    LL ans=0;
    for (LL x=0;m*b>=x;x++) {
        LL y=(-x + m*b)/m;
        //cout<<"X = "<<x<<" ,y = "<<y<<endl;
        ans = max(ans,(y+1)*(x*(x+1))/2 + (x+1)*(y*(y+1))/2);
    }
    cout<<ans<<endl;
}