module Main where

list :: [Integer]
list = [-3, 1, 0, -5, -4, 2]

countLessThanZero :: [Integer] -> Integer
countLessThanZero [] = 0
countLessThanZero (x:l)
 | x < 0 = countLessThanZero l + 1
 | otherwise = countLessThanZero l

main = do print(countLessThanZero list)