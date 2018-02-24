# The Problem
This challenge is good to give programming candidates because it contains two sub-problems: **grid traversal** and **word lookup**.

The candidate has to make sure that the grid is navigated completely, building up potential words as they do so, and also determine if the potential word is in the dictionary.

## Notes
The word list does not need to be stored or sorted. The words can be displayed as soon as they are found.

A populated 4x4 grid is provided, but the solution should accommodate a grid with an arbitrary width and height (both >=3); i.e. the code should not assume the grid is 4x4. The only assumption that can be made is that the grid is at least 3x3.

A dictionary is also provided. However, how it is used is up to the candidate.


# Grid Traversal
The first problem to solve is how to traverse the entire grid in such a way that guarantees that all valid combinations of grid locations have been attempted. Interviewers should be looking for use of a [tree data structure](https://en.wikipedia.org/wiki/Tree_(data_structure) using a [pre-order](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order) [depth-first search](https://en.wikipedia.org/wiki/Tree_traversal#Depth-first_search) algorithm.

This can be solved in two ways:
- Recursive
- Iterative

**It is up to the reviewer to decide which solution is acceptable and to make that known to the candidate without hinting at a possible solution.** For example, if a recursive solution is desired, the interviewer can mention a time constraint: *"We have a limited amount of time today so use the solution that is quicker to write."*


# Word Lookup
The other problem the candidate needs to solve is how to determine if a potential word is in the dictionary. They are likely to think of a brute-force approach first, but that is a trap because the dictionary is deliberately very large. They should be thinking about runtime efficiency and the data structures and algorithms needed for that.

This can also be solved a number of ways, for example:
- [Hashing](https://en.wikipedia.org/wiki/Hash_table)
- [Trees](https://en.wikipedia.org/wiki/Tree_(data_structure)

Other than brute-force, there is, perhaps, no wrong algorithm. The [Discussion Topics](#topics) section asks about other ways that it could be implemented and the trade-offs associated with them.

# <a name="topics"></a>Discussion Topics
Once the challenge is complete, it would be interesting for the interviewer and interviewee to discuss the solution.

## General Questions
**Was the solution complete (were all entries found)? If not, what were the challenges?**

## Grid Traversal
**How efficient is the algorithm used for grid traversal? What is the Big-O notation? How long does it take run? How much memory does it consume? Do your answers change if the dataset was much larger? Why or why not?**

**Are there ways to make it more efficient?**  
Another way to ask this is: *if the grid was extremely large, would the algorithm hold up?*

**Are there another algorithms that can be used? What trade-offs are associated with them?**

**What are some other applications in which your algorithm is useful?**


## Word Lookup
**How efficient is the algorithm used for dictionary lookup? What is the Big-O notation? How long does it take run? How much memory does it consume? Do your answers change if the dataset was much larger? Why or why not?**

**Are there ways to make it more efficient?**  
The dictionary is already deliberately quite large, but the candidate doesn't know this at first unless they ask. It is acceptable for the interviewer to answer this in a general way, such as: *you can assume the number of entries is arbitrary*. That sounds a bit harsh, but the candidate should infer that it *could be really large* so should be thinking *away* from using a brute-force solution.

**Would your algorithm change if the dataset contained only numbers? Why or why not?**

**Are there another algorithms that can be used? What trade-offs are associated with them?**

**What are some other applications in which your algorithm is useful?**


# Exercises
1. Implement a different algorithm for grid traversal. Compare the efficiency results with the original solution. Which one is better? What makes it better? How do you define "better"?
2. Implement a different algorithm for word lookup. Compare the efficiency results with the original solution. Which one is better? What makes it better? How do you define "better"?
3. Time the current solution. Perform other optimizations without generally changing any algorithm. Measure the difference and compare. Were the optimizations worth the time/effort spent implementing them? Why or why not? Do the optimizations make the solution risky or more brittle? What can be inferred from your results?


# The Data
## Sample Grid
The grid data in the materials is:
```
    t i l s
    h n a v
    g i m e
    n e p o
```

## The Word List
There are 53 words in the sample grid shown above:
```
alit
ami
ani
anigh
anight
anil
anime
ave
eight
evan
gie
gien
gimp
imp
lam
lame
lamp
lave
lin
lit
lith
mal
mali
man
mani
mien
mig
might
mina
nam
name
nave
neigh
nep
nigh
night
nil
nils
nim
nit
ope
open
pein
pen
poem
slam
slave
slit
til
tin
vali
vamp
van
```

--
This repo was created by Bob Koon on Feb. 24, 2018.

[GitHub](https://github.com/BobatBH)

[Twitter](https://twitter.com/Bob_at_BH)

[LinkedIn](https://www.linkedin.com/in/bob-koon-5943/)
