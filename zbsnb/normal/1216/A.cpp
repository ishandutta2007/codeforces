#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    char s[200010];cin>>s;
    int cnt=0;
    for(int i=0;i<n/2;i++){
        if(s[i*2]==s[i*2+1])s[i*2]='a',s[i*2+1]='b',cnt++;
    }
    cout<<cnt<<endl;
    cout<<s<<endl;
}