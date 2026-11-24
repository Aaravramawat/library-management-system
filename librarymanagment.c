#include <stdio.h>

#define TOTAL_BOOKS 10

struct Book {
    int id;
    char title[60];
    int available;
};
void clearInputBuffer(void);
int readInteger(const char *prompt, int *value);
void displayBooks(const struct Book books[], int count);
void searchBook(const struct Book books[], int count);
void issueBook(struct Book books[], int count);
void returnBook(struct Book books[], int count);
int findBook(const struct Book books[], int count, int id);

int main(void) {
    struct Book books[TOTAL_BOOKS] = {
        {101, "C Programming", 1},
        {102, "Data Structures", 1},
        {103, "Computer Networks", 1},
        {104, "Operating Systems", 1},
        {105, "Engineering Mathematics", 1},
        {106, "Database Management", 1},
        {107, "Computer Fundamentals", 1},
        {108, "Digital Electronics", 1},
        {109, "Web Technology", 1},
        {110, "Software Engineering", 1}
    };

    int choice;
    int status;

    do {
        printf("\n========== LIBRARY BOOK MANAGEMENT ==========\n");
        printf("1. Display all books\n");
        printf("2. Search book by ID\n");
        printf("3. Issue a book\n");
        printf("4. Return a book\n");
        printf("5. Exit\n");

        status = readInteger("Enter your choice: ", &choice);

        if (status == 0) {
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        } else if (status == -1) {
            printf("\nExiting program...\n");
            break;
        }

        switch (choice) {
            case 1:
                displayBooks(books, TOTAL_BOOKS);
                break;
            case 2:
                searchBook(books, TOTAL_BOOKS);
                break;
            case 3:
                issueBook(books, TOTAL_BOOKS);
                break;
            case 4:
                returnBook(books, TOTAL_BOOKS);
                break;
            case 5:
                printf("Thank you for using the library system.\n");
                break;
            default:
                printf("Please select a valid option (1 to 5).\n");
        }
    } while (choice != 5);

    return 0;
}


void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
      
    }
}
int readInteger(const char *prompt, int *value) {
    int result;

    printf("%s", prompt);
    result = scanf("%d", value);

    if (result == 1) {
    clearInputBuffer();
        return 1;
    } else if (result == EOF) {
        return -1;
    } else {
        clearInputBuffer();
        return 0;
    }
}

void displayBooks(const struct Book books[], int count) {
    int i;

    printf("\n---------------- BOOK LIST ----------------\n");
    printf("%-8s %-30s %s\n", "Book ID", "Title", "Status");

    for (i = 0; i < count; i++) {
        printf("%-8d %-30s %s\n",
               books[i].id,
               books[i].title,
               books[i].available ? "Available" : "Issued");
    }
}

int findBook(const struct Book books[], int count, int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            return i;
        }
    }

    return -1;
}

void searchBook(const struct Book books[], int count) {
    int id, index, status;

    status = readInteger("Enter book ID to search: ", &id);
    if (status != 1) {
        if (status == 0) {
            printf("Invalid ID. Please enter a valid number.\n");
        }
        return;
    }

    index = findBook(books, count, id);

    if (index == -1) {
        printf("Book not found.\n");
    } else {
        printf("\nBook found!\n");
        printf("ID: %d\n", books[index].id);
        printf("Title: %s\n", books[index].title);
        printf("Status: %s\n",
               books[index].available ? "Available" : "Issued");
    }
}

void issueBook(struct Book books[], int count) {
    int id, index, status;

    status = readInteger("Enter book ID to issue: ", &id);
    if (status != 1) {
        if (status == 0) {
            printf("Invalid ID. Please enter a valid number.\n");
        }
        return;
    }

    index = findBook(books, count, id);

    if (index == -1) {
        printf("Book not found.\n");
    } else if (books[index].available == 0) {
        printf("This book is already issued.\n");
    } else {
        books[index].available = 0;
        printf("Book issued successfully: %s\n", books[index].title);
    }
}

void returnBook(struct Book books[], int count) {
    int id, index, status;

    status = readInteger("Enter book ID to return: ", &id);
    if (status != 1) {
        if (status == 0) {
            printf("Invalid ID. Please enter a valid number.\n");
        }
        return;
    }

    index = findBook(books, count, id);

    if (index == -1) {
        printf("Book not found.\n");
    } else if (books[index].available == 1) {
        printf("This book is already marked as available.\n");
    } else {
        books[index].available = 1;
        printf("Book returned successfully: %s\n", books[index].title);
    }
}