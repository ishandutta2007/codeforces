#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    cin>>n>>m;
    if(m==n) cout<<0;
    else if(m<=1) cout<<1;
    else{
        n--;
        m--;
        while(m*2>=n){
            n--;
            m--;
        }
        cout<<m+1;
    }
}