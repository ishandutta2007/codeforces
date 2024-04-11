#include<bits/stdc++.h>
using namespace std;
#define N 40*80+5
char c[N];
int f[200005][305];
int b[N],nL;
char A[N][N],nc[N];
int F[N],n,m,M,tot,S,anslen,len[N];
char ans[N],C[N];
int id[N];
inline void Insert(int n,int p) {
    int gt=1;
    for (int i=0;i<n;i++) {
        if (!f[gt][c[i]]) f[gt][c[i]]=++tot;
        gt=f[gt][c[i]];
    }
    b[gt]=p;
}
inline void Insert1(int x,int p) {
    int gt=1;
    for (int i=0;i<len[x];i++) {
        if (!f[gt][A[x][i]]) f[gt][A[x][i]]=++tot;
        gt=f[gt][A[x][i]];
    }
    b[gt]=p;
}
inline int find(int x) {
    int gt=1;
    for (int i=0;i<len[x];i++) {
        gt=f[gt][A[x][i]];
        if (!gt) return 0;
    }
    return b[gt];
}
inline bool check(char c) {
    return ((c>='A'&&c<='Z')||(c>='a'&&c<='z')||c=='_'||c=='$');
}
inline bool checknum(char c) {
    return (c>='0'&&c<='9');
}
inline void work(int n) {
    for (int i=0;i<n;) {
        int gt=1;
        bool flag1=true;
        bool flag2=true;
        if (!check(c[i])) flag1=false;
        if (!checknum(c[i])) flag2=false;
        int k=-1;
        int gtw=0;
        for (int j=i;j<n;j++) {
            if (j-i>100) break;
            if (!check(c[j])&&!checknum(c[j])) flag1=false;
            if (!checknum(c[j])) flag2=false;
            gt=f[gt][c[j]];
            if (flag1||flag2||b[gt]==-1) {
                k=j;
                if (flag2) gtw=1;
                else gtw=0;
            }
        }
        ++m;
        for (int j=i;j<=k;j++) A[m][len[m]++]=c[j];
        if (!find(m)&&!gtw) Insert1(m,++M);
        i=k+1;
    }
}

inline bool check1(int L) {
    int s=0;
    for (int i=0;i<L;) {
        int gt=1;
        bool flag1=true;
        bool flag2=true;
        if (!check(c[i])) flag1=false;
        if (!checknum(c[i])) flag2=false;
        int k;
        for (int j=i;j<L;j++) {
            if (j-i>100) break;
            if (!check(c[j])&&!checknum(c[j])) flag1=false;
            if (!checknum(c[j])) flag2=false;
            gt=f[gt][c[j]];
            if (flag1||flag2||b[gt]==-1) k=j;
        }
        if (!F[k+1]) return false;
        i=k+1;
        s++;
    }
    return s==S;
}
inline void get(int x) {
    nL=0;
    if (x<=26) nL=1;
    else if (x<=26+26*26) nL=2,x-=26;
    else nL=3,x-=26+26*26;
    x--;
    for (int i=nL-1;i>=0;i--) {
        nc[i]=char('a'+x%26);
        x/=26;
    }
}
int main() {
    //freopen("j.in","r",stdin);
    scanf("%d",&n);
    tot=1;
    for (int i=1;i<=n;i++) {
        scanf("%s",c);
        Insert(strlen(c),-1);
    }
    int j=1;
    for (int i=1;i<=40*80;i++) {
        while (1) {
            get(j);
            int gtw=1;
            for (int k=0;k<nL;k++) gtw=f[gtw][nc[k]];
            if (b[gtw]!=-1) break;
            j++;
        }
        id[i]=j;
        j++;
    }
    scanf("%d",&n);
    getchar();
    for (int _i=1;_i<=n;_i++) {
        cin.getline(C,1000,'\n');
        int ll=0,last=0;
        bool flag=1;
        while (last<strlen(C)) {
            ll=0;
            int i;
            for (i=last;i<strlen(C);i++) {
                if (C[i]=='#') {
                    flag=0;
                    break;
                }
                if (C[i]==' ') break;
                c[ll++]=C[i];
            }
            last=i+1;
            work(ll);
            if (!flag) break;
        }
    }
    for (int i=1;i<=m;i++) {
        int p=find(i);
        if (p>0) {
            get(id[p]);
            len[i]=nL;
            for (int j=0;j<len[i];j++) A[i][j]=nc[j];
        }
    }
    int L=len[1];
    for (int i=0;i<L;i++) c[i]=A[1][i];
    F[L]=1;
    S=1;
    for (int i=2;i<=m;i++) {
        for (int j=0;j<len[i];j++) c[L++]=A[i][j];
        F[L]=1;
        S++;
        if (check1(L)) continue;
        else {
            for (int j=0;j<=L;j++) F[j]=0;
            for (int j=0;j<L-len[i];j++) ans[anslen++]=c[j];
            ans[anslen++]=' ';
            L=len[i];
            for (int j=0;j<L;j++) c[j]=A[i][j];
            F[L]=1;
            S=1;
        }
    }
    for (int j=0;j<L;j++) ans[anslen++]=c[j];
    for (int i=0;i<anslen;i++) printf("%c",ans[i]);
}