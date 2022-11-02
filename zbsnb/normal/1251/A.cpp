#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long

char s[1010];

int main(){
    int t;cin>>t;
    while(t--){
        cin>>s;
        int a[30]={};
        for(int i=0;i<26;i++)a[i]=1;
        int len=strlen(s);
        int cnt=1;
        for(int i=1;i<=len;i++){
            if(i!=len&&s[i]==s[i-1])cnt++;
            else {
                if(cnt%2==1)a[s[i-1]-'a']=0;
                cnt=1;
            }
        }
        for(int i=0;i<26;i++){
            if(a[i]==0)cout<<(char)(i+'a');
        }
        cout<<endl;
    }
}