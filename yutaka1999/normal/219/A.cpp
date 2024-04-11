#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;
char s[1002];
char ab[27];
char ans[1002];

int main()
{
    int k;
    
    string in;
    scanf("%d%s",&k,&s);
    
    for(char c='a';c<='z';c++) ab[c-'a']=c;
    
    in=s;
    
    int si=in.size();
    int abc[27],abd[27];
    fill(abc,abc+27,0);
    fill(abd,abd+27,0);
    
    for(int i=0;i<si;i++)
    {
        abc[in[i]-'a']++;
    }
    
    for(int i=0;i<26;i++)
    {
        if(abc[i]%k!=0)
        {
            printf("%d\n",-1);
            return 0;
        }
        else abd[i]=abc[i]/k;
    }
    
    ostringstream oss;
    
    while(1)
    {
        bool up=false;
        for(int i=0;i<26;i++)
        {
            if(abc[i]!=0)
            {
                abc[i]-=abd[i];
                for(int j=0;j<abd[i];j++) oss<<ab[i];
                up=true;
            }
        }
        if(!up) break;
    }
    string p=oss.str();
    int sz=p.size();
    
    for(int i=0;i<sz;i++) ans[i]=p[i];
    
    printf("%s\n",ans);
    return 0;
}