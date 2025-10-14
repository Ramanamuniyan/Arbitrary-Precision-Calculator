# 🔢 Big Integer Calculator (C Implementation)

A **C-based Big Integer Arithmetic Calculator** that performs mathematical operations (`+`, `-`, `x`, `/`, `%`) on **large numbers** using **Doubly Linked Lists (DLL)**.  
This project overcomes the limitations of built-in C data types (`int`, `long`, etc.) by handling arbitrarily large integers as lists of digits.

---

## 📘 Features

✅ Uses **Doubly Linked List** for storing and processing digits  
✅ Supports **Addition, Subtraction, Multiplication, Division, and Modulus**  
✅ Handles **Negative Integers** properly  
✅ **Precise Addition** and accurate results for all arithmetic operations  
✅ **Input validation** for operands and operators  
✅ Includes **Makefile** for easy compilation (only compiles modified `.c` files)  
✅ Easy execution using:  
```bash
./apc.exc <integer1> <operator> <integer2>
```

---

## ⚙️ Project Structure

```
├── main.c
├── valid.h
├── valid.c
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── reminder.c
├── dlist.c
├── dlist.h
├── Makefile
└── README.md
```

> Each arithmetic operation is implemented separately for modularity and easy debugging.

---

## 🧮 Usage

### 🧱 Compilation
Use the provided `Makefile` for convenient incremental builds:

```bash
make
```

This will compile only modified `.c` files and generate an executable named **apc.exc**.

You can also compile manually if needed:
```bash
gcc main.c valid.c addition.c subtraction.c multiplication.c division.c reminder.c dlist.c -o apc.exc
```

### ▶️ Execution

Run the program with three command-line arguments:
```
./apc.exc <operand1> <operator> <operand2>
```

---

## 📖 Example Runs

#### ➕ Addition
```bash
./apc.exc 999999999999999999999999 + 1
```
Output:
```
999999999999999999999999 + 1 = 1000000000000000000000000
```

#### ➖ Subtraction
```bash
./apc.exc -123456789 - 987654321
```
Output:
```
-123456789 - 987654321 = -1111111110
```

#### ✖️ Multiplication
```bash
./apc.exc 123456789 x 987654321
```
Output:
```
123456789 x 987654321 = 121932631112635269
```

#### ➗ Division
```bash
./apc.exc 100000000000000000000000 / 2
```
Output:
```
100000000000000000000000 / 2 = 50000000000000000000000
```

#### 🧩 Modulus
```bash
./apc.exc 10 % 3
```
Output:
```
10 % 3 = 1
```

---

## 🧰 Input Validation

The program ensures:
- Both operands contain only digits (and an optional leading `-`)
- Operator is one of: `+`, `-`, `x`, `X`, `*`, `/`, `%`

Invalid input results in helpful error messages:
```
operators should be '+','-','x','/'
operand 1 is not a digit
operand 2 is not a digit
```

---

## 🧠 How It Works

1. **Operands** are parsed and stored as digits in a **Doubly Linked List (DLL)**.  
2. Each arithmetic operation processes digits manually (similar to paper-based math).  
3. **Sign handling** ensures correct output for negative numbers.  
4. **Results** are also stored in a linked list and printed.

---

## 🧩 Makefile Usage

### Build:
```bash
make
```

### Clean:
```bash
make clean
```

### Run:
```bash
./apc.exc <integer1> <operator> <integer2>
```

Example:
```bash
./apc.exc -4567 + 12345
```

---

## 🧑‍💻 Author

**Ramana**  
💻 Focused on C programming and data structures  
📂 Designed for system-level understanding of arithmetic using linked lists  

---

## 📜 License

This project is open-source and available under the **MIT License**.
