import Prelude

fibs :: [Integer]
fibs = 1:1:zipWith (+) fibs (tail fibs)

main = do
    let result = sum $ takeWhile (< 4000000) $ filter even $ fibs
    print result
