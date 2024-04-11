#include<bits/stdc++.h>
using namespace std;
int l[27],r[27],t=0x3f3f3f3f;
char s[1000005]; 
int main(){
    scanf("%s",s+1);
    int c=strlen(s+1); 
    for(int i=1;i<=c;i++){
        int id=s[i]-97;
        l[id]=max(l[id],i-r[id]);
        r[id]=i;
    }
    for(int i=0;i<26;i++) l[i]= l[i]==0?0:max(l[i],c+1-r[i]); 
    for(int i=0;i<26;i++)t=l[i]==0?t:min(t,l[i]); 
    cout<<t;
}