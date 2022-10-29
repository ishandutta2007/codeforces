#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    string i;
    while (cin >> i) {
        for (int x=0;i.size()>x;x++) {
            char c=i[x];
            if (c<'a') c += ('a'-'A');
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y') ;
            else cout<<"."<<c;
        }
        cout<<endl;
    }
}