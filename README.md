# Search Auto-Complete System

**(Trie Data Structure | Operating Systems Concepts)**

## Overview

This project implements a **real-time search auto-complete system** using the **Trie data structure**.
While the core search logic is based on data structures, the project is framed around **Operating Systems concepts** such as **memory management, file handling, and response-time efficiency** for interactive systems.

The system provides fast, prefix-based search suggestions similar to those used in command shells, editors, and search interfaces.

---

## Why This Is an Operating Systems Project

Operating Systems are responsible for **efficient resource management** and **low-latency interaction**.
This project maps to OS concepts in the following ways:

* **Memory Management**

  * Trie nodes are dynamically allocated on the heap.
  * Demonstrates trade-offs between memory usage and search speed.
  * Shows how large in-memory data structures affect system resources.

* **File System Interaction**

  * Dictionary words can be loaded from external files instead of hardcoding.
  * Demonstrates buffered file I/O and preprocessing at startup.

* **Real-Time Responsiveness**

  * Autocomplete must respond within milliseconds as the user types.
  * Models a **soft real-time system**, a common OS concern.

* **CPU Efficiency**

  * Prefix-based search avoids repeated full scans of data.
  * Reduces unnecessary CPU usage by limiting search to relevant subtrees.

This makes the project relevant to **systems programming and OS-level performance considerations**, not just algorithms.

---

## Features

* Fast prefix-based search using Trie
* Frequency-based ranking of suggestions
* Case-insensitive search
* Efficient lookup with predictable time complexity
* Scalable to large dictionaries (with performance trade-offs discussed)
---

## How It Works (High Level)

1. Dictionary words are inserted into a Trie.
2. Each Trie node represents a character and tracks word frequency.
3. When the user types a prefix:

   * The Trie is traversed up to the prefix.
   * All valid words under that prefix are collected.
   * Results are ranked and top suggestions are returned.

---


## Sample Input

```
ap
```

## Sample Output

```
app
apple
application
apply
```

---

## Complexity Analysis

* **Insertion Time:** O(L), where L is word length
* **Search Time:** O(L + N), where N is number of words under the prefix
* **Space Complexity:** O(total characters stored in Trie)

---

## Limitations

* DFS-based suggestion retrieval can become expensive for very large datasets.
* Additional memory is used to improve search speed.
* Industrial systems typically use precomputed top-K caching at each Trie node.

These limitations are intentional to highlight **OS-level trade-offs between memory and performance**.

---

## Possible Extensions

* Multithreaded input and search handling
* Precomputed top-K suggestions for faster queries
* Memory usage measurement and optimization
* File-based large dictionary loading

---

## Academic Relevance

This project demonstrates how **data structures are used within operating systems and system-level applications** to achieve efficient, responsive behavior under resource constraints.

---

## Author

**Kanishk**

---

