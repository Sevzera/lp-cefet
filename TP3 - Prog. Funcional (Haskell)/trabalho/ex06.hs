module Main where

toBinary :: Integer -> [Integer]
toBinary x
 | x == 1 = [1]
 | x == 0 = [0]
 | x `mod` 2 == 0 = (toBinary (x `div` 2)) ++ [0]
 | otherwise = (toBinary (x `div` 2)) ++ [1]

main = do print(toBinary 0)