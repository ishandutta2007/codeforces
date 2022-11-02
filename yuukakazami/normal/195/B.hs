import Data.List (sort)

pt :: (Show a) => [a] -> IO()
pt [] = return ()
pt (x:xs) = do
	putStrLn $ show x
	pt xs

main = do
	str <- getLine
	let [n,m] = [read x::Int | x <- words str]
	let lst = [ (abs $ m+1-2*i,i) | i<-[1..m]]
	let srt = sort lst
	let ret = take n $ cycle $ map snd srt
	pt ret