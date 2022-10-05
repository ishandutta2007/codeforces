#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string s;

int main(){
    cin>>s>>n;
    // if (s!="ABC"){
    //   assert(s[2]>='E');
    // }
    assert(s=="ABC"||s=="ARC"||s=="AGC");
    // puts(s=="ABC"||s=="ARC"? "Yes": "No");
    if (s=="ABC"){
      puts(n<2000? "Yes": "No");
    }else if (s=="ARC"){
      puts(n<2800? "Yes": "No");
    }else{
      puts(n>=1200? "Yes": "No");
    }
//     // assert(s[1]>='C'&&s[1]<='C');
//     assert(s[2]=='C');
    // cin>>n;
    // if (n==2999) cout<<n+1<<endl;
    // else{
    //     cout<<n+2<<endl;
    // }
}