#include<bits/stdc++.h>
using namespace std;
int n,cnt[10],h[10][10];

void pt(int x,int y){
    printf("%c%d ",'a'+x-1,y);
}

void solve(int x,int head){
    h[x][1]=head;
    int pos=8;
    if (x==7) pos--;
    if (pos==head) pos--;
    if (x==8) pos=8;
    h[x][cnt[x]]=pos;
    int p=1;
    for (int i=2;i<cnt[x];i++){
        while (p==head||p==pos) ++p;
        h[x][i]=p++;
    }
    if (x<8) solve(x+1,pos);
}

int main(){
    cin >> n;
    if (n<=8){
        pt(1,1);
        for (int i=10-n;i<=8;i++) pt(1,i);
        pt(8,8);
    } else if (n<=14) {
        pt(1,1);
        for (int i=16-n;i<=8;i++) pt(1,i);
        for (int i=2;i<=7;i++) pt(i,8);
        pt(8,8);
    } else {
        for (int i=0;i<=n;i++) cnt[i%8+1]++;
        solve(1,1);
        for (int i=1;i<=8;i++)
        for (int j=1;j<=cnt[i];j++) pt(i,h[i][j]);
    }
    puts("");
    return 0;
}