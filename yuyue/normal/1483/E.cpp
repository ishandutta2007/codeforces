#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const LL M=//70368744177664ll;
//99999999999808ll;
0;
//53324285109678ll;
//55230191225896ll;
//35982344283889ll;
//68220205139073ll;
//37212598770764ll;
//42468011125418ll;

//49826134558021ll;
//51869511731411ll;
//59514491944070ll;

//70368744176723ll;

//99999999999190ll;

//70368744178077;
//70368744178556ll;
//70368744177961ll;
//70368744178307ll;
LL P=0;
int Ot=0;
bool ask(LL x){
	cout<<"? "<<x<<endl;
	string ret; Ot++;
	cin>>ret;
	if (M && x<=M || ret=="Lucky!"){
		P+=x;
		return 1;
	}
	P-=x;
	assert(P>=0);
	return 0;
}
const LL O=1e14;
LL f[999][999];
void work(){
	P=1; Ot=0;
	LL L=0,R=1;
	while (1){
		if (ask(R)) L=R,R=min(R*2,O);
		else{
			break;
		}
		if (L==R){
			cout<<"! "<<L<<endl;
			return ;
		}
//		cout<<R<<"   gg\n";
	}
	R--; LL ret=L; L++;
	int q=50,c=0;
//	double ratio=2.85555555;
	while (L<=R){
		while (f[q-1][c]+L>R) q--;
		if (!c){
			ask(L-1);
			c++;
			continue;
		}
		LL mid=f[q-1][c-1]+L;
//		cout<<L<<" "<<R<<" "<<mid<<"\n";
		while (P<mid) ask(L-1);
		q--;
		if (ask(mid)) L=mid+1,ret=mid,c++;
		else R=mid-1,c--;
	}
//	cerr<<Ot<<"\n";
	cout<<"! "<<ret<<endl;
}
void init(){
	F(i,1,60){
		f[i][0]=f[i-1][1];
		F(j,1,60){
			f[i][j]=f[i-1][j-1]+f[i-1][j+1]+1;
		}
	}
}
int main(){
	init();
//	cerr<<f[49][0]<<"\n";
	int T=read();
	while (T--) work();
	return 0; 
}