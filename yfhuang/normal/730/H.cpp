#include<iostream>
#include<cstring>
#include<cstdio>


using namespace std;
#define N 110

char s[N][N];
char ans[N];
int n,m,a[N];

bool v[N];

bool check(char s1[],char s2[]){
    if (strlen(s1)!=strlen(s2)) return 0;
    int len=strlen(s1);
    for (int i=0;i<len;i++){
        if (s2[i]=='?') continue;
        if (s1[i]!=s2[i]) return 0;
    }
    return 1;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%s",s[i]);
    }
    memset(v,0,sizeof(v));
    for (int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        v[a[i]]=1;
    }
    strcpy(ans,s[a[1]]);
    int len=strlen(ans);
    bool flag=1;
    for (int i=2;i<=m;i++){
        if (strlen(s[a[i]])!=len) {flag=0;break;}
        for (int j=0;j<len;j++) if (ans[j]!=s[a[i]][j]) ans[j]='?';
    }
    for (int i=1;i<=n;i++){
        if (v[i]) continue;
        if (check(s[i],ans)) { flag=0;break;}
    }
    if (flag) printf("Yes\n%s\n",ans);
    else printf("No\n");
}