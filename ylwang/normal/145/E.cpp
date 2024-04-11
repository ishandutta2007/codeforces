#include <bits/stdc++.h>
using namespace std;
char s[1000001];
inline int read() {
    int num=0;
    char c=' ';
    bool flag=1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return flag?num:-num;
}  
struct node {
	int l, r;
    int m4, m7, c4, c7;
    int lsy;
}dt[4000001];
#define ls (k<<1)
#define rs (k<<1|1)
void pushup(int k) {
    dt[k].c4 = dt[ls].c4 + dt[rs].c4;
    dt[k].c7 = dt[ls].c7 + dt[rs].c7;
    dt[k].m4 = max(dt[ls].m4+dt[rs].c7, dt[ls].c4+dt[rs].m4);
	dt[k].m7 = max(dt[ls].m7+dt[rs].c4, dt[ls].c7+dt[rs].m7);
}
void build(int k, int l, int r) {
	dt[k].l = l, dt[k].r = r;
    if(l == r) {
        dt[k].lsy = 0;
        if(s[l - 1] == '4') dt[k].c4 = 1;
        else dt[k].c7 = 1;
        dt[k].m4 = dt[k].m7 = 1; return ;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid); 
	build(rs, mid+1, r);
    pushup(k);
}
void lsy(int k) {
    dt[k].lsy ^= 1;
    swap(dt[k].m4, dt[k].m7);
    swap(dt[k].c4, dt[k].c7);
}
void update(int k, int l, int r) {
	int L = dt[k].l, R = dt[k].r;
    if(l == L && r == R) {
        lsy(k);
        return ;
    }
    if(dt[k].lsy) {
        lsy(ls); 
		lsy(rs); 
		dt[k].lsy=0;
    }
    int m=(L + R) >> 1;
    if(m>=r) {
        update(ls, l, r);
    } else if(l>m) {
        update(rs, l, r);
    } else {
        update(ls, l, m);
        update(rs, m+1, r);
    }
    pushup(k);
}
#undef ls
#undef rs
int main()
{
    int n = read(), m = read(), l, r;
	scanf("%s", s);
    build(1, 1, n);
    while(m--) {
    	char d[55];
        scanf("%s",d);
        if(d[0]=='s') {
             scanf("%d %d", &l, &r);
             update(1, l, r);
        } else {
             printf("%d\n", dt[1].m4);
        }
    }
    return 0;
}