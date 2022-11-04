#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1<<18,mod=1009;
double PI=acos(-1.0);
int n,m,k,tot[N];
struct C{
	double r,i;
	C(){}
	C(double a,double b){r=a,i=b;}
	C operator + (C x){return C(r+x.r,i+x.i);}
	C operator - (C x){return C(r-x.r,i-x.i);}
	C operator * (C x){return C(r*x.r-i*x.i,r*x.i+i*x.r);}
}w[N],A[N],B[N];
int R[N];
vector <int> colors[N<<1];
struct cmp{
	bool operator ()(int a,int b){
		return colors[a].size()>colors[b].size();
	}
};
priority_queue <int,vector<int>,cmp> heap;
void FFT(C a[],int n){
	for (int i=0;i<n;i++)
		if (i<R[i])
			swap(a[i],a[R[i]]);
	for (int t=n>>1,d=1;d<n;d<<=1,t>>=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				C tmp=w[t*j]*a[i+j+d];
				a[i+j+d]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
}
void FFT_times(vector <int> &a,vector <int> &b,vector <int> &c){
	int n,d;
	for (int i=0;i<a.size();i++)
		A[i]=C(a[i],0);
	for (int i=0;i<b.size();i++)
		B[i]=C(b[i],0);
	for (n=1,d=0;n<a.size()+b.size()-1;n<<=1,d++);
	for (int i=0;i<n;i++){
		R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
		w[i]=C(cos(2*PI*i/n),sin(2*PI*i/n));
	}
	for (int i=a.size();i<n;i++)
		A[i]=C(0,0);
	for (int i=b.size();i<n;i++)
		B[i]=C(0,0);
	FFT(A,n),FFT(B,n);
	for (int i=0;i<n;i++)
		A[i]=A[i]*B[i],w[i].i*=-1.0;
	FFT(A,n);
	c.clear();
	for (int i=0;i<=a.size()+b.size()-2;i++)
		c.push_back(((LL)(A[i].r/n+0.5))%mod);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1,x;i<=n;i++)
		scanf("%d",&x),tot[x]++;
	while (!heap.empty())
		heap.pop();
	int size=0;
	for (int i=1;i<=m;i++){
		if (tot[i]==0)
			continue;
		colors[++size].clear();
		for (int j=0;j<=tot[i];j++)
			colors[size].push_back(1);
		heap.push(size);
	}
	while (heap.size()>=2){
		int x=heap.top();
		heap.pop();
		int y=heap.top();
		heap.pop();
		FFT_times(colors[x],colors[y],colors[++size]);
		colors[x].clear(),colors[y].clear();
		heap.push(size);
	}
	printf("%d",colors[size][k]);
	return 0;
}