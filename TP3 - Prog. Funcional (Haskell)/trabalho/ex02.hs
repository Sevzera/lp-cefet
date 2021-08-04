module Main where
list :: [Integer]
list = [0, 1, 2, 3, 4, 5]

oddSum :: [Integer] -> Integer
oddSum [] = 0
oddSum (x:y)
 | x `mod` 2 == 0 = oddSum y
 | otherwise = x + oddSum y

main = do print(oddSum list)