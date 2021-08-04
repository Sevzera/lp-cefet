module Main where

list :: [Integer]
list = [0, 0, 1, 0, 1, 1, 0]

overwrite :: Integer -> Integer -> [Integer] -> [Integer]
overwrite x y [] = []
overwrite x y (a:b)
 | a == x = (y:(overwrite x y b))
 | otherwise = (a:(overwrite x y b)) 

main = do print(overwrite 0 1 list)