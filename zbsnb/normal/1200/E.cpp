#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
#define ll long long

const ll mod1=1e9+7;
const ll mod2=1e9+9;

string s[100010];

int calcu(string &a,string &b){
    int ret=0;ll ha1=0,ha2=0,hb1=0,hb2=0;ll p1=1,p2=1;
    int lena=a.size();
    int lenb=b.size();
    int m=min(lena,lenb);
    for(int i=1;i<=m;i++){
        ha1=(ha1+p1*a[lena-i])%mod1;
        ha2=(ha2+p2*a[lena-i])%mod2;

        hb1=(hb1*131+b[i-1])%mod1;
        hb2=(hb2*137+b[i-1])%mod2;

        if(ha1==hb1&&ha2==hb2){
            ret=i;
        }

        p1=p1*131%mod1;
        p2=p2*137%mod2;
    }
    return ret;
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=2;i<=n;i++){
        int num=calcu(s[1],s[i]);
        s[1].append(s[i],num,s[i].size());
    }
    cout<<s[1]<<endl;
}