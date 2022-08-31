#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
int ret[100002];

int main()
{
    vector <int> vec;
    
    int n,k;
    scanf("%d %d",&n,&k);
    
    int num;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        
        if(i==0)
        {
            num=a;
            vec.push_back(a);
        }
        else
        {
            if(num==a) continue;
            else
            {
                vec.push_back(a);
                num=a;
            }
        }
    }
    
    for(int i=0;i<vec.size();i++)
    {
        if(i==vec.size()-1) ret[vec[i]]++;
        else if(vec[i-1]==vec[i+1]) ret[vec[i]]+=2;
        else ret[vec[i]]++;
    }
    
    int max=0;
    int ans;
    for(int i=1;i<=n;i++)
    {
        if(max<ret[i])
        {
            max=ret[i];
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}