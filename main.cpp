#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Book { //this is the book class
private:
    string title;
    string author;
    int bookID;
    bool isAvailable;

public: // a constructor 
    Book(int ID, string bookAuthor, string bookTitle) {
        bookID = ID;
        author = bookAuthor;
        title = bookTitle;
        isAvailable = true;
    }// getters
    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
    int getBookID() {
        return bookID;
    }
    bool getAvailability() {
        return isAvailable;
    }
    void setAvailability(bool status) {
        isAvailable = status;
    }
    // to display book information
    void displayBook() {
      cout << "\nTitle: " << title;
      cout << "\nAuthor: " << author;
      cout << "\nBook ID: " << bookID;

    if (isAvailable) {
     cout << "\nStatus: Available\n";
      }
    else {
     cout << "\nStatus: Unavailable\n";
        }
    }
}; 
class User { //this is the user class 
private:
    int userID;
    string name;
    vector<int> borrowedBooks;

public:
//this is a constructor
    User(int id, string userName) {
        userID = id;
        name = userName;
    }

    // Getters
    int getUserID() {
        return userID;
    }
    string getName() {
        return name;
    }

    // to borrow a book
    void borrowBook(int bookID) {
        borrowedBooks.push_back(bookID);
    }
    // to return a book
    void returnBook(int bookID) {
    for (int i = 0; i < borrowedBooks.size(); i++) {

   if (borrowedBooks[i] == bookID) {

     borrowedBooks.erase(
      borrowedBooks.begin() + i
      );
     cout << "Book returned successfully.\n";
   return;
            }
        }
    cout << "This user did not borrow that book.\n";
    }
    // to display user information
    void displayUser() {
      cout << "\nUser ID: " << userID;
        cout << "\nName: " << name;
        cout << "\nNumber of borrowed books: "
             << borrowedBooks.size() << endl;
    }
};
class Librarian { //this is the librarian class 
private:
    int librarianID;
    string name;
    vector<Book> inventory;

public:
    // Constructor
    Librarian(int id, string librarianName) {
        librarianID = id;
        name = librarianName;
    }
    // to add a book
    void addBook(Book book) {
        inventory.push_back(book);
        cout << book.getTitle()
     << " was added to the library.\n";
    }

    // to display inventory
    void displayInventory() {
        cout << "\n LIBRARY INVENTORY n";
        for (int i = 0; i < inventory.size(); i++) {
          inventory[i].displayBook();
        }
    }
    //  to issue a book
    void issueBook(User& user, int bookID) {

    for (int i = 0; i < inventory.size(); i++) {
     if (inventory[i].getBookID() == bookID) {
         if (inventory[i].getAvailability()) {
      inventory[i].setAvailability(false);
     user.borrowBook(bookID);
      cout << "\nBook issued successfully.\n";
        }
       else {
         cout << "\nThis book is unavailable.\n";
         }
   return;        }
    }
        cout << "\nBook not found.\n";
    }
    void returnBook(User& user, int bookID) {
    for (int i = 0; i < inventory.size(); i++) {
     if (inventory[i].getBookID() == bookID) {
         inventory[i].setAvailability(true);
        user.returnBook(bookID);
           return;
        }
        }
        cout << "\nBook not found.\n";
    }
    double calculateFine(int lateDays) {
        double finePerDay = 2.0;
        if (lateDays <= 0) {
            return 0;
        }
       return lateDays * finePerDay;
    }
};
