<div align="center">

# Inventory Management System

### A console-based inventory management system built using C

</div>

---

## 📌 About

A **C-based Inventory Management System** designed to manage product records and perform common inventory operations through a simple console interface.

The project uses **structures, arrays, functions, file handling, and basic data processing** to store and manage inventory information.

---

## ✨ Features

* Add new products
* View all products
* Search products by ID
* Update product details
* Delete products
* Sell products and calculate bill amount
* Restock products
* Low-stock alerts
* Calculate total inventory value
* Dashboard with inventory statistics
* Save inventory data to a file
* Load previously saved inventory data

---

## 🛠️ Technologies Used

* **C**
* Structures
* Arrays
* Functions
* File Handling
* `stdio.h`
* `stdlib.h`
* `string.h`

---

## 📂 Data Managed

Each product contains:

* Product ID
* Product Name
* Quantity
* Price

The inventory supports up to **100 products**.

---

## ⚙️ How It Works

The application provides a menu-driven console interface where users can select different inventory operations.

Product information is maintained using a `struct Product`, while file handling is used to store and retrieve inventory data from `inventory.txt`.

The system also provides basic inventory calculations such as:

* Total stock
* Total inventory value
* Bill amount during sales
* Low-stock identification

---

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone <your-repository-url>
```

### 2. Open the project directory

```bash
cd Inventory-Management-System
```

### 3. Compile the program

```bash
gcc inventory.c -o inventory
```

### 4. Run

**Windows:**

```bash
inventory.exe
```

**Linux / macOS:**

```bash
./inventory
```

---

## 📚 Concepts Practiced

This project helped strengthen practical understanding of:

* C Structures
* Arrays
* Functions
* Loops and Conditional Statements
* Pointers and File Handling
* Searching and Updating Records
* Menu-driven Programming
* Basic Inventory Calculations

---

## 🚀 Future Improvements

Possible future improvements include:

* Better input validation
* Improved file-storage format
* Sorting and filtering products
* User authentication
* Graphical user interface
* Database integration

---

## 👨‍💻 Author

**Sathvik Talabathula**

B.Tech CSE (AI & ML)
CMR University

---

<div align="center">

**Built as an academic project to strengthen C programming and problem-solving skills.**

</div>
