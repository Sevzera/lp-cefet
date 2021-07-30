list :: [Integer]
list = [0, 1, 2, 3, 4, 5]

foundInteger :: Integer -> [Integer] -> Bool
foundInteger x [] = False
foundInteger x (y:l)
    | x == y = True
    | otherwise = foundInteger x l
