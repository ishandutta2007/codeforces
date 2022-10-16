#include <iostream>
using namespace std;
int main(){
    string s;
    int n;
    cin>>n>>s;
    n--;
    int cnt=0;
    int i=0;
    while(i<=n){
        if(s[i]=='<')
            cnt++;
        else break;
        i++;
    }
    i=n;
    while(i>=0){
        if(s[i]=='>')
            cnt++;
        else break;
        i--;
    }
    cout<<cnt;
}