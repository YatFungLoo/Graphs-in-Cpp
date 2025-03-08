# Graphs in C++

Simple implementation of undirect graph in C++ following the book Algorithms 4th Edition. (Note: other data structure such as Bags and ST are also from eariler chapter from the same book, reused from another repo of mine.)

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Graphs in C++](#graphs-in-c)
  - [Graph related (Move to a new Repo)](#graph-related-move-to-a-new-repo)
  - [To run the code](#to-run-the-code)

<!-- markdown-toc end -->

## Graph Abstract Data Type

Using Bag and array.

## Graph related (Move to a new Repo)

1. BFS
2. DFS
3. Topological sort
4. Weighted graph (Dijkstra's Algorithms)

## To run the code

```bash
cmake -S . --preset=debug -B build
```

or

```bash
cmake -S . --preset=release -B build
```

then run

```bash
cmake --build build
```

or

```bash
cd build && ninja clean && ninja
```

and executable will exist in the `build/` directory.

to generate compile_commands.json file for clangd LSP, use

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. --preset=${PRESET_NAME}

cd ${ROOT_DIRECTORY}

ln -s build/compile_commands.json
```
