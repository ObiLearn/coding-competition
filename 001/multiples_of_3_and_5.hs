import Prelude

main = do
    --let result = foldl (+) 0 $ filter (\x -> x `mod` 3 == 0 || x `mod` 5 == 0) [1..999]
    let result = sum [x | x <- [1..999], x `mod` 5 == 0 || x `mod` 3 == 0]
    print result
