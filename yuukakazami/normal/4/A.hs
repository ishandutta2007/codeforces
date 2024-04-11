main = do
	str <- getLine	
	let a = read str :: Integer
	putStrLn $ if (a > 2 && even a) then "YES" else "NO"