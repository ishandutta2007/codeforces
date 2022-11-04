#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int mo=32768;
int ans,v,f[mo+5],num,p,l;
string s[105],tmp;
int exp();
int getnum(){
	if (tmp[l]=='n') return l++,v;
	if (tmp[l]=='f'){
		l+=2;
		int ans=f[exp()];
		return l++,ans;
	}
	int ans=0;
	for (;tmp[l]>='0'&&tmp[l]<='9';)
		ans=ans*10+tmp[l++]-'0';
	return ans;
}
int getnum2(){
	int ans=getnum();
	for (;tmp[l]=='*'||tmp[l]=='/';){
		char tp=tmp[l++];
		int t1=getnum();
		if (tp=='*')
			ans=ans*t1%mo;
		else ans=ans/t1%mo;
	}
	return ans;
}
int exp(){
	int ans=getnum2();
	for (;tmp[l]=='+'||tmp[l]=='-';){
		char ch=tmp[l++]; int t1=getnum2();
		if (ch=='+') ans=(ans+t1)%mo;
		else ans=(ans+mo-t1)%mo;
	}
	return ans;
}
bool iexp(){
	int p1,p2,tp;
	p1=exp();
	if (tmp[l]=='=') tp=0,l+=2;
	else if (tmp[l]=='<') tp=-1,l++;
	else if (tmp[l]=='>') tp=1,l++;
	p2=exp();
	if (!tp) return p1==p2;
	if (tp==-1) return p1<p2;
	if (tp==1) return p1>p2;
	return 0;
}
int getans(){
	for (int i=0;i<num;i++){
		tmp=s[i];
		if (tmp[0]=='i'){
			l=3;
			if (iexp()){
				l+=7;
				return exp();
			}
		}
		else{
			l=6;
			return exp();
		}
	}
	return 0;
}
char ch;
int main(){
	scanf("%d",&ans); cin>>ch;
	for (;ch!='{';cin>>ch);
	num=0;
	for (;;){
		cin>>ch;
		if (ch=='}') break;
		if (ch==';') ++num;
		else s[num]+=ch;
	}
	int id=-1;
	For(i,0,32767){
		v=i;
		f[i]=getans();
		if (f[i]==ans) id=i;
	}
	printf("%d",id);
}