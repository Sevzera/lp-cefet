module Main where

perfect :: Integer -> Bool
perfect x = equals x (sumOfDivisors x (x - 1))

sumOfDivisors :: Integer -> Integer -> Integer
sumOfDivisors x y
 | y == 1 = 1
 | x `mod` y == 0 = y + sumOfDivisors x (y - 1)
 | otherwise = sumOfDivisors x (y - 1)

equals :: Integer -> Integer -> Bool
equals x y
 | x == y = True
 | otherwise = False

main = do print(perfect 6)