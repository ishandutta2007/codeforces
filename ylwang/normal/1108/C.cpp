#include<cstdio>
#define Rint register int
using namespace std;
const int N = 200003;
int n, a[N], ans = 1 << 30, c[3], ch[3];
bool vis[3];
char s[N];
inline void dfs(int dep){
    if(dep == 3){
        int res = 0;
        for(Rint i = 0;i < n;i ++)
            res += (a[i] != c[i % 3]);
        if(ans > res){
            ans = res;
            ch[0] = c[0]; ch[1] = c[1]; ch[2] = c[2];
        }
        return;
    }
    for(Rint i = 0;i < 3;i ++)
        if(!vis[i]){
            vis[i] = true;
            c[dep] = i;
            dfs(dep + 1);
            vis[i] = false;
        }
}
int main(){
    scanf("%d%s", &n, s);
    for(Rint i = 0;i < n;i ++)
        if(s[i] == 'R') a[i] = 0;
        else if(s[i] == 'G') a[i] = 1;
        else if(s[i] == 'B') a[i] = 2;
    dfs(0);
    printf("%d\n", ans);
    for(Rint i = 0;i < n;i ++)
        if(ch[i % 3] == 0) putchar('R');
        else if(ch[i % 3] == 1) putchar('G');
        else putchar('B');
}