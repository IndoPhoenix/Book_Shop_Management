#include<bits/stdc++.h>

using namespace std;

class book{
    public:
string author;
string title;
int price;
string publisher;
int stock;

    book(string author, string title, string publisher, int price = 0, int stock = 0){
        this->author = author;
        this->title = title;
        this->publisher = publisher;
        this->price = price;
        this->stock = stock;
    }


};

class books{
    private:
     int successful_transaction = 0;
     int unsuccessful_transaction = 0;
    vector<book*>list;
    public:

        void addbooks(string author, string title, string publisher, int price = 0, int stock = 0){
            book*item = new book(author, title, publisher, price, stock);
            list.push_back(item);
        }
        void searchbook(string title, string author){
            bool found = false;
            for(book* ptr : list){
                if(ptr->author == author && ptr->title == title ){
                    found = true;
                    int required;
                    cout<<"The book "<<title<<" is available"<<endl;
                    cout<<"_________________________________"<<endl;
                    cout<<"________________Book details_________________: "<<endl;
                    cout<<"title: "<<ptr->title<<endl;
                    cout<<"author: "<<ptr->author<<endl;
                    cout<<"publisher: "<<ptr->publisher<<endl;
                    cout<<"price: "<<ptr->price<<endl;
                    cout<<"_____________________________________"<<endl<<endl;
                    cout<<"Enter the number of copies required: "; cin>>required;
                    if(required <= ptr->stock){
                        string x;
                        cout<<"The requested amount of copies are available"<<endl;
                        cout<<"___________________________________________________________"<<endl;
                        cout<<"'Total cost : "<<(ptr->price)*required << "rupees"<<endl;
                        cout<<"_________________________________________________________"<<endl;
                        cout<<"Do you want to buy ? (y/n)";
                        cin>>x;
                        if(x == "y" || x == "Y" || x == "Yes" || x == "YES" || x == "yes"){
                            buyBooks(ptr, required);
                        }
                        else{
                            unsuccessful_transaction += 1;
                            cout<<" Transaction failed "<<endl;
                        }

                    }
                    else{
                        cout<<"Sorry the Requested amount of coies are not available.";
                    }
                    
                }
            }
            if(!found){
                cout<<"Sorry this book is not available"<<endl;
            }
        }

        void buyBooks(book*ptr, int stock){
            ptr->stock -= stock;
            cout<<"Tranasaction of rupees "<<stock*(ptr->price)<<" succesfull"<<endl;
            this->successful_transaction += 1;
        }

        void updatePrice(string title, string author){
                bool found = false;
                for(book* ptr : list){
                    if(ptr->author == author && ptr->title == title){
                        int newprice;
                         cout<<"________________Book details_________________: "<<endl;
                    cout<<"title: "<<ptr->title<<endl;
                    cout<<"author: "<<ptr->author<<endl;
                    cout<<"publisher: "<<ptr->publisher<<endl;
                    cout<<"price: "<<ptr->price<<endl;
                    cout<<"__________________________________"<<endl;
                    cout<<"Enter the new price: ";cin>>newprice;
                    ptr->price = newprice;
                    cout<<"Book price updated";
                    }
                }
        }

        void transactionHistory(){
            cout<<"_________________Transaction History_________________"<<endl;
            cout<<"Successfull Transactions: "<<successful_transaction<<endl;
            cout<<"Unsuccesfull Transactions: "<<unsuccessful_transaction<<endl;
            cout<<"__________________________________________________________";
        }

};

void menu(){
    cout<<endl;
    cout<<"1 .Buy or Search Book"<<endl;
    cout<<"2. Update Book Price"<<endl;
    cout<<"3. Add a Book"<<endl;
    cout<<"4. Transaction History"<<endl;
    cout<<"5. Print Menu Again"<<endl;
}

int main() {



books n;
cout<<"_________________________Ramanshu Digital Book Shop_________________________";
menu();
while(true){
int x;
cout<<"Enter option number: ";cin>>x;
if(x == 1){
string title;
string author;
cout<<"Enter Book Title: ";cin>>title;
cout<<"Enter Author Name: ";cin>>author;
n.searchbook(title, author);
cout<<endl;
}
else if( x== 2){
string title;
string author;
cout<<"Enter Book Title: ";cin>>title;
cout<<"Enter Author Name : ";cin>>author;
n.updatePrice(title, author);
cout<<endl;
}
else if(x == 3){
string title;
string author;
int price;
string publisher;
int stock;

cout<<"Enter Book Title: ";cin>>title;
cout<<"Enter Author Name: ";cin>>author;
cout<<"Enter publisher name: ";cin>>publisher;
cout<<"Enter Book Price: ";cin>>price;
cout<<"Enter Book Stock: ";cin>>stock;

n.addbooks(author, title, publisher , price, stock);
cout<<endl;
}
else if(x == 4){
    n.transactionHistory();
    cout<<endl;
}
else if(x == 5){
cout<<"________________________________________"<<endl;
menu();

cout<<"__________________________________________"<<endl;

cout<<endl;
}
}


return 0;

}