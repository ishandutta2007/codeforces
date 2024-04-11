#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string vowels="AEIOUY";
    string x;
    cin>>x;
    x+="A";
    int last=-1,max=-1;
    for(int i=0;i<x.size();i++){
        if (vowels.find(x[i])!=string::npos){
            max=max>(i-last)?max:i-last;
            last=i;
        }
    }
    cout<<max;
return 0;
}