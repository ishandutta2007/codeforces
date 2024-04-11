main = do
	str <- getLine
	let [a,b,c] = [read x::Integer | x <- words str]
	putStrLn $ show $ head $ [x|x <- [1..],b*(x+c) >= a*c]