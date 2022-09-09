#include<bits/stdc++.h>
using namespace std;
int T,n,i,j,k;
char c[55];
inline void ask(string s){
	cout<<"? "<<s<<endl;
	int k,x;
	cin>>k;for(;k--;){cin>>x;for(int i=0;i<s.size();++i)c[x+i]=s[i];}
}
bool E(){for(char z:c)if(z)return 0;return 1;}
inline void sett(string s){memcpy(c+1,&s[0],n);}
char fir,las;int firr,lass;
inline void work1(){
	string s;
	for(i=1;i<=lass;++i)s.push_back(c[i]);
	for(i=2;i<firr;++i)s[i-1]='C';s[0]='H';
	ask(s);
	if(!c[1]){
		s[0]='O';
		ask(s);
		if(!c[1])for(i=1;i<firr;++i)c[i]='C';
	}
	fir=c[1];firr=1;
}
inline void work2(){
	string s;
	for(i=firr;i<=n;++i)s.push_back(c[i]);
	for(i=lass+1;i<=n;++i)s[i-firr]='C';
	ask(s);
	if(!c[n])for(i=lass+1;i<=n;++i)c[i]=las;
	las=c[n];lass=n;
}
inline void F(){cout<<"! "<<c+1<<endl;cin>>n;}
int main(){
	for(cin>>T;T--;){
		if(!(cin>>n))break;
		memset(c,0,sizeof c);ask("CH");ask("CO");ask("HO");ask("OH");
		if(n==4){
			if(E()){
				ask("HHH");ask("CCC");ask("OOO");
				if(E()){
					ask("HHCC");
					if(E())sett("OOCC");
				}else if(!c[4]){
					c[4]='C';
				}else if(!c[1]){
					ask("HCCC");
					if(!c[1])sett("OCCC");
				}
				F();continue;
			}else if((!c[3] && !c[4]) || (!c[1] && !c[2]))ask("HHC"),ask("OOC");
		}else{
			ask("HHC"),ask("OOC");
			if(E()){
				ask("H"+string(n-1,'C'));
				ask("O"+string(n-1,'C'));
				ask(string(n,'H'));
				ask(string(n,'O'));
				if(E())sett(string(n,'C'));
				F();continue;
			}
		}
		for(i=1;i<n;++i)if(c[i]){
			for(j=i+1;j<=n && !c[j];++j);if(j>n)continue;
			if(c[i]==c[j])for(k=i+1;k<j;++k)c[k]=c[i];
				else for(k=i+1;k<j;++k)c[k]='C';
		}
		for(i=1;!c[i];++i);fir=c[firr=i];for(i=n;!c[i];--i);las=c[lass=i];
		if(fir!='C')for(i=1;!c[i];++i)c[i]=fir;
		if(las=='C')for(i=n;!c[i];--i)c[i]=las;
		if(!c[1] && (c[n] || lass>n-firr+1))work1();
		if(!c[n])work2();
		if(!c[1])work1();
		F();
	}
}