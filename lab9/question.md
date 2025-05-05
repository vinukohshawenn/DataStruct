/*
A)
Nene invented a new game based on an increasing sequence of integers a1,a2,…,ak
.

In this game, initially n
 players are lined up in a row. In each of the rounds of this game, the following happens:

Nene finds the a1
-th, a2
-th, …
, ak
-th players in a row. They are kicked out of the game simultaneously. If the i
-th player in a row should be kicked out, but there are fewer than i
 players in a row, they are skipped.
Once no one is kicked out of the game in some round, all the players that are still in the game are declared as winners.

For example, consider the game with a=[3,5]
 and n=5
 players. Let the players be named player A, player B, …
, player E in the order they are lined up initially. Then,

Before the first round, players are lined up as ABCDE. Nene finds the 3
-rd and the 5
-th players in a row. These are players C and E. They are kicked out in the first round.
Now players are lined up as ABD. Nene finds the 3
-rd and the 5
-th players in a row. The 3
-rd player is player D and there is no 5
-th player in a row. Thus, only player D is kicked out in the second round.
In the third round, no one is kicked out of the game, so the game ends after this round.
Players A and B are declared as the winners.
Nene has not yet decided how many people would join the game initially. Nene gave you q
 integers n1,n2,…,nq
 and you should answer the following question for each 1≤i≤q
 independently:

How many people would be declared as winners if there are ni
 players in the game initially?
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤250
). The description of test cases follows.

The first line case contains two integers k
 and q
 (1≤k,q≤100
) — the length of the sequence a
 and the number of values ni
 you should solve this problem for.

The second line contains k
 integers a1,a2,…,ak
 (1≤a1<a2<…<ak≤100
) — the sequence a
.

The third line contains q
 integers n1,n2,…,nq
 (1≤ni≤100
).

Output
For each test case, output q
 integers: the i
-th (1≤i≤q
) of them should be the number of players declared as winners if initially ni
 players join the game.
B)There are n
 participants in a competition, participant i
 having a strength of si
.

Every participant wonders how much of an advantage they have over the other best participant. In other words, each participant i
 wants to know the difference between si
 and sj
, where j
 is the strongest participant in the competition, not counting i
 (a difference can be negative).

So, they ask you for your help! For each i
 (1≤i≤n
) output the difference between si
 and the maximum strength of any participant other than participant i
.

Input
The input consists of multiple test cases. The first line contains an integer t
 (1≤t≤1000
) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains an integer n
 (2≤n≤2⋅105
) — the length of the array.

The following line contains n
 space-separated positive integers s1
, s2
, ..., sn
 (1≤si≤109
) — the strengths of the participants.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output n
 space-separated integers. For each i
 (1≤i≤n
) output the difference between si
 and the maximum strength of any other participant.
C. Write a separate C++ menu-driven program to implement Tree ADT using a binary search tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations, 
 
1. Insert 
2. Preorder 
3. Inorder 
4. Postorder 
5. Search 
6. Exit 
D. Add a "construct expression tree" method to the binary tree data structure from the previous lab code—import stack from the standard template library (STL) to construct the expression tree. Import the Tree ADT program into another program that gets a valid postfix expression, constructs, and prints the expression tree. It consists of the following operations. 
 
1. Postfix Expression 
2. Construct Expression Tree 
3. Preorder 
4. Inorder 
5. Postorder 
6. Exit 
*/
