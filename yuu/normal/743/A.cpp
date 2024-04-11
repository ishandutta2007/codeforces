#include <iostream>
using namespace std;
string s;
int n, a, b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>b>>s;
    if(s[a-1]==s[b-1])
        cout<<0;
    else cout<<1;
}