#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
const int N=1000000,P=31;
const int Mod=1e9+7;
char c[1010000];
int n,m,T,len,p[1010000],h[1010000],s[1010000],mx,ansl,ansr,pos,l,r,mid,mor;
IN geta(int x,int y){
	re res=0,val;res=h[y];
	val=(ll)p[y-x+1]*h[x-1]%Mod;val=Mod-val;
	(res+=val)>=Mod?res-=Mod:0;
	return res;
}
IN getb(int x,int y){
	re res=0,val;res=s[x];
	val=(ll)p[y-x+1]*s[y+1]%Mod;val=Mod-val;
	(res+=val)>=Mod?res-=Mod:0;
	return res;
}
int main(){
	p[0]=1;
	F(i,1,N)p[i]=(ll)p[i-1]*P%Mod;
	read(T);
	while(T--){
		cin>>c+1;n=strlen(c+1);len=-1;
		F(i,1,n>>1){
			if(c[i]!=c[n-i+1]){
				len=i-1;break;
			}
		}
		if(len==-1){
			puts(c+1);continue;
		}
		h[0]=0;
		F(i,1,n)h[i]=(ll)h[i-1]*P%Mod,(h[i]+=(c[i]-'a'+1))>=Mod?h[i]-=Mod:0;
		s[n+1]=0;
		FOR(i,n,1)s[i]=(ll)s[i+1]*P%Mod,(s[i]+=(c[i]-'a'+1))>=Mod?s[i]-=Mod:0;
		mx=1;ansl=1;ansr=0;
		F(i,1,n>>1){
			l=1;r=i;
			if(c[i+1]!=c[i])mor=0;
			else{
				while(l!=r){
					mid=(l+r+1)>>1;
					if(geta(i-mid+1,i)==getb(i+1,i+mid))l=mid;
					else r=mid-1;
				}	
				mor=l;
			}
			if(mor+len>=i&&(i<<1)>mx){
				//cout<<"!";
				mx=i<<1;ansl=i+mor;ansr=i-mor;
			}
			if(i==1)continue;
			l=1;r=i-1;
			if(c[i+1]!=c[i-1])mor=0;
			else {
				while(l!=r){
					mid=(l+r+1)>>1;
					if(geta(i-mid,i-1)==getb(i+1,i+mid))l=mid;
					else r=mid-1;
				}
				mor=l;
			}
			if(mor+len>=i-1&&(i<<1)-1>mx){//cout<<"@";
				mx=(i<<1)-1;ansl=i+mor;ansr=i-1-mor;
			}
		}
		F(i,1,n>>1){
			l=1;r=i;
			if(c[n-i]!=c[n-i+1])mor=0;
			else {
				while(l!=r){
					mid=(l+r+1)>>1;
					//cout<<geta(n-i-mid+1,n-i)<<" "<<getb(n-i+1,n-i+mid)<<endl;
					if(geta(n-i-mid+1,n-i)==getb(n-i+1,n-i+mid))l=mid;
					else r=mid-1;
				}
				mor=l;
			}
			//cout<<mor<<endl;
			if(mor+len>=i&&(i<<1)>mx){//cout<<"#";
				mx=i<<1;ansr=i+mor;ansl=i-mor;
			}
			if(i==1)continue;
			l=1;r=i-1;
			if(c[n-i]!=c[n-i+2])mor=0;
			else{
				while(l!=r){
					mid=(l+r+1)>>1;
					if(geta(n-i-mid+1,n-i)==getb(n-i+2,n-i+mid+1))l=mid;
					else r=mid-1;
				}
				mor=l;
			}
			if(mor+len>=i-1&&(i<<1)-1>mx){//cout<<"$";
				mx=(i<<1)-1;ansr=i+mor;ansl=i-mor-1;
			}
		}
		//cout<<ansl<<" "<<ansr<<endl;
		F(i,1,ansl)cout<<c[i];
		F(i,n-ansr+1,n)cout<<c[i];
		cout<<endl;
	}
	return 0;
}