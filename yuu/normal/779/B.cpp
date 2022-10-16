#include <iostream>
#include <stdio.h>
using namespace std;
string n;
int k, ok;
int ans=0;
#define taskname "B"
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    cin>>n>>k;
    int i=n.size()-1;
    ok=k;
    while(i>=0){
        if(n[i]=='0')
            ok--;
        else ans++;
        if(ok==0) break;
        i--;
    }
    if(ok>0)
        cout<<n.size()-1;
    else
        cout<<ans;
}