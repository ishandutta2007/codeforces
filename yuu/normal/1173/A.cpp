#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y, z;
    cin>>x>>y>>z;
    x-=y;
    if(z==0){
        if(x>0) cout<<"+";
        else if(x==0) cout<<"0";
        else cout<<"-";
    }
    else{
       if(z>=abs(x)) cout<<"?";
       else{
            if(x>0) cout<<"+";
            else if(x==0) cout<<"0";
            else cout<<"-";
       }
    }
}