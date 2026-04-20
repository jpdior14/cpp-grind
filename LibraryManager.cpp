#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

// Forward declarations
class Book;
class Patron;

// ---------- Book Class ----------
class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    bool isCheckedOut;
    std::string checkedOutTo;  // patron ID
    static int totalBooks;

public:
    Book(const std::string& isbn, const std::string& title, const std::string& author)
        : isbn(isbn), title(title), author(author), isCheckedOut(false), checkedOutTo("") {
        totalBooks++;
    }

    ~Book() {
        totalBooks--;
    }

    bool checkOut(const std::string& patronId) {
        if (isCheckedOut) return false;
        isCheckedOut = true;
        checkedOutTo = patronId;
        return true;
    }

    bool returnBook() {
        if (!isCheckedOut) return false;
        isCheckedOut = false;
        checkedOutTo = "";
        return true;
    }

    void display() const {
        std::cout << std::left << std::setw(12) << isbn
                  << std::setw(25) << title
                  << std::setw(20) << author
                  << (isCheckedOut ? "Checked out by " + checkedOutTo : "Available")
                  << std::endl;
    }

    static int getTotalBooks() { return totalBooks; }

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.isbn << " | " << book.title << " | " << book.author;
        return os;
    }

    std::string getISBN() const { return isbn; }
    bool getAvailability() const { return !isCheckedOut; }
    std::string getCheckedOutTo() const { return checkedOutTo; }
};

int Book::totalBooks = 0;

// ---------- Patron Class ----------
class Patron {
private:
    std::string id;
    std::string name;
    std::vector<Book*> borrowedBooks;
    double fineBalance;
    static int nextId;

public:
    Patron(const std::string& name) : name(name), fineBalance(0.0) {
        id = "P" + std::to_string(nextId++);
    }

    ~Patron() {}

    bool borrowBook(Book* book) {
        if (!book->getAvailability()) return false;
        if (book->checkOut(id)) {
            borrowedBooks.push_back(book);
            return true;
        }
        return false;
    }

    bool returnBook(Book* book) {
        auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
        if (it != borrowedBooks.end()) {
            if (book->returnBook()) {
                borrowedBooks.erase(it);
                return true;
            }
        }
        return false;
    }

    void addFine(double amount) { fineBalance += amount; }
    void payFine(double amount) { fineBalance = std::max(0.0, fineBalance - amount); }

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name
                  << ", Borrowed: " << borrowedBooks.size()
                  << ", Fine: $" << fineBalance << std::endl;
    }

    std::string getId() const { return id; }
    int getBorrowedCount() const { return borrowedBooks.size(); }
    double getFineBalance() const { return fineBalance; }
};

int Patron::nextId = 1001;

// ---------- Library Class ----------
class Library {
private:
    std::vector<Book*> books;
    std::vector<Patron*> patrons;

public:
    ~Library() {
        for (auto b : books) delete b;
        for (auto p : patrons) delete p;
    }

    void addBook(Book* book) { books.push_back(book); }
    void addPatron(Patron* patron) { patrons.push_back(patron); }

    Book* findBook(const std::string& isbn) {
        for (auto b : books)
            if (b->getISBN() == isbn) return b;
        return nullptr;
    }

    Patron* findPatron(const std::string& id) {
        for (auto p : patrons)
            if (p->getId() == id) return p;
        return nullptr;
    }

    bool checkoutBook(const std::string& isbn, const std::string& patronId) {
        Book* book = findBook(isbn);
        Patron* patron = findPatron(patronId);
        if (!book || !patron) return false;
        return patron->borrowBook(book);
    }

    bool returnBook(const std::string& isbn, const std::string& patronId) {
        Book* book = findBook(isbn);
        Patron* patron = findPatron(patronId);
        if (!book || !patron) return false;
        return patron->returnBook(book);
    }

    void displayAllBooks() const {
        std::cout << "\n--- Library Books ---\n";
        std::cout << std::left << std::setw(12) << "ISBN"
                  << std::setw(25) << "Title"
                  << std::setw(20) << "Author"
                  << "Status" << std::endl;
        std::cout << std::string(70, '-') << std::endl;
        for (const auto& b : books) {
            b->display();
        }
        std::cout << "Total books: " << Book::getTotalBooks() << std::endl;
    }

    void displayAllPatrons() const {
        std::cout << "\n--- Patrons ---\n";
        for (const auto& p : patrons) {
            p->display();
        }
    }
};

// ---------- Main Demo ----------
int main() {
    Library lib;

    // Add books
    lib.addBook(new Book("978-0132350884", "Clean Code", "Robert C. Martin"));
    lib.addBook(new Book("978-0201633610", "Design Patterns", "Erich Gamma"));
    lib.addBook(new Book("978-0321356680", "Effective Java", "Joshua Bloch"));

    // Add patrons
    lib.addPatron(new Patron("Alice Johnson"));
    lib.addPatron(new Patron("Bob Smith"));

    std::cout << "Initial state:\n";
    lib.displayAllBooks();
    lib.displayAllPatrons();

    // Perform some operations
    std::cout << "\n--- Checking out 'Clean Code' to Alice ---\n";
    if (lib.checkoutBook("978-0132350884", "P1001"))
        std::cout << "Checkout successful.\n";
    else
        std::cout << "Checkout failed.\n";

    std::cout << "\n--- Checking out 'Design Patterns' to Bob ---\n";
    lib.checkoutBook("978-0201633610", "P1002");

    lib.displayAllBooks();

    std::cout << "\n--- Returning 'Clean Code' from Alice ---\n";
    if (lib.returnBook("978-0132350884", "P1001"))
        std::cout << "Return successful.\n";
    else
        std::cout << "Return failed.\n";

    lib.displayAllBooks();
    lib.displayAllPatrons();

    return 0;
}
