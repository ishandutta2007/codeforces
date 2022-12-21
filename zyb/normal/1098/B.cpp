#include<bits/stdc++.h>
#define maxn 300005

using namespace std;
char s[maxn];
vector <int> a[maxn],b[maxn];
int ans,o[maxn],n,m,tp,d[maxn],dx,dy,dz,dw;

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++){
        scanf("%s",s);
        a[i].resize(m);
        for (int j=0;j<m;j++){
            if (s[j]=='A') a[i][j]=0;
            if (s[j]=='T') a[i][j]=1;
            if (s[j]=='G') a[i][j]=2;
            if (s[j]=='C') a[i][j]=3;
        }
    }
    ans=n*m;
    for (int x=0;x<4;x++) for (int y=x+1;y<4;y++){
        int z,w,res,tot1,tot2; res=0;
        for (int i=0;i<4;i++) if (i!=x&&i!=y) {z=i; break;}
        for (int i=0;i<4;i++) if (i!=x&&i!=y&&i!=z) {w=i; break;}
        for (int i=0;i<n;i+=2){
            tot1=tot2=0;
            for (int j=0;j<m;j+=2){
                tot1+=(a[i][j]!=x);
                tot2+=(a[i][j]!=y);
            }
            for (int j=1;j<m;j+=2){
                tot1+=(a[i][j]!=y);
                tot2+=(a[i][j]!=x);
            }
            if (tot1<tot2) res+=tot1,o[i]=1; else res+=tot2,o[i]=0;
        }
        for (int i=1;i<n;i+=2){
            tot1=tot2=0;
            for (int j=0;j<m;j+=2){
                tot1+=(a[i][j]!=z);
                tot2+=(a[i][j]!=w);
            }
            for (int j=1;j<m;j+=2){
                tot1+=(a[i][j]!=w);
                tot2+=(a[i][j]!=z);
            }
            if (tot1<tot2) res+=tot1,o[i]=1; else res+=tot2,o[i]=0;
        }
        if (res<ans){
            ans=res; tp=1;
            for (int i=0;i<n;i++) d[i]=o[i];
            dx=x; dy=y; dz=z; dw=w;
        }
    }
    for (int x=0;x<4;x++) for (int y=x+1;y<4;y++){
        int z,w,res,tot1,tot2; res=0;
        for (int i=0;i<4;i++) if (i!=x&&i!=y) {z=i; break;}
        for (int i=0;i<4;i++) if (i!=x&&i!=y&&i!=z) {w=i; break;}
        for (int i=0;i<m;i+=2){
            tot1=tot2=0;
            for (int j=0;j<n;j+=2){
                tot1+=(a[j][i]!=x);
                tot2+=(a[j][i]!=y);
            }
            for (int j=1;j<n;j+=2){
                tot1+=(a[j][i]!=y);
                tot2+=(a[j][i]!=x);
            }
            if (tot1<tot2) res+=tot1,o[i]=1; else res+=tot2,o[i]=0;
        }
        for (int i=1;i<m;i+=2){
            tot1=tot2=0;
            for (int j=0;j<n;j+=2){
                tot1+=(a[j][i]!=z);
                tot2+=(a[j][i]!=w);
            }
            for (int j=1;j<n;j+=2){
                tot1+=(a[j][i]!=w);
                tot2+=(a[j][i]!=z);
            }
            if (tot1<tot2) res+=tot1,o[i]=1; else res+=tot2,o[i]=0;
        }
        if (res<ans){
            ans=res; tp=2;
            for (int i=0;i<m;i++) d[i]=o[i];
            dx=x; dy=y; dz=z; dw=w;
        }
    }
    if (tp==1){
        for (int i=0;i<n;i+=2){
            if (d[i]){
                for (int j=0;j<m;j+=2) a[i][j]=dx;
                for (int j=1;j<m;j+=2) a[i][j]=dy;
            } else {
                for (int j=0;j<m;j+=2) a[i][j]=dy;
                for (int j=1;j<m;j+=2) a[i][j]=dx;
            }
        }
        for (int i=1;i<n;i+=2){
            if (d[i]){
                for (int j=0;j<m;j+=2) a[i][j]=dz;
                for (int j=1;j<m;j+=2) a[i][j]=dw;
            } else {
                for (int j=0;j<m;j+=2) a[i][j]=dw;
                for (int j=1;j<m;j+=2) a[i][j]=dz;
            }
        }
    } else {
        for (int i=0;i<m;i+=2){
            if (d[i]){
                for (int j=0;j<n;j+=2) a[j][i]=dx;
                for (int j=1;j<n;j+=2) a[j][i]=dy;
            } else {
                for (int j=0;j<n;j+=2) a[j][i]=dy;
                for (int j=1;j<n;j+=2) a[j][i]=dx;
            }
        }
        for (int i=1;i<m;i+=2){
            if (d[i]){
                for (int j=0;j<n;j+=2) a[j][i]=dz;
                for (int j=1;j<n;j+=2) a[j][i]=dw;
            } else {
                for (int j=0;j<n;j+=2) a[j][i]=dw;
                for (int j=1;j<n;j+=2) a[j][i]=dz;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]==0) printf("A");
            if (a[i][j]==1) printf("T");
            if (a[i][j]==2) printf("G");
            if (a[i][j]==3) printf("C");
        }
        puts("");
    }
}