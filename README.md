# Library Management System

This is a simple console-based Library Management System written in C++. It allows you to add books, DVDs, and magazines to the library's collection, manage library users, check out and return items, and display available items. The system provides basic functionality for a library management system and can be used as a starting point for further development.

## Features

- **Add Books:** You can add books to the library by providing details like Book ID, Title, Author, and ISBN.

- **Add DVDs:** You can add DVDs to the library by providing details like DVD ID, Title, Director, and Runtime.

- **Add Magazines:** You can add magazines to the library by providing details like Magazine ID, Title, Editor, and Publication Date.

- **Add Users:** You can add library users by providing User ID and User Name.

- **Check Out Items:** Users can check out items by providing their User ID and the Item ID they want to borrow. If the item is available, it can be checked out, and its status changes to "not available."

- **Return Items:** Users can return items by providing their User ID and the Item ID they want to return. The item's status changes back to "available."

- **Display Available Items:** You can display a list of available items in the library.

- **Delete Items:** You can delete items from the library collection by providing the Item ID.

- **Exit Options:** You can exit the system, delete all items and exit, or cancel the exit operation.

## How to Use

1. Clone the repository to your local machine.

2. Compile the code using a C++ compiler.

3. Run the executable.

4. Use the menu to perform various operations.

## Example Usage

```plaintext
Library Management System Menu:
1. Add a Book
2. Add a DVD
3. Add a Magazine
4. Add a User
5. Check Out Item
6. Return Item
7. Display Available Items
8. Delete Item
9. Exit
Enter your choice: 1

Enter Book ID: 101
Enter Book Title: The Catcher in the Rye
Enter Author: J.D. Salinger
Enter ISBN: 978-0-316-76948-7

Item added successfully.

...

Enter your choice: 7

Available Items:
Book ID: 101, Title: The Catcher in the Rye, Author: J.D. Salinger, ISBN: 978-0-316-76948-7

...

Enter your choice: 9

Exit Options:
1. Confirm
2. Delete All Items and Exit
3. Cancel
Enter your choice: 1

Exiting the Library Management System.
