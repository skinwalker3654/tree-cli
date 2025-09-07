# Tree CLI

A simple interactive CLI for working with **Binary Search Trees** (BST) in C.
You can add, delete, search, and print the tree using different traversal methods.
INORDER PREORDER POSTORDER.

---

## 🗂️ File Structure

```text
tree-cli/
  ├── src/
  │    ├── main.c  #Command-line interface logic
  │    ├── tree.c  #BST implementation
  │    └── tree.h  #Header for BST functions and structs
  │ 
  ├── Makefile  #Builds the project into a 'bin' folder
  ├── README.md  #You're here!
  └── LICENSE  #MIT License
```

## Build instructions

you need the `gcc` compiler

```bash
make       #compils the program
make run   #runs the program
```
this will compile the program into the bin folder.

## Available commands

- `add`     <value>
- `del`     <value>
- `find`    <value>
- `cls`
- `exit`
- `help`
- `inorder`
- `postorder`
- `preorder`
