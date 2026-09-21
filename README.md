# Network Routing Engine

A C++ network routing engine that models a network as a graph and finds a valid route between two nodes subject to a minimum bandwidth requirement.

## Overview

This project implements a graph-based routing system using **nodes** and **edges** to represent a network topology. Given a source node, destination node, and minimum required bandwidth, the program searches for a route where every connection along the path satisfies the bandwidth requirement.

The project was developed in C++ with an emphasis on object-oriented design, dynamic memory management, graph traversal, and file-based network configuration.

## Features

* Represents network topologies using nodes and edges
* Loads network information from an input file
* Finds routes between a source and destination node
* Enforces a minimum bandwidth requirement for every connection
* Uses depth-first search (DFS) with backtracking
* Supports multiple bandwidth requirements
* Includes implementations using both raw pointers and `std::unique_ptr`
* Demonstrates dynamic memory management and object ownership

## How It Works

The network is represented as a graph:

* **Nodes** represent devices or locations in the network.
* **Edges** represent connections between nodes.
* Each edge has an associated **bandwidth capacity**.

When searching for a route, the program:

1. Starts at the source node.
2. Examines connected nodes.
3. Only considers connections whose bandwidth meets the required minimum.
4. Uses DFS to continue searching through the network.
5. Backtracks when a path cannot reach the destination.
6. Returns a valid route if one exists.

For example, a route requiring at least `100` units of bandwidth will only use edges with bandwidth of `100` or greater.

## Example

The program can test different bandwidth requirements:

```text
Minimum bandwidth: 50
Route: A -> B -> D -> F

Minimum bandwidth: 100
Route: A -> C -> D -> F

Minimum bandwidth: 200
No valid route found
```

The exact route depends on the network topology provided in the input file.

## Memory Management

The project includes two approaches to managing dynamically allocated graph objects:

### Raw Pointers

The raw-pointer implementation manually manages memory using:

* Constructors
* Destructors
* Copy constructors
* Copy assignment operators

This demonstrates explicit ownership and lifetime management in C++.

### Smart Pointers

The smart-pointer implementation uses `std::unique_ptr` to automatically manage object lifetime and reduce the need for manual memory cleanup.

This provides an example of how modern C++ can use RAII to make dynamically allocated resources safer and easier to manage.

## Technologies

* **C++**
* Object-Oriented Programming
* Graph Data Structures
* Depth-First Search (DFS)
* Backtracking
* `std::vector`
* `std::unique_ptr`
* Dynamic Memory Management
* File I/O

## Project Structure

```text
network-routing-engine/
├── src/
│   └── ...
├── include/
│   └── ...
├── data/
│   └── ...
└── README.md
```

## What I Learned

This project provided practice with:

* Representing real-world systems using graph data structures
* Implementing DFS and backtracking
* Working with dynamically allocated objects
* Comparing manual memory management with smart pointers
* Designing classes with proper copy semantics
* Reading structured data from files
* Separating program functionality into reusable components

## Limitations

The routing algorithm searches for a **feasible** path rather than optimizing for a specific metric such as:

* Shortest path
* Highest available bandwidth
* Lowest latency
* Fewest network hops

The first valid route found by the DFS traversal is returned.

## Author

**Amin Charepoo**

Computer Engineering — Northeastern University
