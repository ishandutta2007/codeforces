#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#define all(x) x.begin(),x.end()
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10;
void Z_function(string s,vector<int> &v){
	int len=s.size();
	v.resize(len); v[0]=len;
	int l=-1,r=-1;
	F(i,1,SZ(s)){
		if (i<=r) v[i]=min(r-i+1,v[i-l]);
		while (i+v[i]<len && s[i+v[i]]==s[v[i]]) v[i]++;
		if (i+v[i]-1>r){
			r=i+v[i]-1;
			l=i;
		}
	}
}
string a,b,s;
int n,m;
vector<int> la,lb;
int ta[M],tb[M],ia[M],ib[M];
bool cpa(int x,int y){
	return ta[x]<ta[y];
}
bool cpb(int x,int y){
	return tb[x]<tb[y];
}
struct BIT{
	#define lowbit(x) (x&-x)
	int d[M];
	void add(int x){
		for (;x<=n;x+=lowbit(x)) d[x]++;
	}
	void del(int x){
		for (;x<=n;x+=lowbit(x)) d[x]--;
	}
	int qry(int x){
		int ret=0;
		for (;x;x-=lowbit(x)) ret+=d[x];
		return ret;
	}
	int sum(int l,int r){
		if (r>n) r=n; if (l<1) l=1;
		return qry(r)-qry(l-1);
	}
	void out(){
		cout<<"OUT::\n";
		F(i,1,n) cout<<sum(i,i)<<" "; cout<<"\n";
	}
}ba,bb;

int main(){
	n=read(); m=read();
	cin>>a>>b>>s;
	string ob=b,os=s; 
	reverse(all(ob)); reverse(all(os));
	Z_function(s+"#"+a,la);
	Z_function(os+"#"+ob,lb);
	F(i,m+1,SZ(la)){
		ta[i-m]=la[i];
		tb[i-m]=lb[i];
//		cout<<ta[i-m]<<" "<<tb[i-m]<<"   g\n";
	}
	reverse(tb+1,tb+n+1);
	F(i,1,n) ia[i]=ib[i]=i;
	sort(ia+1,ia+n+1,cpa);
	sort(ib+1,ib+n+1,cpb);
	LL tmp=0,ans=0;
	F(i,1,n) ba.add(i);
	for (int l1=1,r1=m-1,i=1,j=n;l1<=m-1;l1++,r1--){
		while (i<=n && ta[ia[i]]<l1) {
			tmp-=bb.sum(ia[i],ia[i]+m-2);
			ba.del(ia[i]);
			i++;
		}
		while (j && tb[ib[j]]>=r1){
			tmp+=ba.sum(ib[j]-m+2,ib[j]);
			bb.add(ib[j]);
			j--;
		}
//		cout<<i<<" "<<j<<" "<<l1<<" "<<r1<<" "<<ans<<"   cnm\n";
//		ba.out(); bb.out();
		ans+=tmp;
	}
	cout<<ans<<"\n";
	return 0;
}