#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,ans[N],a[N],q[N];
char c[N];
inline bool check(int x,int y) {
    if (x<=2) return true;
    if (ans[1]!=ans[x-1]) return true;
    if (ans[2]!=y) return true;
    return false;
}
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%s",c);
        n=strlen(c);
        for (int i=1;i<=26;i++) a[i]=0;
        for (int i=0;i<n;i++) a[c[i]-'a'+1]++;
        int s=0;
        for (int i=1;i<=26;i++) {
            if (a[i]) q[++s]=i;
        }
        
        if (s==1) {
            printf("%s\n",c);
            continue;
        }
        int x=0;
        for (int i=1;i<=26;i++) {
            if (a[i]==1) {
                x=i;
                break;
            }
        }
        if (x) {
            int j=1;
            printf("%c",char(x+'a'-1));
            a[x]=0;
            for (;j<=26;j++) {
                while (a[j]) {
                    printf("%c",char(j+'a'-1));
                    a[j]--;
                }
            }
            puts("");
            continue;
        }
        int ff=0;
        for (int i=1;i<=n;i++) {
            int j=1;
            for (;j<=s;j++) {
                if (!a[q[j]]) continue;
                if (check(i,j)) {
                    a[q[j]]--;
                    ans[i]=j;
                    break;
                }
            }
            if (j>s) ff=1;
        }

        if (ff) {
            for (int i=1;i<=26;i++) a[i]=0;
            for (int i=0;i<n;i++) a[c[i]-'a'+1]++;
            ans[1]=1;
            ans[2]=2;
            a[q[1]]--;
            a[q[2]]--;
            ff=0;
            for (int i=3;i<=n;i++) {
                int j=1;
                for (;j<=s;j++) {
                    if (!a[q[j]]) continue;
                    if (check(i,j)) {
                        a[q[j]]--;
                        ans[i]=j;
                        break;
                    }
                }
                if (j>s) ff=1;
            }
        }
        if (ff) {
            assert(s==2);
            for (int i=1;i<=26;i++) a[i]=0;
            for (int i=0;i<n;i++) a[c[i]-'a'+1]++;
            ans[1]=1;
            a[q[1]]--;
            int p=2;
            for (int j=1;j<=a[q[2]];j++) ans[p++]=2;
            for (int j=1;j<=a[q[1]];j++) ans[p++]=1;
            
        }

        for (int i=1;i<=n;i++) printf("%c",char(q[ans[i]]+'a'-1));
        puts("");
    }
}