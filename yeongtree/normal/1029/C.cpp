#include <iostream>

using namespace std;

struct seq
{
    int l;
    int r;
    seq(void) {}
    seq(int x,int y) {l=x; r=y;}
    int lgt(void) {return r-l;}
};

seq itsc(seq x,seq y)
{
    if(x.l>y.r||x.r<y.l) {seq s(0,0); return s;}
    seq s((x.l>y.l)?x.l:y.l , (x.r<y.r)?x.r:y.r); return s;
}

seq f(seq* x,seq* y,int n,int left,int right)
{
    if(left+1==right) return x[n]=y[left];
    int mid=(left+right)/2;
    return x[n]=itsc(f(x,y,2*n+1,left,mid),f(x,y,2*n+2,mid,right));
}

seq fnd(seq* x,int n,int left,int right,int _left,int _right)
{
    if(left>=_right||_left>=right) {seq s(0,1000000001); return s;}
    if(left<=_left&&right>=_right) return x[n];
    int mid=(_left+_right)/2;
    return itsc(fnd(x,2*n+1,left,right,_left,mid),fnd(x,2*n+2,left,right,mid,_right));
}

int main()
{
    int n; cin>>n;
    seq* s=new seq[n]; for(int i=0;i<n;i++) cin>>s[i].l>>s[i].r;
    int e=1; while(e<n) {e*=2;} e*=2;
    seq* riq=new seq[e]; f(riq,s,0,0,n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int l;
        if(i==0) l=fnd(riq,0,1,n,0,n).lgt();
        else if(i==n-1) l=fnd(riq,0,0,n-1,0,n).lgt();
        else l=itsc(fnd(riq,0,0,i,0,n),fnd(riq,0,i+1,n,0,n)).lgt();
        if(l>ans) ans=l;
    }
    cout<<ans;
    return 0;
}