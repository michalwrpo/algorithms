module BinarySearch (binarySearch, binarySearch1) where

-- Worth noting that Binary Search doesn't make much sense in haskell, considering how slow !! operator is

-- Minimalizes the average number of comparisons
binarySearch :: Ord a => [a] -> Int -> Int -> a -> Int
binarySearch xs s e v
    | e - s < 2 =
        if xs !! mid == v then mid
        else -1
    | xs !! mid > v = binarySearch xs s mid v
    | otherwise = binarySearch xs mid e v
    where mid = div (s + e) 2

-- Checks the midpoint every time, better best case time
binarySearch1 :: Ord a => [a] -> Int -> Int -> a -> Int
binarySearch1 xs s e v
    | e - s < 2 =
        if ele == v then mid
        else -1
    | ele == v = mid
    | ele > v = binarySearch1 xs s mid v
    | otherwise = binarySearch1 xs mid e v
    where 
        mid = div (s + e) 2 
        ele = xs !! mid
