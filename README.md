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

Values are converted to ranks from `0` to `n - 1`. This keeps their relative
order while making chunk and bit operations simpler.

### Simple - O(n^2)

A Turk-style insertion method moves the cheapest elements to B, sorts the three
remaining values in A, and inserts every value back into its correct position.

### Medium - O(n sqrt(n))

A chunk method processes ranks through a moving window of about `sqrt(n)` values.
Elements are pushed to B, then the largest values return to A using the shortest
rotation direction.

### Complex - O(n log n)

An LSD binary radix sort reads one rank bit at a time. Values are separated with
`pb` and `ra`, then returned with `pa`. Ranks avoid signed-bit handling and keep
the number of passes close to `log2(n)`.

### Adaptive

The initial disorder is measured before any move:

```text
disorder < 0.20             simple
0.20 <= disorder < 0.50     medium
disorder >= 0.50            complex
```

This uses lighter work for ordered inputs and more scalable methods for higher
disorder.

## Contributions

- `cmarques`: stack operations, utilities, validation, medium and complex strategies.
- `joavieir`: initialization, utilities, disorder metric, simple strategy, bench mode implementation and
  adaptive integration.
- Both: testing, debugging and documentation.

## Resources

- Linux manual pages: `write`, `malloc`, `free`
- *The C Programming Language*, Brian Kernighan and Dennis Ritchie
- References on insertion methods, chunk sorting and binary radix sort

AI tools were used to explain concepts, review edge cases, suggest tests and help
review the documentation. Every suggestion was checked and adapted by the authors.
