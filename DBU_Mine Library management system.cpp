//to enter as an admin please use the password 1234

#include <iostream>
#include<windows.h>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
int num;
struct book
{
	string book_title;
	string author;
	string publisher;
	string book_id;
	book *pre, *next;
};

book *start = NULL, *last = NULL, *temp, *temp2, *temp3;
void intro();
void users();
void admi_pass();
void user();
void home();
void insert_book();
void insert_at_biginning(); 
void insert_at_end();
void delete_book();
void delete_beginning();
void delete_end();
void delete_search();
void developers(int num);
// Function display a loding
void intro()
{
	cout << "\n\n\n\n\n\n\n\n\n";
	int x(219);
	cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t" << "LOADING ";
	for(int j = 1; j <= 50; j++)
	{
		cout << char(x);
		Sleep(14);
	}
	system("cls");
	home();
}
// Function display a home
void home()
{
	system("color 3E");
	int key;
	cout << "\n\n\n\n";
	cout << "\t\t\t LOGIN AS " << endl;
	cout << "\t\t\t<1> AS ADMIN \n";
	cout << "\t\t\t<2> AS USER \n";
	cout << "\t\t\t PRESS ANY KEY TO EXIT FROM THE SYSTRM \n";
	cout << "\t\t\t ENTER YOUR CHOICE: ";
	cin >> key;
	switch(key)
	{
	case 1:
		system("cls");
		admi_pass();
		break;
	case 2:
		system("cls");
		user();
		break;
	case 3:
		cin.ignore();
		cin.get();
		system("cls");
		break;
	}
}
// Function for admi UI
void admi_pass()
{
	int password, count = 0;
	cout << "\n\n\n\n";
	while(count < 3)
	{
		cout << "\t\t\t ENTER YOUR PASSWORD: ";
		cin >> password;
		if(password == 1234)
		{
			system("cls");
			int choice;
			cout << "\n\n\n\n";
			cout << "\t\t\t PLEASE ENTER YOUR CHOOSE" << endl;
			cout << "\t\t\t<1> TO INSERT A BOOK \n";
			cout << "\t\t\t<2> TO SHOW THE BOOKES \n";
			cout << "\t\t\t<3> TO DELET A BOOK \n";
			cout << "\t\t\t<4> TO SORT A BOOK \n";
			cout << "\t\t\t<5> ABOUT DEVELOPERS \n";
			cout << "\t\t\t<6> TO Exit \n";
			cout << "\n ENTER YOUR CHOICE: ";
			cin >> choice;
			switch(choice)
			{
			case 1:
				system("cls");
				insert_book();
				break;
			case 2:
				system("cls");
				display_book(1);
				break;
			case 3:
				system("cls");
				delete_book();
				break;
			case 4:
				system("cls");
				sortBooks();
				break;
			case 5:
				system("cls");
				developers(1);
				break;
			case 6:
				cin.ignore();
				cin.get();
				system("cls");
				home();
			}
		}
		else
		{
			system("cls");
			cout << "\n\t\t\t WRONG PASWORD PLEASE TRY AGAIN \n";
			count++;
		}
	}
	if(count == 3)
	{
		cout << "\n\t\t\t YOU REACHED THE MAXIMUM ATEMPET COME BACK LATER \n";
		cout << "\n\t\t\tPress anykey to go into previous screen.\n";
		cin.ignore();
		cin.get();
		system("cls");
		home();
	}
}
// Function display a UI
void user()
{
	int choice;
	cout << "\n\n\n\n";
	cout << "\t\t\t PLEASE ENTER YOUR CHOOSE" << endl;
	cout << "\t\t\t<1> TO SHOW THE BOOKES \n";
	cout << "\t\t\t<2> ABOUT DEVELOPERS \n";
	cout << "\t\t\t<3> TO Exit \n";
	cout << "\n ENTER YOUR CHOICE: ";
	cin >> choice;
	switch(choice)
	{
	case 1:
		system("cls");
		display_book(2);
		break;
	case 2:
		system("cls");
		developers(2);
		break;
	case 3:
		cin.ignore();
		cin.get();
		system("cls");
		break;
	}
}
// Function display a insert main
void insert_book()
{
	int choice;
	cout << "\n\n";
	cout << "\t\t<1> TO INSERT A BOOKS AT THE BIGINNING. \n";
	cout << "\t\t<2> TO INSERT A BOOKS AT THE END. \n";
	cout << "\t\t<3> TO RETERN INTO THE PREVIOUSE PAGE \n";
	cout << "\n ENTER YOUR CHOICE: ";
	cin >> choice;
	switch(choice)
	{
	case 1:
		system("cls");
		insert_at_biginning();
		break;
	case 2:
		system("cls");
		insert_at_end();
		break;
	case 3:
		cin.ignore();
		cin.get();
		system("cls");
		admi_pass();
		break;
	}

}
// Function to insert a book at beginning
void insert_at_biginning()
{
	temp = new book;
	temp->next = NULL;
	temp->pre = NULL;
	cout << "ENTERE THE BOOK TITEL: ";
	cin >> temp->book_title;
	cout << "ENTERE THE NAME OF AUTHOR OF THE BOOK: ";
	cin >> temp->author;
	cout << "ENTERE THE PUPLISHER OF THE BOOK: ";
	cin >> temp->publisher;
	cout << "ENTERE THE BOOK ID: ";
	cin >> temp->book_id;
	if(start == NULL )
	{

		start = temp;
		last = temp;
	}

	else
	{
		temp->next = start;
		start->pre = temp;
		start = temp;
	}
	cout << "\n\t\tTHE BOOK INFORMATION IS SAVED SUCCESSFULLY \n";
	cout << "\n\t\tPress anykey to go into previous screen.\n";
	cin.ignore();
	cin.get();
	system("cls");
	insert_book();

}
// Function to delete a at the beginning
void delete_beginning()
{
	if(start == NULL)
		cout << "the list is empty \n";
	else
	{
		temp = start;
		start = start->next;
		start->pre = NULL;
		cout << temp->book_title << " deleted successfully!! \n";
		delete temp;
	}
	cout << "\n\t\tPress anykey to go into previous screen.\n";
	cin.ignore();
	cin.get();
	system("cls");
	delete_book();
}
// Function to delete a at the end
void delete_end()
{
	if(last == NULL)
		cout << "\n\n\tthe list is empty \n";
	else
	{
		temp = last;
		last = last->pre;
		last->next = NULL;
		cout << "\n\n\t" << temp->book_title << " deleted successfully!! \n\n";
		delete temp;
	}
	cout << "\n\t\tPress anykey to go into previous screen.\n";
	cin.ignore();
	cin.get();
	system("cls");
	delete_book();
}
// Function to delete a spcfic book
void delete_search()
{
	if(start == NULL)
		cout << "\n\n\tthe list is empty /n";
	else
	{
		string ID;
		temp = start;
		cout << "\n\n\tENTERE THE BOOK ID: ";
		cin >> ID;
		while(temp != NULL)
		{
			if(temp->book_id == ID)
			{
				if(start == last)
				{
					start = last = NULL;
					cout << "\n\n\t" << temp->book_title << " deleted successfully!! \n";
					delete temp;
				}
				else if(temp == start)
				{
					start = temp->next;
					start->pre = NULL;
					cout << "\n\n\t" << temp->book_title << " deleted successfully!! \n";
					delete temp;
				}
				else if(temp == last)
				{
					last = temp->pre;
					last->next = NULL;
					cout << "\n\n\t" << temp->book_title << " deleted successfully!! \n";
					delete temp;
				}
				else
				{
					temp2 = temp->pre;
					temp2->next = temp->next;
					temp3 = temp->next;
					temp3->pre = temp->pre;
					cout << "\n\n\t" << temp->book_title << " deleted successfully!! \n";
					delete temp;
				}
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	cout << "\n\t\tPress anykey to go into previous screen.\n";
	cin.ignore();
	cin.get();
	system("cls");
	delete_book();
}

// Function to display the group members
void developers(int num)
{
	cout << "---------------------------------------" << endl;
	cout << "NAME             |F_NAME        | ID        " << endl;
	cout << "----------------------------------------" << endl << endl;
	cout << "AMANUL 		 MENGISTU                  " << endl;
	cout << "BEMNET           WESLEY          0597/13           " << endl;
	cout << "BINYAM           DAMENE          0500/13   " << endl;
	cout << "DABI             HAILE           2054/13 " << endl;
	cout << "EPHREME          TILAHUNE        0094/13" << endl;
	cout << "ESMELEALEM 	 BERHANU         1180/13" << endl;
	cout << "Press anykey to go into home screen.";
	cin.ignore();
	cin.get();
	system("cls");
	if(num == 1)
		admi_pass();
	else
		user();

}

int main()
{

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t             WELCOME";
	Sleep(700);
	cout << " TO ";
	Sleep(700);
	cout << "THIS LIBRARY";
	Sleep(700);
	cout << " MANAGMENT SYSTEM. \n\n";
	Sleep(700);
	cout << "\t\t\t\t\t\t\t\t\t         Please press any key to continue...\n";
	cin.get();
	intro();
	return 0;
}
