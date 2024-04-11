#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5006;

int ask(int i,int j) {
    printf("? %d %d\n",i,j);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    if (ret == -1) exit(0);
    return ret;
}

int p[MAX_N];
int b[MAX_N];
int q[MAX_N];
int q1[MAX_N];
int q2[MAX_N];

int main () {
    int n;
    scanf("%d",&n);
    if (n&1) {
        int b0=0;
        for (int i=0;n>i;i++) {
            q[i] = ask(i,0);
            b0 ^= i;
            b0 ^= q[i];
        }
        for (int i=0;n>i;i++) {
            p[i] = (q[i]^b0);
        }
        puts("!");
        puts("1");
        for (int i=0;n>i;i++) {
            if (i) printf(" ");
            printf("%d",p[i]);
        }
        puts("");
        fflush(stdout);
    }
    else {
        for (int i=0;n>i;i++) {
            q1[i] = ask(i,i);
        }
        for (int i=0;n>i;i++) {
            q2[i] = ask((i+1)%n,(i));
        }
        int ans=0;
        int id=-1;
        for (int ii=0;n>ii;ii++) {
            p[0] = ii;
            b[0] = (ii^q1[0]);
            bool can=true;
            for (int i=1;n>i;i++) {
                p[i] = (b[i-1]^q2[i-1]);
                b[i] = (p[i]^q1[i]);
            }
            can = ((p[0]^b[n-1]) == q2[n-1]);
            if (!can) continue;
            for (int i=0;n>i;i++) {
                can &= (p[b[i]] == i);
            }
            if (can) {
                id = ii;
                ans++;
            }
        }
        puts("!");
        printf("%d\n",ans);
        for (int ii=id;ii>=id;ii++) {
            p[0] = ii;
            b[0] = (ii^q1[0]);
            bool can=true;
            for (int i=1;n>i;i++) {
                p[i] = (b[i-1]^q2[i-1]);
                b[i] = (p[i]^q1[i]);
            }
            can = ((p[0]^b[n-1]) == q2[n-1]);
            if (!can) continue;
            for (int i=0;n>i;i++) {
                can &= (p[b[i]] == i);
            }
            if (can) {
                id = ii;
                ans++;
            }
            break;
        }
        for (int i=0;n>i;i++) {
            if (i) printf(" ");
            printf("%d",p[i]);
        }
        puts("");
        fflush(stdout);
    }
}