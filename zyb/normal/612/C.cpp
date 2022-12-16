#include<stdio.h>
#include<cstring>
using namespace std;
int i,l,ans,r;
char c[1000005],q[1000005];
int main() {
    scanf("%s",c);
    l=strlen(c);
    for (i=0;i<l;i++) {
        if (c[i]=='['||c[i]=='{'||c[i]=='('||c[i]=='<') q[++r]=c[i];
        else {
            if (c[i]==']') c[i]='[';
            if (c[i]=='}') c[i]='{';
            if (c[i]==')') c[i]='(';
            if (c[i]=='>') c[i]='<';
            if (!r) return printf("Impossible\n"),0;
            if (q[r--]!=c[i]) ans++;
        }
    }
    if (r) return printf("Impossible\n"),0;
    printf("%d\n",ans);
}