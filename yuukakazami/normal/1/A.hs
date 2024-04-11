main = do
	str <- getLine
	let xs = words str
	let [n,m,a] = [read x::Integer|x<-xs]
	putStrLn $ show $ ((n-1) `div` a + 1)*((m-1) `div` a +1)