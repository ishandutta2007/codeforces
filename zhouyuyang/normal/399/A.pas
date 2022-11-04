var
  i,j,k,l,m,n,p:longint;
begin
  read(n,p,k);
  if p<=k+1 then
    for i:=1 to p-1 do
      write(i,' ')
    else
      begin
        write('<< ');
        for i:=k downto 1 do
          write(p-i,' ');
      end;
  write('(',p,') ');
  if p+k>=n then
    for i:=p+1 to n do
      write(i,' ')
    else
      begin
        for i:=1 to k do
          write(i+p,' ');
        write('>>');
      end;
  readln;
end.