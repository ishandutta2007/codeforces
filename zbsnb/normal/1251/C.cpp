#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long

char s[300010];
char s1[300010];
char s2[300010];
int main(){
    int t;cin>>t;
    while(t--){
        cin>>s;
        int p1=0,p2=0;
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if((s[i]-'0')%2==0)s1[++p1]=s[i];
            else s2[++p2]=s[i];
        }
        int l1=1,l2=1;
        for(int i=0;i<len;i++){
            if(l1>p1){
                cout<<s2[l2++];
                continue;
            }
            if(l2>p2){
                cout<<s1[l1++];
                continue;
            }
            //cout<<l1<<l2<<endl;
            if(s1[l1]>s2[l2])cout<<s2[l2++];
            else cout<<s1[l1++];
        }
        cout<<endl;
    }
}