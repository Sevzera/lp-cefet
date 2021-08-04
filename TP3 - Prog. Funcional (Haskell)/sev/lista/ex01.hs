module Main where
list :: [Integer]
list = [0, 2, 4, 6, 8, 10]

foundInteger :: Integer -> [Integer] -> Bool
foundInteger x [] = False
foundInteger x (y:l)
    | x == y = True
    | otherwise = foundInteger x l

main = do print(foundInteger 1 list)