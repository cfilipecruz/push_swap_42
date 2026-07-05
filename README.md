*This project has been created as part of the 42 curriculum by cmarques, joavieir.*

# push_swap

## Description

`push_swap` sorts a list of unique integers using two stacks and a limited set of
operations. It prints the operations needed to leave stack A sorted in ascending
order and stack B empty.

## Instructions

Compile with:

```bash
make
```

Run with a strategy and a list of integers:

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] 4 2 1 3
```

Invalid numbers, duplicates and values outside the `int` range print `Error`.

## Algorithms

### Simple - O(n^2)

A Turk-style insertion method moves the cheapest elements to B, sorts the three
remaining values, and inserts everything back in order. Each of the `n` values
may need `O(n)` moves, giving `O(n^2)` operations and `O(1)` extra space.

### Medium - O(n sqrt(n))

Values are ranked from `0` to `n - 1` and processed in a moving window of about
`sqrt(n)` values. There are about `sqrt(n)` groups, each costing up to `O(n)`
moves, so the limit is `O(n sqrt(n))` operations and `O(n)` extra space.

### Complex - O(n log n)

LSD binary radix sort reads one rank bit per pass. Each pass uses at most `2n`
operations and there are `log2(n)` bits, giving `O(n log n)` operations and
`O(n)` extra space. Ranks also avoid signed-bit handling.

### Adaptive

The initial disorder is measured before any move:

```text
disorder < 0.20          simple
0.20 <= disorder < 0.50 medium
disorder >= 0.50         complex
```

Low disorder uses insertion because few values need repositioning. Medium
disorder uses chunks to avoid full radix passes. High disorder uses radix for a
predictable `O(n log n)` limit. Ranking arrays are temporary, so the adaptive
strategy uses at most `O(n)` extra space.

## Contributions

- `cmarques`: stack operations, utilities, validation, medium and complex strategies.
- `joavieir`: initialization, utilities, disorder metric, simple strategy and
  adaptive integration.
- Both: testing, debugging and documentation.

## Resources

- Linux manual pages: `write`, `malloc`, `free`
- *The C Programming Language*, Brian Kernighan and Dennis Ritchie
- References on insertion methods, chunk sorting and binary radix sort

AI tools were used to explain concepts, review edge cases, suggest tests and help
review the documentation. Every suggestion was checked and adapted by the authors.
