​<h1> Question of Disjoint Union Set </h1>

<h2> INTUITION </h2>

PART 1 - 
1. There is no limit of swapping
2. The graph will be undirected becoz swapping doesn't limit on direction
3. if [0,3] can be swapped and [0,4] can be swapped then we can say that there is an edge which join [2,4] that is why they can also be swapped.
4. So for above point 3 we can use either DFS/BFS or Disjoint Union Set

e.g,
Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"

```
0------------3
|
|
|
|
2------------1

```
This is the required graph obtained 

<h3> How to use DSU </h3>

1. Make an array to store par and rnk of each node
2. size? obviously n = size of string 
3. then on each pair find parent and simultaneously rank
4. After that make an adjency list and store every child of a particular parent
5. from logic of above PART 1 pt 3 we can store all the character to particular child indices and sort them.
6. Simultaneously add all the char to the pos adj[i][j].
