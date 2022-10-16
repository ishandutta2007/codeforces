#include <iostream>
using namespace std;
int n;
string s;
int dc;
int ac;
int main(){
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++)
        dc+=(s[i]=='D');
    ac=n-dc;
    if(ac>dc)
        cout<<"Anton";
    else if(ac<dc)
        cout<<"Danik";
    else cout<<"Friendship";
}