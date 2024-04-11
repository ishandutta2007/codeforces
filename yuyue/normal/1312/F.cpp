#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
#define vet vector<vector<int> > 
map<vet,int> mp; 
vet sg;
LL a[M];
int x,y,z,n; 
int mex(int a,int b,int c){
	int k=0,ret=0; k|=(1<<a); k|=(1<<b); k|=(1<<c);
	while (k&1) ret++,k>>=1;
	return ret;
}
void con(){
	int o=SZ(sg)+1;
	vector<int> tmp(3,0);
	tmp[0]=mex(sg[max(o-x,0)][0],sg[max(o-y,0)][1],sg[max(o-z,0)][2]);
	tmp[1]=mex(sg[max(o-x,0)][0],sg[max(o-z,0)][2],4);
	tmp[2]=mex(sg[max(o-x,0)][0],sg[max(o-y,0)][1],4);
	sg.pb(tmp);
}
int pre,len;
int ral(LL x){
	return (x<=pre ? x : (x-pre)%len+pre); 
}
int s[10]; 
int main(){
	int T=read();
	while (T--){
		n=read(); x=read(); y=read(); z=read();
		F(i,1,n) a[i]=read();
		mp.clear(); sg.clear();	
		sg.pb({0,0,0});
		F(i,1,5) con();
				
		while (1){
			vet tmp(sg.end()-5,sg.end()); 
			if (mp.count(tmp)){
				pre=mp[tmp]; len=SZ(sg)-4-pre; 
				break; 
			}
			mp[tmp]=SZ(sg)-4;
			con(); 
		}		

		int sumsg=0; ms(s,0); 
		F(i,1,n){	
//		cout<<"fi\n";

			LL val0=ral(max(a[i]-x,0ll)),val1=ral(max(a[i]-y,0ll)),val2=ral(max(a[i]-z,0ll));
			int now=sg[ral(a[i])][0],X=sg[val0][0],Y=sg[val1][1],Z=sg[val2][2];
			sumsg^=now; 
			s[X^now]++; s[Y^now]++; s[Z^now]++;
		}
		cout<<s[sumsg]<<"\n"; 
	}
	return 0;
}