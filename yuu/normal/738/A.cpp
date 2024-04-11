#include <iostream>
using namespace std;
int main(){
    string s;
    int n;
    cin>>n>>s;
    while((n=s.find("ogo"))!=-1){
        s.replace(s.begin()+n, s.begin()+n+3, "***");
        while((n=s.find("***go"))!=-1)
            s.replace(s.begin()+n, s.begin()+n+5, "***");
    }
    cout<<s;
}