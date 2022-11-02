#include<bits/stdc++.h>
#define maxn 1050

using namespace std;
char s[maxn];
int n;
int main(){
    cin >> s;
    n=strlen(s);
    for (int i=1;i<n;i++) printf("%d ",(bool)(s[i]!=s[i-1]));
    printf("%d\n",(bool)(s[n-1]=='a'));
    return 0;
}