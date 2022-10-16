#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int s=0;
    while(n--){
        int a, b;
        cin>>a>>b;
        if(a>b) s++;
        else if(a<b) s--;
    }
    if(s==0) cout<<"Friendship is magic!^^\n";
    else if(s>0) cout<<"Mishka\n";
    else cout<<"Chris\n";
}