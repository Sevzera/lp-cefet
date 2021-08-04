module Main where

pow :: Integer -> Integer -> Integer
pow x y
 | y == 1 = x
 | y == 0 = 1
 | otherwise = x * pow x (y - 1)

main = do print(pow 5 2)