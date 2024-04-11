#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Rectango{
    int up,down,left,right;
    Rectango(){}
    Rectango(int u,int d,int l,int r):
    up(u),down(d),left(l),right(r){}
};

void scanf(Rectango& in){
    //scanf("%lld%lld%lld%lld",&in.left,&in.up,&in.right,&in.down);
    cin >> in.left >> in.up >> in.right >> in.down;
}

Rectango uni(Rectango A,Rectango B){
    Rectango ret(max(A.up,B.up)
                ,min(A.down,B.down)
                ,max(A.left,B.left)
                ,min(A.right,B.right));
    return ret;
}

int calc(Rectango A){
    return (A.down - A.up + 1) * (A.right - A.left + 1);
}

int calc(Rectango A,int color){
    if (A.left > A.right || A.up > A.down){
        return 0;
    }
    int foo = calc(A);
    if (foo % 2 == 0){
        return foo / 2;
    }else{
        return foo / 2 + ((A.left + A.up) % 2 == color);
    }
}

#undef int
int main(){
#define  int long long

    int T;
    scanf("%lld",&T);
    while (T--){
        int n,m;
        cin >> n >> m;
        Rectango All(1,m,1,n);
        int w = calc(All,0);
        int b = calc(All,1);
        Rectango A,B;
        scanf(A);
        scanf(B);
        Rectango U = uni(A,B);
        //printf(U);
        w = w + calc(A,1) - calc(U,1) - calc(B,0);
        b = b - calc(A,1) + calc(U,1) + calc(B,0);
        cout << w << ' ' << b << endl;
    }
    return 0;
}