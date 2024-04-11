#include<bits/stdc++.h>
using namespace std;


int T, n, m;
char s[101000], t[101000];

int gao(){
    int p1=n, p2=m;
    while (p1&&p2){
        if (s[p1]==t[p2]){
            p1--; p2--; continue;
        }
        p1=max(0,p1-2);
    }
    if (!p2) return 1;
    if (!p1) return 0;
}

int main(){
    for (cin>>T;T--;){
        cin>>s+1>>t+1;
        n=strlen(s+1);
        m=strlen(t+1);
        puts(gao()? "YES": "NO");
    }
}