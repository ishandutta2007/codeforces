#include <stdio.h>

long long a, z;
int p, i, j, P[78777];

int C(long long x){
    for (j=0; ;){
        z=P[j++];
        if((z*z)>x) return 1;
        if(!(x%z)) return 0;
    }
}

inline int F(int i,long long a){
    if(a==1) return 1;
    long long y=P[i];
    if((y+1)>a) return 0;
    if(((y*y)+1)>a) return C(--a);
    int res = F(i+1, a);
    for(; ;){
        if (++y>a) return res;
        if (!(a%y)) res+=F(i+1,a/y);
        y=(y-1)*P[i];
    }
}

int main(){
    P[p++] = 2;
    for (i=3;i<1000010;i+=2) P[C(i)?p++:p] = i;
    scanf("%I64d",&a);
    printf("%d\n",F(0,a));
}