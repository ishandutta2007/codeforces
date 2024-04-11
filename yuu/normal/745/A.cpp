#include <iostream>
#include <map>
using namespace std;
string s;
map <string, int> m;
int cnt=0;
int main(){
    cin>>s;
    m[s]=++cnt;
    for(int i=1; i<s.size(); i++){
        s=s[s.size()-1]+s;
        s.erase(s.end()-1);
        if(m[s]==0)
            m[s]=++cnt;
    }
    cout<<cnt;
}