#include<bits/stdc++.h>
using namespace std;

int f[6666][6666],deg[6666][6666];
struct P{
  int x,y;
}u;
queue<P>q;

void pre(){
  
  for (int i=0;i<=8;++i)
    for (int ii=0;i+ii<=8;++ii)
      for (int iii=0;i+ii+iii<=8;++iii)
        for (int iv=0;i+ii+iii+iv<=8;++iv){
          
          int now=i*1+ii*9+iii*81+iv*729;
          if (!now) continue;
          f[now][0]=-1; q.push((P){now,0});
          
          for (int j=0;j<=8;++j)
            for (int jj=0;j+jj<=8;++jj)
              for (int jjj=0;j+jj+jjj<=8;++jjj)
                for (int jv=0;j+jj+jjj+jv<=8;++jv){
                  int el=j*1+jj*9+jjj*81+jv*729;
                  if (!el) continue;
                  deg[now][el]= (!!i+!!ii+!!iii+!!iv) *(!!j+!!jj+!!jjj+!!jv);
                }
        }
  
  for (;!q.empty();){
    u=q.front(); q.pop();
    static int a[5],b[5],x,y;
    x=u.x; y=u.y;
    for (int i=1;i<=4;++i) a[i]=y%9, y/=9; a[0]=8-a[1]-a[2]-a[3]-a[4];
    for (int i=1;i<=4;++i) b[i]=x%9, x/=9; b[0]=8-b[1]-b[2]-b[3]-b[4];
    
    for (int i=0;i<=4;++i) if (a[i])
      for (int j=1;j<=4;++j)
        if (b[j]&&i!=j){
          --a[i]; ++a[(i-j+5)%5];
          #define has(a) a[1]*1+a[2]*9+a[3]*81+a[4]*729
          x=has(a); y=has(b);
          if (f[u.x][u.y]==1){
            if (!--deg[x][y]){
              f[x][y]=-1; q.push((P){x,y});
            }
          }else{
            if (!f[x][y])
              f[x][y]=1, q.push((P){x,y});
          }
          ++a[i]; --a[(i-j+5)%5];
        }
  }
}

inline int rd(){
  static char s[3];
  scanf("%s",s); return s[0]-'0';
}

int in(){
  static int cnt[5],x;
  memset(cnt,0,sizeof cnt);
  for (int i=8;i--;) ++cnt[rd()];
  return has(cnt);
}

int main(){
  pre(); //return 0;
  int T,x,y,t,fir,res;
  for (scanf("%d",&T);T--;){
    fir=rd();
    x=in(); y=in();
    res= fir? -f[y][x]: f[x][y];
    switch (res){
      case 1: puts("Alice"); break;
      case 0: puts("Deal"); break;
      case -1: puts("Bob"); break;
    }
  }
}