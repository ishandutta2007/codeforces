#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define IN inline int
char s[300],t[300],p[300];
int sum,tp,ps,T,buc[100],m;
IN Strlen(char *x){
	for(re i=1;;i++){
		if(x[i]=='%')return i-1;
	}
}
int main(){
	cin>>T;
	while(T--){
		F(i,1,sum){
			s[i]='\0';
		}
		F(i,1,tp){
			t[i]='\0';
		}
		F(i,1,ps){
			p[i]='\0';
		}
		cin>>s+1>>t+1>>p+1;
		sum=strlen(s+1);
		tp=strlen(t+1);
		ps=strlen(p+1);
		memset(buc,0,sizeof(buc));
		m=1;
		F(i,1,sum){
			if(m>tp){
				m=-1;
				break;
			}
			while(t[m]!=s[i]&&m<=tp){
				m++;
				if(m>tp){
					m=-1;
					break;
				}
			}
			if(m==-1)break;
			m++;
		}
		if(m==-1){
			printf("NO\n");
			continue;
		}
		F(i,1,sum){
			buc[s[i]-'a'+1]++;
		}
		F(i,1,ps){
			buc[p[i]-'a'+1]++;
		}
		m=0;
		F(i,1,tp){
			buc[t[i]-'a'+1]--;
			if(buc[t[i]-'a'+1]<0){
				m=1;
				break;
			}
		}
		if(m)printf("NO\n");
		else printf("YES\n");
	}
    return 0;
}