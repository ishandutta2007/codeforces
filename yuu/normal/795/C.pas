{$MODE OBJFPC}
var n, i: integer;
begin
	read(n);
	if(n mod 2 = 0) then
	begin
		n:=n div 2;
		for i:=1 to n do
			write(1);
	end
	else
	begin
		write(7);
		n:=(n-3) div 2;
		for i:=1 to n do
			write(1);
	end;
end.