type
  arr=record
  root,now:string;
end;
var
  n,i,j,num,p1:longint;
  p:boolean; s1:string;
  old,new:string;
  s:array[1..10000] of arr;
begin
  readln(n);
  for i:=1 to n do
    begin
	  readln(s1); p1:=pos(' ',s1);
	  old:=copy(s1,1,p1-1); delete(s1,1,p1);
	  new:=s1; p:=true;
	  for j:=1 to num do
	    if s[j].now=old then
		  begin
		    s[j].now:=new;
			p:=false; break;
		  end;
	  if p then
	    begin
		  inc(num);
		  s[num].root:=old;
		  s[num].now:=new;
		end;
	end;
  writeln(num);
  for i:=1 to num do
    writeln(s[i].root,' ',s[i].now);
end.