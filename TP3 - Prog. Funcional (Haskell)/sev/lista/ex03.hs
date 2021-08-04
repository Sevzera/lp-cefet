module Main where
list :: [Integer]
list = [3, 1, 0, 5, 4, 2]

reverseList :: [Integer] -> [Integer]
reverseList [] = []
reverseList (x:l) = reverseList(l)++[x]

main = do print(reverseList list)