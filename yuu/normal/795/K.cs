using System;
class Program{
    static void Main(){
        int n = Convert.ToInt32(Console.ReadLine());
        string s = Console.ReadLine();
		s=s+'$';
		for(int i=0; i<n; i++){
			if((s[i]=='a'||s[i]=='u'||s[i]=='i'||s[i]=='e'||s[i]=='o'||s[i]=='y')){
				int j=i;
				while(s[j+1]==s[i])
					j++;
				if(j-i+1!=2)
					Console.Write(s[i]);
				else if(s[i]!='e'&&s[i]!='o')
					Console.Write(s[i]);
				else{
					Console.Write(s[i]);
					Console.Write(s[i]);
				}
				i=j;
			}
			else
				Console.Write(s[i]);
		}
    }
}