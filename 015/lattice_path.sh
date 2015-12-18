#!/bin/bash

# idea binomial coefficients
# in 20 of 40 cases you choose to go down
# 40!/(20!*20!)


fac(){
    local n=$(($1 + 1))
    local rv=1

    while ((n-- > 1)); do
        local rv=$((rv * n))
    done

    echo $rv
}

echo "bash only:"
fn=$(fac 40); echo $fn
fk=$(fac 20); echo $fk
echo $(( fn / (fk * fk ) ))

# numbers are too big for bash :(  - we could try: 40 .. 21 / 20!
# or use a better language

echo "in python:"
python -c 'from math import factorial as f; print(f(40)/(f(20)*f(20)))'
