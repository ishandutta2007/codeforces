import Data.List
main=do
	a<-getLine
	t<-fmap (map read.words) getLine
	print $ sum t / genericLength t