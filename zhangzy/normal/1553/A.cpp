#include<bits/stdc++.h>
using namespace std;

int T, n;

int main(){
    for (cin>>T;T--;){
        cin>>n;
        int c=n/10;
        if (n%10==9) ++c;
        printf("%d\n",c);
    }
}