var
  b:array[0..1000] of boolean;
  l:array[0..300,0..300] of longint;
  i,j,n,m,num,max,t1,t2,p:longint;
  nam:array[0..300] of string;
  s1,s2,s,na1,na2:string;
  procedure dfs(x:longint);
    var
	  i:longint;
	begin
	  b[x]:=false;
	  for i:=1 to l[x,0] do
	    if b[l[x,i]] then dfs(l[x,i]);
	end;
  function pd(s1,s2:string):boolean;
    var s3,s4:string; i:longint;
	begin
          s3:=''; s4:='';
	  if (length(s1)<>length(s2)) then exit(false);
	  for i:=1 to length(s1) do
	  if (s1[i]>='a')or(('0'<=s1[i])and('9'>=s1[i])) then s3:=s3+s1[i]
          else s3:=s3+chr(ord(s1[i])-ord('A')+ord('a'));
	  for i:=1 to length(s1) do
	  if (s2[i]>='a')or(('0'<=s2[i])and('9'>=s2[i])) then s4:=s4+s2[i]
          else s4:=s4+chr(ord(s2[i])-ord('A')+ord('a'));
	  if (s3=s4) then exit(true) else exit(false);
	end;
begin
  readln(n);
  for i:=1 to n do
    begin
	  readln(s1); p:=pos(' ',s1); na1:=copy(s1,1,p-1);
	  delete(s1,1,p); p:=pos(' ',s1); delete(s1,1,p);
	  na2:=s1; t1:=0; t2:=0;
	  for j:=1 to num do
	  if pd(nam[j],na1) then begin t1:=j; break; end;
	  if (t1=0) then begin inc(num); t1:=num; nam[num]:=na1; end;
	  for j:=1 to num do
	  if pd(nam[j],na2) then begin t2:=j; break; end;
	  if (t2=0) then begin inc(num); t2:=num; nam[num]:=na2; end;
	  inc(l[t1,0]); l[t1,l[t1,0]]:=t2;
	end;
  max:=0;
  for i:=1 to num do
    begin
	  fillchar(b,sizeof(b),true);
	  m:=0; dfs(i);
	  for j:=1 to num do if b[j]=false then inc(m);
	  if m>max then max:=m;
	end;
  writeln(max);
end.