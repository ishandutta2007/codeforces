#include<bits/stdc++.h>
using namespace std;
int n,m,maxx,maxy,minx=55,miny=55;
char ch[55][55];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ch[i][j]=getchar();
            while(ch[i][j]!='*'&&ch[i][j]!='.') ch[i][j]=getchar();
            if(ch[i][j]=='*'){
                minx=min(minx,i);
                miny=min(miny,j);
                maxx=max(maxx,i);
                maxy=max(maxy,j);
            } 
        }
    }
    for(int i=minx;i<=maxx;i++){
        for(int j=miny;j<=maxy;j++){
            cout<<ch[i][j];
        }
        cout<<endl;
    }
    return 0;
}