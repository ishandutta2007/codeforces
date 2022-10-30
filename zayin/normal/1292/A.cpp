#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,m;
int cnt0,cnt1;
int col[5][maxn];

void upd(int x,int y,int s)   {
    if (!col[x][y]) return ;
    if (y>1&&col[3-x][y-1])
        cnt0+=s;
    if (y<n&&col[3-x][y+1])
        cnt0+=s;
    if (col[3-x][y])
        cnt1+=s;
}


int main()  {
    scanf("%d%d",&n,&m);
    while (m--) {
        int x,y;
        scanf("%d%d",&x,&y);
        upd(x,y,-1);
        col[x][y]^=1;
        upd(x,y,1);

        // cout<<cnt0<<" "<<cnt1<<endl;
        puts((cnt0||cnt1)?"No":"Yes");
    }
    return 0;
}