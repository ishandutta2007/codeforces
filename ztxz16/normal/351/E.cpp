#include <cstdio>
#include <algorithm>
using namespace std;
const int NMax=2030;
int N,nn;
int A[NMax],B[NMax],C[NMax];;
struct edge{
    int e,f;
    edge * next,*opt;
}epool[NMax*NMax*3],*etop,*E[NMax];
void addedge(int b,int e,int c){
    edge * p=etop++;
    edge * q=etop++;
    p->e=e;p->f=c;p->next=E[b];p->opt=q;E[b]=p;
    q->e=b;q->f=0;q->next=E[e];q->opt=p;E[e]=q;
}
int level[NMax],Q[NMax];
bool mkLevel(){
    for (int i=0;i<nn;i++)
        level[i]=-1;
    level[Q[0]=0]=0;
    for (int i=0,j=1;i<j;i++){
        int x=Q[i];
        for (edge *p=E[x];p;p=p->next)
            if (p->f && level[p->e]==-1){
                level[Q[j++]=p->e]=level[x]+1;
            }
    }
    return level[nn-1]!=-1;
}
int extend(int a,int r){
    if (a==nn-1)
        return r;
    int t=0;
    for (edge *p=E[a];p && r>t;p=p->next)
        if (p->f && level[p->e]==level[a]+1){
            int v=extend(p->e,min(r-t,p->f));
            t+=v;
            p->f-=v;
            p->opt->f+=v;
        }
    if (t==0)
        level[a]=-1;
    return t;
}
int Dinic(){
    int flow=0;
    while (mkLevel())
        while (int t=extend(0,nn*nn))
            flow+=t;
    return flow;
}
int main()
{
    scanf("%d",&N);
    nn=N+2;
    for (int i=0;i<nn;i++)
        E[i]=NULL;
    etop=epool;
    for (int i=0;i<N;i++){
        scanf("%d",A+i);
        if (A[i]<0)
            A[i]=-A[i];
    }
    for (int i=0;i<N;i++)
        for (int j=i+1;j<N;j++){
            if (A[i]==A[j]){
                if (A[i]!=-A[j])
                    addedge(1+i,1+j,1);
            }else{
                if (A[i]>A[j]){
                    C[i]+=1;
                }else if (A[i]<A[j]){
                    B[j]+=1;
                }
            }
        }
    int ret=0;
    for (int i=0;i<N;i++){
        int t=min(B[i],C[i]);
        ret+=t;
        if (B[i]>t)
            addedge(0,1+i,B[i]-t);
        if (C[i]>t)
            addedge(1+i,nn-1,C[i]-t);
    }
    printf("%d\n",ret);
    return 0;
}