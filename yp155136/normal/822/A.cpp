#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main (){
    LL a,b;
    cin >>a >> b;
    LL mn=min(a,b);
    LL ans=1;
    for (int i=1;mn>=i;i++) ans*=i;
    cout<<ans<<endl;
}