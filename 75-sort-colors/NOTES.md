​
Mid == 2
Swap High and Mid
High--
​
0 1 0 2 1 2
^ ^   ^
L M   H
​
Mid == 0
Swap Low and Mid
Mid++
Low++
​
0 0 1 2 1 2
^ ^ ^
L M H
​
Mid == 2
Swap High and Mid
High--
​
0 0 1 1 2 2
^ ^
L M
H
​
Mid <= High is our exit case