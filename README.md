# 📚 Library Book Management System

A simple, interactive console-based library book management application written in C. This program allows users to display books, search by ID, issue available books, and return issued books with real-time status tracking.

---

## 👥 Team Details

| **Batch** | Batch 20 |
| **Team Name** | AP Coders |
| **Team Members** | • Aarav Ramawat<br>• Pariksit Bansal |

---

## 📌 Problem Statement

Manual tracking of library books in small setups can lead to confusion and misplaced records. This project provides a menu-driven C program to maintain an in-memory collection of library books, track their availability status, and prevent duplicate issuing or returning.

---

## 🎯 Objectives

- Provide a straightforward command-line interface for managing library records.
- Track book ID, title, and current availability status (`Available` / `Issued`).
- Apply and demonstrate fundamental C programming concepts learned in the lab.

---

## ✨ Features

- **Pre-loaded Library Catalog:** Starts with 10 pre-defined book records.
- **Display All Books:** Neatly shows book IDs, titles, and availability status.
- **Search by ID:** Quickly checks if a book exists in the library.
- **Issue a Book:** Marks an available book as issued (prevents issuing already checked-out books).
- **Return a Book:** Returns an issued book to the library (prevents returning books that are already available).
- **Input Validation:** Handles invalid menu choices and non-existent book IDs gracefully.

---

## 📂 Project Structure

```text
├── library.c      # Main source code containing structures, functions, and menu loop
└── README.md      # Project documentation
└── flowchart.     # flowchart of the whole code
```

---

## 💡 C Concepts Used

- **Structures (`struct`):** Groups related book attributes (`id`, `title`, `is_issued`) into a single data type.
- **Arrays:** Holds the collection of book records.
- **Modular Functions:** Separates operations (`displayBooks()`, `searchBook()`, `issueBook()`, `returnBook()`).
- **Control Flow:**
  - `do-while` loop to keep the menu active until exit.
  - `switch-case` to handle user menu choices.
  - `if-else` blocks for availability checks and validations.
- **Loops (`for`):** Iterates through arrays for searching and displaying items.
- **Standard I/O:** Uses `printf()` and `scanf()` for user interaction.

---

## ⚙️ Prerequisites

To run this program, you only need a standard C compiler:
- **GCC** (Linux / macOS / MinGW on Windows), or
- Any C IDE (Code::Blocks, Dev-C++, VS Code, CLion, etc.)

---

## 🚀 How to Compile and Run

### On Linux / macOS / Git Bash:
```bash
# 1. Compile the program
gcc library.c -o library

# 2. Run the executable
./library
```

### On Windows (Command Prompt / PowerShell):
```cmd
gcc library.c -o library.exe
library.exe
```

---

## 🧪 Sample Test Cases

| Test Case | User Action | Expected Output |
|---|---|---|
| **1. Display Catalog** | Choose Option `1` | Lists all 10 books with their title and status |
| **2. Search Valid Book** | Choose Option `2`, enter `101` | Displays book details and availability |
| **3. Search Invalid Book** | Choose Option `2`, enter `999` | Displays `"Book not found"` message |
| **4. Issue Available Book** | Choose Option `3`, enter `101` | Displays `"Book issued successfully"` |
| **5. Duplicate Issue** | Choose Option `3`, enter `101` again | Displays `"Book is already issued"` warning |
| **6. Return Issued Book** | Choose Option `4`, enter `101` | Displays `"Book returned successfully"` |
| **7. Duplicate Return** | Choose Option `4`, enter `101` again | Displays `"Book is already available"` warning |
| **8. Invalid Menu Choice** | Enter `8` at main menu | Displays `"Invalid choice! Please select 1-5"` |
| **9. Exit Program** | Choose Option `5` | Displays thank-you message and terminates |

---

## ⚠️ Current Limitations & Future Scope

- **In-Memory Storage:** Book records are stored in RAM during execution. Any changes reset when the program is closed.
- **Future Improvements:**
  - Add **File Handling** (`fopen`, `fread`, `fwrite`) to save book records permanently to a `.txt` or `.dat` file.
  - Allow adding new books and deleting old ones dynamically.
  - Add search by book title in addition to ID.
 
