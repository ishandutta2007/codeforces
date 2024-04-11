#include <iostream>
#include <sstream>
using namespace std;
int main(){//abc def
    string s;
    cin>>s;
    long long n=s.size()-1;
    long long a;
    if(s[n]>'c') a='f'-s[n]+1;
    else a=s[n]-'a'+4;
    s.erase(s.begin()+n);
    stringstream ss(s);
    ss>>n;
    long long ans=(n-1)/4*16;
    n%=2;
    if(n==0)
        cout<<ans+a+7;
    else cout<<ans+a;
}