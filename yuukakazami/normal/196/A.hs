f s 
	| null s=[]
	| null y=[x]
	| x >= (head y)=x:y
	| True = y
	where (x,y) = (head s,f $ tail s) 
main = do 
	s <- getLine
	putStrLn $ f s