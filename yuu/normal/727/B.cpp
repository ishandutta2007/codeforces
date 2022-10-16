#include <iostream>
#include <vector>
using namespace std;
vector <string> p;
long long intpart, floatpart;
long long getint(string s){
    long long n=0;
    for(int x=0; x<s.size(); x++){
        if(s[x]=='.') continue;
        n=n*10+(long long)s[x]-48ll;
    }
    return n;
}
long long getintskip(string s){
    long long n=0;
    int pmax=s.size()-3;
    for(int x=0; x<pmax; x++){
        if(s[x]=='.') continue;
        n=n*10+(long long)s[x]-48ll;
    }
    return n;
}
long long getfloat(string s){
    int pmax=s.size()-2;
    return (s[pmax]-48)*10+s[pmax+1]-48;
}
int main(){
    string s, ss;
    cin>>s;
    int x=0;
    while(x<s.size()){
        while(s[x]>='a'&&s[x]<='z'&&x<s.size())
            x++;
        ss="";
        while(s[x]<'a'&&x<s.size()){
            ss+=s[x];
            x++;
        }
        p.push_back(ss);
    }
    for(int i=p.size()-1; i>=0; i--){
        if(p[i].size()<4) intpart+=getint(p[i]);
        else{
            if(p[i][p[i].size()-3]=='.'){
                floatpart+=getfloat(p[i]);
                intpart+=getintskip(p[i]);
            }
            else intpart+=getint(p[i]);
        }
    }
    string ans="";
    if(floatpart>0){
        intpart+=floatpart/100;
        floatpart%=100;
        if(floatpart>0){
            ans=char(floatpart%10+48);
            floatpart/=10;
            ans=char(floatpart%10+48)+ans;
            ans='.'+ans;
        }
    }
    int c=0;
    if(intpart==0){
        ans='0'+ans;
        cout<<ans;
    }
    else{
        while(intpart>0){
            c++;
            ans=char(intpart%10+48)+ans;
            intpart/=10;
            if(c%3==0&&intpart>0)
                ans='.'+ans;
        }
        cout<<ans;
    }
}