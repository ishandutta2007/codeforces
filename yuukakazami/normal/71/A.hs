work :: Integer -> IO()
work 0 = return ()
work n = do
	str <- getLine
	putStrLn $ f str
	work $ n-1

f :: String -> String
f s
	| len <= 10 = s
	| otherwise = [head s] ++ (show $ len - 2) ++ [last s]
	where len = length s

main = do
	n <- readLn
	work n