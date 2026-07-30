#include <iostream>
#include <vector>
using namespace std;
class Book{
    private:
    string ISDN;
    string Book_name;
    public:
    Book(string isdn, string name){
        ISDN= isdn;
        Book_name= name;
    }
};
class BookCopy{
    private:
    Book* book;
    int quantity;
    public:
    BookCopy(int q){
        quantity =q;
    }
    
};
class Member{
    private:
    string Name;
    int max_book;
    vector<BookCopy*> books;
    public:
    Member(string n, int maxm){
        Name= n;
        max_book= maxm;
    }
    bool canborrow(){
        if(books.size() < max_book)
        return true;
        return false;
    }
    void borrow(BookCopy* b){
        if(canborrow())
        books.push_back(b);
    }
    void return_book(BookCopy* b){
        for(int i =0;i< books.size();i++){
            if(books[i]==b){
                books.erase(books.begin()+i);
                break;
            }
        }
    }
};
class Inventory{

    vector<BookCopy*> books;

    void add_book(BookCopy* b){
        books.push_back(b);
    }
    
};
class Library{
    Inventory inventory;
    void borrowBook(){

    }

    void returnBook(){

    }

    void searchBook(){

    }

    
};