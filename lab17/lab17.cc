#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_STR 200

// โครงสร้างข้อมูลหนังสือ
typedef struct {
    int bookID;
    char title[MAX_STR];
    char author[MAX_STR];
    int year;
} Book;

// ฟังก์ชันประกาศ
void addBook(Book books[], int *count);
void searchBook(Book books[], int count, char title[]);
void displayBooks(Book books[], int count);

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;
    char searchTitle[MAX_STR];

    do {
        printf("\nChoose an option:\n");
        printf("1. Add a New Book\n");
        printf("2. Search for a Book by Title\n");
        printf("3. Display All Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                printf("Enter Title to Search: ");
                fgets(searchTitle, sizeof(searchTitle), stdin);
                // ลบ newline ทิ้ง
                searchTitle[strcspn(searchTitle, "\n")] = '\0';
                searchBook(books, count, searchTitle);
                break;
            case 3:
                displayBooks(books, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// ฟังก์ชันเพิ่มหนังสือ
void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &books[*count].bookID);
    getchar(); // clear newline

    printf("Enter Title: ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = '\0';

    printf("Enter Author: ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = '\0';

    printf("Enter Year: ");
    scanf("%d", &books[*count].year);
    getchar(); // clear newline

    (*count)++;
    printf("Book added successfully!\n");
}

// ฟังก์ชันค้นหาหนังสือตามชื่อ
void searchBook(Book books[], int count, char title[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            return;
        }
    }
    printf("Book not found.\n");
}

// ฟังก์ชันแสดงหนังสือทั้งหมด
void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Book ID: %d\n", books[i].bookID);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year: %d\n", books[i].year);
    }
}
