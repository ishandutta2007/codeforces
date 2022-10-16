#include <iostream>
#include <stdio.h>
using namespace std;
int s, x1, x2, t1, t2, p, d;
int ans;
int main(){
//    freopen("C.INP", "r", stdin);
    cin>>s>>x1>>x2;
    cin>>t1>>t2;
    cin>>p>>d;
    if(d==1){
        if(x1<x2){
            ans=(x2-x1)*t2;//i b
            if(p<=x1)//Nu tu khng cn quay li  gp -> nu i tu th chf tu n x2
                ans=min(ans, (x2-p)*t1);
            else//Nu tu ng xa hn th phi i quay li
                ans=min(ans, (s-p+s+x2)*t1);
        }
        else{
            ans=(x1-x2)*t2;
            ans=min(ans, (s-p+s-x2)*t1);
        }
    }
    else{
        if(x1<x2){
            ans=(x2-x1)*t2;//i b
            ans=min(ans, (p+x2)*t1);
        }
        else{
            ans=(x1-x2)*t2;
            if(p>=x1)
                ans=min(ans, (p-x2)*t1);
            else ans=min(ans, (p+s+s-x2)*t1);
        }
    }
    cout<<ans;
}