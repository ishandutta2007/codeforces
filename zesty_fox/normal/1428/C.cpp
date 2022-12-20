#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T;
char s[200010];
int main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        int len=strlen(s+1),cnta=0,cntb=0,pos1=1,pos2=len;
        for(int i=1;i<=len;i++){
            if(s[i]=='A') cnta++;
            else{
                cntb++;
                if(cnta) cnta--,cntb--;
            }
        }   
        cntb%=2;
        printf("%d\n",cnta+cntb);
    }
    return 0;
}