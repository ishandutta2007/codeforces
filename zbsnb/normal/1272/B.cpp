#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
using namespace std;
#define ll long long
#define int long long

char s[1000010];

signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        int L=0,R=0,U=0,D=0;
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]=='L')L++;
            if(s[i]=='R')R++;
            if(s[i]=='U')U++;
            if(s[i]=='D')D++;
        }
        int a=min(L,R);
        int b=min(U,D);
        if(a==0&&b==0){
            cout<<0<<endl;
            continue;
        }
        if(a==0){
            cout<<2<<endl;
            cout<<"UD"<<endl;
            continue;
        }
        if(b==0){
            cout<<2<<endl;
            cout<<"LR"<<endl;
            continue;
        }
        cout<<2*(a+b)<<endl;
        for(int i=1;i<=a;i++)cout<<"L";
        for(int i=1;i<=b;i++)cout<<"U";
        for(int i=1;i<=a;i++)cout<<"R";
        for(int i=1;i<=b;i++)cout<<"D";
        cout<<endl;
    }
}