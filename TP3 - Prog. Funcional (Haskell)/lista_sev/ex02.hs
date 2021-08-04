module Main where

list :: [Integer]
list = [3, 1, 0, 5, 4, 2]

maxInteger :: [Integer] -> Integer
maxInteger [] = 0
maxInteger (x:l)
 | x > maxInteger l = x
 | otherwise = maxInteger l

main = do print(maxInteger list)