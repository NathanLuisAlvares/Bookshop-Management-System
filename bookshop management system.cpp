//Bookshop Management System

#include<iostream>
#include<conio.h>
#include<cstring>
#include<iomanip>

using namespace std;

class book
{
	char c;
	
	protected:
	    int *no_of_copies;
	    long double *isbn;
	    float *price;
	    char *bname, *author, *edition, *category, *language;
	
	public:
		book()
		{
			no_of_copies=new int;
			isbn=new long double;
			price=new float;
			bname=new char[50];
			author=new char[30];
			edition=new char[20];
			category=new char[20];
			language=new char[20];
		}
		void add_book()
		{
			cout<<"\n\t\t\t\t\t\t\t\tEnter the following book details:-";
			cout<<"\n\t\t\t\t\t\t\t\tBook name: ";
			fflush(stdin);
			cin.getline(bname,50);
		    cout<<"\t\t\t\t\t\t\t\tAuthor: ";
		    fflush(stdin);
			cin.getline(author,30);
			cout<<"\t\t\t\t\t\t\t\tEdition: ";
			fflush(stdin);
			cin.getline(edition,20);
			cout<<"\t\t\t\t\t\t\t\tCategory: ";
			fflush(stdin);
			cin.getline(category,20);
			cout<<"\t\t\t\t\t\t\t\tLanguage: ";
			fflush(stdin);
			cin.getline(language,20);
			cout<<"\t\t\t\t\t\t\t\tPrice: ";
			fflush(stdin);
			cin>>*price;
			cout<<"\t\t\t\t\t\t\t\tNo. of copies: ";
			fflush(stdin);
			cin>>*no_of_copies;
			cout<<"\t\t\t\t\t\t\t\tISBN: ";
			fflush(stdin);
			cin>>*isbn;
			cout<<endl;
		}
		void modify_book()
		{
			cout<<"\n\t\t\t\t\t\t\t\tEnter the following new book details:-";
			cout<<"\n\t\t\t\t\t\t\t\tBook name: ";
			fflush(stdin);
			cin.getline(bname,50);
		    cout<<"\t\t\t\t\t\t\t\tAuthor: ";
		    fflush(stdin);
			cin.getline(author,30);
			cout<<"\t\t\t\t\t\t\t\tEdition: ";
			fflush(stdin);
			cin.getline(edition,20);
			cout<<"\t\t\t\t\t\t\t\tCategory: ";
			fflush(stdin);
			cin.getline(category,20);
			cout<<"\t\t\t\t\t\t\t\tLanguage: ";
			fflush(stdin);
			cin.getline(language,20);
			cout<<"\t\t\t\t\t\t\t\tPrice: ";
			fflush(stdin);
			cin>>*price;
			cout<<"\t\t\t\t\t\t\t\tNo. of copies: ";
			fflush(stdin);
			cin>>*no_of_copies;
			cout<<"\t\t\t\t\t\t\t\tISBN: ";
			fflush(stdin);
			cin>>*isbn;
			cout<<endl;
		}
		int search_book(char checkbname[], char checkauthor[])
		{
			if(strcmp(checkbname, bname)==0 && strcmp(checkauthor, author)==0)
			return 1;
			else
			return 0;
		}
		void display_book()
		{
			cout<<"\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t\t\t\t\t\t\t                                   BOOK DETAILS                                 "<<endl;
			cout<<"\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t\t\t\t\t\t\t________________________________________________________________________________"<<endl;
			cout<<"\t\t\t\t\t\t\t\t                                                                                "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Book name    : "<<bname<<"                                                 "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Author       : "<<author<<"                                                "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Edition      : "<<edition<<"                                               "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Category     : "<<category<<"                                              "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Language     : "<<language<<"                                              "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Price        : Rs. "<<*price<<"                                            "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     No. of copies: "<<*no_of_copies<<"                                         "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     ISBN         : "<<setprecision(0)<<fixed<<*isbn<<"                         "<<endl;
			cout<<"\t\t\t\t\t\t\t\t________________________________________________________________________________"<<endl<<endl;
		}
};

class item_order: public book
{
	protected:
	    int quantity;
	    float total;
	
	public:
		void reduce_copies()
		{
			*no_of_copies = *no_of_copies - quantity;
		}
		void additem()
		{
			cout<<"\t\t\t\t\t\t\t\tEnter the no. of books the customer wants to buy: ";
			fflush(stdin);
			cin>>quantity;
			if(quantity<=*no_of_copies)
			{
				reduce_copies();
				cout<<"\n\t\t\t\t\t\t\t\tBook(s) bought successfully";
				total=(*price) * quantity;
			}
			else
			cout<<"\n\t\t\t\t\t\t\t\tNot enough copies of the book";
		}
		void display()
		{
			cout<<"\t\t\t\t\t\t\t\t     Quantity     : "<<quantity<<"                                              "<<endl;
			cout<<"\t\t\t\t\t\t\t\t   __________________________________________________________________________   "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Total        : Rs. "<<setprecision(2)<<total<<"                            "<<endl;
		}
};

class customer: public item_order
{
	protected:
		char cname[30];
		long double contactno;
		
	public:
		void getcustomer()
		{
			cout<<"\n\t\t\t\t\t\t\t\tEnter customer name: ";
			fflush(stdin);
			cin.getline(cname,30);
			cout<<"\n\t\t\t\t\t\t\t\tEnter contact no. of customer: ";
			fflush(stdin);
			cin>>contactno;
		}
		void display()
		{
			cout<<"\t\t\t\t\t\t\t\t  Customer name   : "<<cname<<"                                                 "<<endl;
			cout<<"\t\t\t\t\t\t\t\t  Contact no.     : "<<setprecision(0)<<fixed<<contactno<<"                     "<<endl;
		}
};

class bill: public customer
{
	public:
		void display()
		{
			cout<<"\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t\t\t\t\t\t\t                                       BILL                                     "<<endl;
			cout<<"\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t\t\t\t\t\t\t________________________________________________________________________________"<<endl;
			cout<<"\t\t\t\t\t\t\t\t                                                                                "<<endl;
			customer::display();
			cout<<"\t\t\t\t\t\t\t\t                                                                                "<<endl;
			cout<<"\t\t\t\t\t\t\t\t                                   BOOK DETAILS                                 "<<endl;
			cout<<"\t\t\t\t\t\t\t\t   __________________________________________________________________________   "<<endl;
			cout<<"\t\t\t\t\t\t\t\t                                                                                "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Book name    : "<<bname<<"                                                 "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Author       : "<<author<<"                                                "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Edition      : "<<edition<<"                                               "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Category     : "<<category<<"                                              "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Language     : "<<language<<"                                              "<<endl;
			cout<<"\t\t\t\t\t\t\t\t     Price        : Rs. "<<setprecision(2)<<*price<<"                           "<<endl;
			item_order::display();
			cout<<"\t\t\t\t\t\t\t\t________________________________________________________________________________"<<endl;
			cout<<"\t\t\t\t\t\t\t\t==============================THANKS FOR VISITING==============================="<<endl<<endl;
		}
};

int main()
{
	bill *B[50];
	int ch,i=0,t;
	char checkbname[50],checkauthor[30],c;
 	do
 	{
 		cout<<"\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------"<<endl;
	    cout<<"\t\t\t\t\t\t\t\t             '-' WELCOME TO NATHAN's BOOKSHOP MANAGEMENT SYSTEM '-'             "<<endl;
		cout<<"\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t\t\t\t\t\t________________________________________________________________________________"<<endl;
		cout<<"\t\t\t\t\t\t\t\t                                   MAIN MENU                                    "<<endl;
 		cout<<"\t\t\t\t\t\t\t\t________________________________________________________________________________"<<endl;
 		cout<<"\t\t\t\t\t\t\t\t|                                                                              |"<<endl;
  		cout<<"\t\t\t\t\t\t\t\t|         SELECT ONE OF THE FOLLOWING OPERATIONS YOU WANT TO DO:-              |"<<endl;
  		cout<<"\t\t\t\t\t\t\t\t|       1. Add book record                                                     |"<<endl;
  		cout<<"\t\t\t\t\t\t\t\t|       2. Search and display book record                                      |"<<endl;
  		cout<<"\t\t\t\t\t\t\t\t|       3. Modify book record                                                  |"<<endl;
  		cout<<"\t\t\t\t\t\t\t\t|       4. Sell book(s) to customer                                            |"<<endl;
  		cout<<"\t\t\t\t\t\t\t\t|       5. Exit                                                                |"<<endl;
  		cout<<"\t\t\t\t\t\t\t\t|______________________________________________________________________________|"<<endl<<endl;
  		cout<<"\t\t\t\t\t\t\t\tEnter your choice: ";
  		fflush(stdin);
		cin>>ch;
  		switch(ch)
  		{
            case 1: B[i] = new bill;
			        B[i]->add_book();
			        i++;
                    break;
                   
            case 2: cout<<"\t\t\t\t\t\t\t\tEnter name of the book: ";
                    fflush(stdin);
                    cin.getline(checkbname,50);
                    cout<<"\n\t\t\t\t\t\t\t\tEnter author of the book: ";
                    fflush(stdin);
                    cin.getline(checkauthor,30);
                    for(t=0;t<i;t++)
                    {
                    	if(B[t]->search_book(checkbname, checkauthor))
                    	{
                    		cout<<"\n\t\t\t\t\t\t\t\tBook Found Successfully\n";
                    		B[t]->display_book();
                    		break;
						}
					}
					if(t==i)
					cout<<"\n\t\t\t\t\t\t\t\tThis Book is Not in Stock\n";
                    break;
                   
            case 3: cout<<"\t\t\t\t\t\t\t\tEnter name of the book: ";
                    fflush(stdin);
                    cin.getline(checkbname,50);
                    cout<<"\n\t\t\t\t\t\t\t\tEnter author of the book: ";
                    fflush(stdin);
                    cin.getline(checkauthor,30);
                    for(t=0;t<i;t++)
                    {
                    	if(B[t]->search_book(checkbname, checkauthor))
                    	{
                    		cout<<"\n\t\t\t\t\t\t\t\tBook Found Successfully";
                    		B[t]->modify_book();
                    		break;
						}
					}
					if(t==i)
					cout<<"\n\t\t\t\t\t\t\t\tThis Book is Not in Stock\n";
                    break;
                   
            case 4: cout<<"\t\t\t\t\t\t\t\tEnter name of the book: ";
                    fflush(stdin);
                    cin.getline(checkbname,50);
                    cout<<"\n\t\t\t\t\t\t\t\tEnter author of the book: ";
                    fflush(stdin);
                    cin.getline(checkauthor,30);
                    for(t=0;t<i;t++)
                    {
                    	if(B[t]->search_book(checkbname, checkauthor))
                    	{
                    		cout<<"\t\t\t\t\t\t\t\tDoes the customer want to continue buying the book?(Y/N): ";
                    		cin>>c;
                    		if(c=='y'||c=='Y')
                    		{
                    			B[t]->additem();
                    			B[t]->getcustomer();
                    			B[t]->display();
							}
							else
							break;
						}
                    	break;
					}
					if(t==i)
					cout<<"\n\t\t\t\t\t\t\t\tThis Book is Not in Stock\n";
                    break;
			        
			case 5: break;
			
			default: cout<<"\n\t\t\t\t\t\t\t\tWrong choice! Select the ones given in the choice\n";
			        break;
  		}
 	}
	while(ch!=5);
	getch();
	return 0;
}
