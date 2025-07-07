#include <iostream>
#include <vector>
#include <cmath>
#include <string>


using namespace std;


struct Book{
    int I_D;
    string Title;
    string Author;
    bool Is_borrow;


         Book(int Book_ID, string Book_Title, string Book_Author) {
            I_D = Book_ID;
            Title = Book_Title;
            Book_Author = Book_Author;
            Is_borrow =false;
       }
   };

 class Library{
   private:
        vector<Book> books;
        int next_id;

   public:
       Library(){
       next_id =1;
       }


  // Adding a new book
       void Add_Book(string title, string author){

       books.push_back(Book(next_id,title,author));
       cout<<"Book Succeefully Added with ID: "<<next_id<<endl;
       next_id++;

       }
// displaying all books
void Display_Books(){
                    if (books.empty()){
                         cout<<"no available books \n";
                         return;
                    }
                else{
                   cout<<"All available books"<<endl;
                          for(Book &availableBooks : books )
                          {
                                  cout<<" Book ID: "<<availableBooks.I_D<<" ,Book title: "<<availableBooks.Title<<" ,Author: "<<availableBooks.Author<<" ,status: "<<(availableBooks.Is_borrow ? "Borrowed" : "Available")<<endl;
                          }
                }
                }
 // search book by title
                void searchBook(string keyword){
                   bool found = false;
                   for (Book & availableBooks : books){
                        if(availableBooks.Title.find(keyword) != string::npos){
                            cout<<" Book ID: "<<availableBooks.I_D<<" ,Book title: "<<availableBooks.Title<<" ,Author: "<<availableBooks.Author<<endl;
                            found = true;
                        }
                   }
                   if (!found){
                       cout<<"No book found with title containing: "<<keyword<<endl;
                   }

                }

          void BorrowBook(int borrowID){
                        for (Book &availableBooks : books){

                            if (availableBooks.I_D = borrowID){
                               if (availableBooks.Is_borrow){
                                  cout<<"Book is already borrowed"<<endl;
                               }
                               else {
                                availableBooks.Is_borrow =true;
                                cout<<"The book is borrowed succeessfully"<<endl;
                               }
                               return;
                            }
                        }
                        cout<<"Book with Id: "<<borrowID<<"not found \n"<<endl;
             }

             void ReturnBook( int returnBookID){

                 for (Book &availableBooks : books){
                    if(availableBooks.I_D == returnBookID){
                         if (!availableBooks.Is_borrow){
                                  cout<<"book is not borowed"<<endl;
                         }
                         else {
                               availableBooks.Is_borrow = false;
                               cout<<"book return successfully"<<endl;
                         }
                         return;
                    }
                 }

                 cout<<"Book with ID: "<<returnBookID<<"not found \n";
             }
 };



int main()
{
      Library BookLibrary;

int choice;


        while(true){

              cout<<"Welcome"<<endl;
              cout<<"1.Add Book"<<endl;
              cout<<"2.Display all books"<<endl;
              cout<<"3.Search Book bt title "<<endl;
              cout<<"4.Borrowed a Book with Id"<<endl;
              cout<<"5.Return a Book with ID "<<endl;
              cout<<"6.Exit"<<endl;
              cout<<"enter ur choice: ";
              cin>>choice;

              // clear buffer or terminal
              if(cin.fail()){
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cout<<"invalid input"<<endl;
                continue;
              }



              if (choice == 1){
                   string author;
                   string title;
                  cin.ignore();
                  cout<<"enter title: ";
                  getline(cin,title);

                  cout<<"enter author: ";
                  getline(cin,author);
                  BookLibrary.Add_Book(title,author);
              }

              else if (choice == 2)
              {
                  BookLibrary.Display_Books();

              }
              else if (choice == 3){
                    string keyword;
                    cin.ignore();
                    cout<<"Enter the title to serach the book: ";
                    getline(cin,keyword);
                    BookLibrary.searchBook(keyword);
              }
              else if (choice == 4){
                     int BorrowID;
                     cout<<"Borrow a book with book id: ";
                     cin>>BorrowID;
                     BookLibrary.BorrowBook(BorrowID);

              }
              else if (choice == 5){
                  int return_ID;
                  cout<<"Return a book with Id: "<<endl;
                  cin>>return_ID;
                  BookLibrary.ReturnBook(return_ID);

              }
              else if (choice==6){
                cout<<"exit"<<endl;
                break;
              }
              else {
                cout<<"invalid option"<<endl;
              }
   }

    return 0;
}
