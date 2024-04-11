#include <iostream>
using namespace std;
string s;
int main(){
    cin>>s;
    s='A'+s+'A';
    int lv=0;
    int nd=0;
    for(int i=1; i<s.size(); i++){
        if(s[i]=='A'||s[i]=='I'||s[i]=='U'||s[i]=='E'||s[i]=='O'||s[i]=='Y'){
            nd=max(nd, i-lv);
            lv=i;
        }
    }
    cout<<nd;
}