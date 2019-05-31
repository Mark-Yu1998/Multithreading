# Multithreading

## Introduction

1. The office supply superstore, StapleMax, has commissioned you to create a new inventory management program for them.
There are 20 different files that contain the sales (in chronological order - one product per line) for each of 20 different salespeople. 
2. A multithreaded program (in the file staplemax.cpp) that deducts each item from the current inventory on the store shelves as it is sold (each line in the file that the program reads in).

3. If the sale reduces the inventory of that item to 0, that salesperson must immediately restock that item on the self before selling any more items. 

4. Restocking should only occur for a particular item when it runs out; never restock any item if there are still some of it on the shelves.

5. After the store closes for the day (i.e., all the files have been read & processed fully), the inventory program should print out how many items are currently on the shelves at close, and how many total sales transactions have been made (which should be the same as the total number of lines in all files). 

## Output

After the code finish running: 

- No items have 0 inventory on the shelves
- All the final values are deterministic

## Restocking value

- pen = 100 
- paper = 200
- toner = 40
- raptops = 15

## Compilation

- Makefile is provided, type **make** on bash command line
- To clean up, type **make clean** on bash command line

## Execution
run with: **./staplemax**


