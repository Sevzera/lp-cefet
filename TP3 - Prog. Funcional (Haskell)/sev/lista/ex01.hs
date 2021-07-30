module Main where
list :: [Integer]
list = [0, 2..]

foundInteger :: Integer -> [Integer] -> Bool
foundInteger x [] = False
foundInteger x (y:l)
    | x == y = True
    | otherwise = foundInteger x l

main = do print(foundInteger 500 list)