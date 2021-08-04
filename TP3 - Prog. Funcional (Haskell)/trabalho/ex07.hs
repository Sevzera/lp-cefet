module Main where

list :: [Integer]
list = [0, 1, 2, 3, 4, 5, 6]

areAllDifferent :: [Integer] -> Bool
areAllDifferent [] = True
areAllDifferent (x:y)
 | equalsAnyOnArray x y = False
 | otherwise = areAllDifferent y

equalsAnyOnArray :: Integer -> [Integer] -> Bool
equalsAnyOnArray x [] = False
equalsAnyOnArray x (y:l)
 | x == y = True
 | otherwise = equalsAnyOnArray x l

main = do print(areAllDifferent list)