#include<iostream>
#include<string>
using namespace std;

int main(){
string s,t;
cin>>s>>t;
int ans=0,n=t.size();
for(int i=0;i<n;i++){
if(s[ans]==t[i])ans++;
}
cout<<ans+1<<endl;
}