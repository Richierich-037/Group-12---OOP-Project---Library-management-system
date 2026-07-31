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

     //getters
    string getName() {
     return name;
     }

    int getLibrarianID() {
    return librarianID;
    }

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
int main() {

    cout << "=====================================\n";
    cout << "   WELCOME TO THE LIBRARY SYSTEM\n";
    cout << "=====================================\n";


    // Create Librarian using user input

    int librarianID;
    string librarianName;


    cout << "\nEnter Librarian ID: ";
    cin >> librarianID;

    cin.ignore();

    cout << "Enter Librarian Name: ";
    getline(cin, librarianName);


    Librarian librarian(librarianID, librarianName);



    cout << "\nLibrarian Created Successfully\n";
    cout << "Name: " << librarian.getName();
    cout << "\nID: " << librarian.getLibrarianID() << endl;



    // Add Books

    Book book1(101, "George Orwell", "1984");
    Book book2(102, "Harper Lee", "To Kill a Mockingbird");
    Book book3(103, "J.R.R. Tolkien", "The Hobbit");
    Book book4(104, "F. Scott Fitzgerald", "The Great Gatsby");
    Book book5(105, "J.K. Rowling", "Harry Potter and the Philosopher's Stone");


    librarian.addBook(book1);
    librarian.addBook(book2);
    librarian.addBook(book3);
    librarian.addBook(book4);
    librarian.addBook(book5);



    // Create Users

    User user1(201, "Alice Johnson");
    User user2(202, "Bob Williams");
    User user3(203, "Charlie Brown");



    int choice;


    do {

        cout << "\n=====================================\n";
        cout << "          LIBRARY MENU\n";
        cout << "=====================================\n";

        cout << "1. Display all books\n";
        cout << "2. Issue a book\n";
        cout << "3. Return a book\n";
        cout << "4. Display users\n";
        cout << "5. Calculate fine\n";
        cout << "6. Exit\n";


        cout << "Enter choice: ";
        cin >> choice;



        switch(choice) {


        case 1:

            librarian.displayInventory();

            break;



        case 2:
        {
            int userChoice;
            int bookID;


            cout << "\nSelect User\n";
            cout << "1. " << user1.getName() << endl;
            cout << "2. " << user2.getName() << endl;
            cout << "3. " << user3.getName() << endl;

            cout << "Choice: ";
            cin >> userChoice;


            cout << "Enter Book ID: ";
            cin >> bookID;



            if(userChoice == 1)
                librarian.issueBook(user1, bookID);

            else if(userChoice == 2)
                librarian.issueBook(user2, bookID);

            else if(userChoice == 3)
                librarian.issueBook(user3, bookID);

            else
                cout << "Invalid user.\n";


            break;
        }



        case 3:
        {
            int userChoice;
            int bookID;


            cout << "\nSelect User\n";
            cout << "1. " << user1.getName() << endl;
            cout << "2. " << user2.getName() << endl;
            cout << "3. " << user3.getName() << endl;


            cout << "Choice: ";
            cin >> userChoice;


            cout << "Enter Book ID: ";
            cin >> bookID;



            if(userChoice == 1)
                librarian.returnBook(user1, bookID);

            else if(userChoice == 2)
                librarian.returnBook(user2, bookID);

            else if(userChoice == 3)
                librarian.returnBook(user3, bookID);

            else
                cout << "Invalid user.\n";


            break;
        }




        case 4:

            cout << "\n--- USER INFORMATION ---\n";


            cout << "\nUser 1";
            user1.displayUser();


            cout << "\nUser 2";
            user2.displayUser();


            cout << "\nUser 3";
            user3.displayUser();


            break;



        case 5:
        {
            int lateDays;


            cout << "Enter number of late days: ";
            cin >> lateDays;


            cout << "Fine: $"
                 << librarian.calculateFine(lateDays)
                 << endl;


            break;
        }



        case 6:

            cout << "\nThank you for using the Library System.\n";

            break;



        default:

            cout << "Invalid choice.\n";

        }


    } while(choice != 6);



    return 0;
}
