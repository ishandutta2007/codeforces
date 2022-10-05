#include<bits/stdc++.h>
using namespace std;

int n,cnt,fl;
char s[6666];

int ok(char c){
    if (c=='a') return 0;
    if (c=='e') return 0;
    if (c=='i') return 0;
    if (c=='o') return 0;
    if (c=='u') return 0;
    return 1;
}

int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    cnt=0;fl=1;
    for (int i=1;i<=n;i++){
        if (ok(s[i])){
            cnt++;
            if (cnt>=2){
                if (s[i]!=s[i-1]) fl=0;
            }
            if (cnt>=3&&!fl){
                printf(" ");
                cnt=1;
                fl=1;
            }
        }else{
            cnt=0;
            fl=1;
        }
        printf("%c",s[i]);
    }
}