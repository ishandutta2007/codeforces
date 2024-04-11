#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
bool a[26];
for(int i=0;i<26;i++)a[i]=false;
int ans=0;
cin>>s;
int l=s.size();
for(int i=0;i<l;i++){
s[i]-='a';
for(int j=0;j<26;j++){if(s[i]==j)a[j]=true;}}
for(int i=0;i<26;i++){if(a[i])ans++;}
ans%=2;
if(ans==0){cout<<"CHAT WITH HER!"<<endl;}
if(ans==1){cout<<"IGNORE HIM!"<<endl;}
}