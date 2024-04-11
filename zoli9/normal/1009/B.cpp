#include <bits/stdc++.h>
using namespace std;
string s;
int one=0;
bool volte=false;
int main()

{
    cin>>s;
    for (int i=0; i<s.size(); i++){
        if (s[i]=='1')
            one++;
    }
    for (int i=0; i<s.size(); i++){
        if (s[i]=='2'){
            if (volte==false){
                for (int i=1;i<=one;++i){
                    cout<<1;
                    volte=true;
                }
                cout<<2;
            }
            else {
                cout<<s[i];
            }
        }
        else if (s[i]=='0'){
            cout<<s[i];
        }
    }
   if (volte==false){
        for (int i=1;i<=one;++i)
            cout<<1;
        }

    return 0;
}