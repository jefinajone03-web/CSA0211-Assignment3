# C Programming - Assignment 3 (CSA 0211)

Searching, sorting, merging, 2-D arrays and strings in C.

| File | Question | Topic |
| --- | --- | --- |
| `q1_library_search.c` | Q1 | Linear Search vs Binary Search (comparison counts) |
| `q2_sorting_seating.c` | Q2 | Bubble, Selection and Insertion Sort |
| `q3_merge_merit_lists.c` | Q3 | Merging two descending merit lists |
| `q4_rainfall_2d_array.c` | Q4 | District rainfall using a 38 x 12 2-D array |
| `q5_string_processing.c` | Q5 | Word count, uppercase, reverse, palindrome (no `string.h`) |
| `q6_names_directory.c` | Q6 | Sorting, binary search and duplicate detection on names |
| `q7_election_counting.c` | Q7 | Election counting with validation, ranking and tie detection |

## Compile and run

```bash
gcc -Wall -Wextra q1_library_search.c -o q1
./q1
```

Q4, Q6 and Q7 read input. Sample inputs and outputs are in `sample_outputs/`:

```bash
./q4 < sample_outputs/q4_input.txt
printf '4\n10\n1\n2\n1\n3\n2\n1\n4\n0\n5\n3\n' | ./q7
```
