Algorithm 1: Connecting Pairs of Persons
Assume that there are 𝑛 individuals (possibly couples) sitting in 2𝑛 seats arranged in a row. They
can hold hands. The people and the seats are presented by an integer row, where 𝑟𝑜𝑤[𝑖] is the
ID of the person sitting in the 𝑖th seat. The couples are arranged in order, the first couple is
presented as (0, 1), the second couple being (2, 3), and so on, until the last couple. The last couple
being (2𝑛 − 2, 2𝑛 − 1).
Design an algorithm that that takes in any available number of couple and return the minimum
number of swaps, such that every couple is sitting side by side. A swap consists of choosing any
two people, and ensuring that they switch seats
Below are some sample inputs and outcomes.
Sample 1:
Input: row = [0, 2, 1, 3]
Output: 1
Only the second (row[1]) needs to be swapped with the third (row[2]) individual
Sample 2:
Input: row = [3,2,0,1]
