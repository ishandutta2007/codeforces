#include<bits/stdc++.h>
using namespace std;
int _,cnt[10];
char s[155];

int main(){
    cin >> _;
    while (_--){
        cin >> s; 
        memset(cnt,0,sizeof(cnt));
        int n=strlen(s),sum=0;
        for (int i=0;i<n;i++) sum+=s[i]-'0',cnt[s[i]-'0']++;
        if (sum%3!=0||cnt[0]==0){puts("cyan");continue;}
        bool flag=cnt[0]>1;
        for (int i=2;i<10;i+=2) flag|=cnt[i]>0;
        if (flag) puts("red"); else puts("cyan");
    }
    return 0;
}