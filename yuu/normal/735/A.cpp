#include <iostream>
using namespace std;
string s;
int n, k;
int t, g;
int main(){
    cin>>n>>k;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='T')
            t=i;
        if(s[i]=='G')
            g=i;
    }
    if(t<g) swap(g, t);
    while(g<t){
        g+=k;
        if(g>t){
            cout<<"NO";
            return 0;
        }
        else if(g==t){
            cout<<"YES";
            return 0;
        }
        if(s[g]=='#'){
            cout<<"NO";
            return 0;
        }
    }
}