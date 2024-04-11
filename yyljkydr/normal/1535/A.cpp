#include<bits/stdc++.h>
using namespace std;


int T,a,b,c,d;

int main(){
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c>>d;
        if(min(a,b)>max(c,d)||min(c,d)>max(a,b))
        cout<<"No\n";
        else cout<<"Yes\n";
    }
}