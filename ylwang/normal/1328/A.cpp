#include<bits/stdc++.h>
using namespace std;
long long a,b[10005],c[10005];
int main(){
    cin>>a;
    for(int i=1;i<=a;i++) cin>>b[i]>>c[i];
    for(int i=1;i<=a;i++) cout<<(c[i]-(b[i]%c[i]))%c[i]<<endl;
}