#include <stdio.h>
#define inf 1000000007
int n;
int x, y, u, v;
char c;
int b[9];
char q[9];
char ch[]={'B', 'R'};
void update(){
    if(x==u){
        if(y>v){
            if(y<b[1]){
                b[1]=y;
                q[1]=c;
            }
        }
        else{
            if(y>b[5]){
                b[5]=y;
                q[5]=c;
            }
        }
    }
    else if(y==v){
        if(x>u){
            if(x<b[3]){
                b[3]=x;
                q[3]=c;
            }
        }
        else{
            if(x>b[7]){
                b[7]=x;
                q[7]=c;
            }
        }
    }
    else if(x+y==u+v){
        if(x>u){
            if(x<b[4]){
                b[4]=x;
                q[4]=c;
            }
        }
        else{
            if(x>b[8]){
                b[8]=x;
                q[8]=c;
            }
        }
    }
    else if(x-y==u-v){
        if(x>u){
            if(x<b[2]){
                b[2]=x;
                q[2]=c;
            }
        }
        else{
            if(x>b[6]){
                b[6]=x;
                q[6]=c;
            }
        }
    }
}
int main(){
    //freopen("D.INP", "r", stdin);
    scanf("%i%i%i\n", &n, &u, &v);
    for(int i=1; i<=4; i++)
        b[i]=inf;
    for(int i=5; i<=8; i++)
        b[i]=-inf;
    for(int i=1; i<=n; i++){
        scanf("%c%i%i\n", &c, &x, &y);
        update();
    }
    for(int i=1; i<=8; i++){
        if(q[i]==ch[i%2]||q[i]=='Q'){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}