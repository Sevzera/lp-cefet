module Main where

prime :: Integer -> Bool
prime x 
 | x == 1 = False
 | otherwise primeQ x (x - 1)

primeQ :: Integer -> Integer -> Bool
primeQ x y
 | y == 1 = True
 | x `mod` y == 0 = False
 | otherwise = primeQ x (y - 1)

main = do print(prime 5)