#include<bits/stdc++.h>
using namespace std;

string s;
int k,l;
int cnt;
int xing,wen;

template<typename Tp>
void read(Tp &x){
    x=0;char ch=1;int fh;
    while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
    if(ch=='-'){
        ch=getchar();fh=-1;
    }
    else fh=1;
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    x*=fh;
}

int main(){
    cin>>s;cin>>k;
    l=s.size();
    for(register int i=0;i<l;i++){
        if(s[i]>='a'&&s[i]<='z') cnt++;
        else if(s[i]=='*') xing++;
        else wen++;
    }
    if(cnt-xing-wen>k||(cnt<k&&xing==0)){
        puts("Impossible");return 0;
    }
    if(cnt>=k){
        int del=cnt-k;
        for(register int i=0;i<l;i++){
            if(s[i]=='*'||s[i]=='?') continue;
            if(i==l-1||(s[i+1]>='a'&&s[i+1]<='z')) putchar(s[i]);
            else if(!del){
                putchar(s[i]);
            }
            else del--;
        }
        return 0;
    }
    else{
        int add=k-cnt;
        for(register int i=0;i<l;i++){
            if(s[i]=='*'||s[i]=='?') continue;
            if(i==l-1||(s[i+1]>='a'&&s[i+1]<='z')) putchar(s[i]);
            else if(!add) putchar(s[i]);
            else{
                putchar(s[i]);
                if(s[i+1]=='*'){
                    while(add){
                        putchar(s[i]);add--;
                    }
                }
            }
        }
    }
    return 0;
}