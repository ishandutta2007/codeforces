#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        string p;
        cin>>p;
        
        string str[10];
        
        char bef=p[0];
        int poi=0;
        
        for(int j=0;j<p.size();j++)
        {
            if(p[j]==':'&&j!=0)
            {
                if(bef==':')
                {
                    str[poi]="::";
                    if(j!=p.size()-1) poi++;
                }
                else
                {
                    poi++;
                }
            }
            else
            {
                str[poi]+=p[j];
            }
            bef=p[j];
        }
        
        for(int j=0;j<8;j++)
        {
            string q=str[j];
            if(q=="") break;
            
            if(q.size()!=4&&q!="::")
            {
                int k=4-q.size();
                string r;
                r="0000";
                
                for(int l=k;l<4;l++)
                {
                    r[l]=q[l-k];
                }
                str[j]=r;
            }
            else if(q=="::")
            {
                int ooo=8-poi;
                string q;
                for(int k=0;k<ooo;k++)
                {
                    string r;
                    r="0000";
                    if(k!=ooo-1) r+=':';
                    q+=r;
                }
                str[j]=q;
            }
        }
        
        for(int i=0;i<10;i++)
        {
            if(str[i]=="") break;
            else
            {
                if(i==0) cout<<str[i];
                else cout<<':'<<str[i];
            }
        }
        cout<<endl;
    }
    return 0;
}