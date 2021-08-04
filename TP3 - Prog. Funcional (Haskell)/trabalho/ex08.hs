module Main where

list1 :: [Integer]
list1 = [0, 1, 2, 3, 4, 5, 6]

list2 :: [Integer]
list2 = [7, 8, 9, 10, 11, 12, 13]

areDifferent :: [Integer] -> [Integer] -> Bool
areDifferent x [] = True
areDifferent [] y = True
areDifferent x (y:l)
 | equalsAnyOnArray y x = False
 | otherwise = areDifferent x l

equalsAnyOnArray :: Integer -> [Integer] -> Bool
equalsAnyOnArray x [] = False
equalsAnyOnArray x (y:l)
 | x == y = True
 | otherwise = equalsAnyOnArray x l

main = do print(areDifferent list1 list2)