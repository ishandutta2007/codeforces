#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
//    freopen("B.INP", "r", stdin);
    ios_base::sync_with_stdio(false);
    int pos=0;
    int N=0;
    int S=20000;
    int n, t;
    string s;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>t>>s;
        if(pos==N&&s!="South"){
            puts("NO");
            return 0;
        }
        if(pos==S&&s!="North"){
            puts("NO");
            return 0;
        }
        if(s=="South"){
            pos+=t;
            if(pos>20000){
                puts("NO");
                return 0;
            }
        }
        else if(s=="North"){
            pos-=t;
            if(pos<0){
                puts("NO");
                return 0;
            }
        }
    }
    if(pos!=0) puts("NO");
    else puts("YES");
}