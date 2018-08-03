#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void mainMenu();
void input_restricted_dequeue();
void output_restricted_dequeue();
void push_start();
void push_end();
void pop_start();
void pop_end();
void display();

struct node
{
	int data;
	node *link;
}; node *front = NULL, *rear = NULL, *newNode, *current, *temp, *pre;

int dequeue_type = 0;

void main()
{
	mainMenu();

	cout << endl;
	system("pause");
}


void mainMenu()
{
	system("CLS");
	cout << "1. Input Restricted Dequeue\n2. Output Restricted Dequeue\n3. Exit\n\nEnter your choice:\n";
	switch (_getch())
	{
	case '1':
	{
		dequeue_type = 1;
		input_restricted_dequeue();
		break;
	}
	case '2':
	{
		dequeue_type = 2;
		output_restricted_dequeue();
		break;
	}
	case '3':
		exit(0);
	default:
		cout << "\n\aWrong entry!!!";
		break;
	}
}
void input_restricted_dequeue()
{
	system("CLS");
	cout << "1. Insert at end\n2. Delete from start\n3. Delete from end\n4. Display\n5. Select type of Dequeue\n6. Exit\n\nEnter your choice:\n";
	switch (_getch())
	{
	case '1':
		push_end();
		break;
	case '2':
		pop_start();
		break;
	case '3':
		pop_end();
		break;
	case '4':
		display();
		break;
	case '5':
		mainMenu();
		break;
	case '6':
		exit(0);
	default:
		cout << "\n\aWrong entry!!!";
		break;
	}
}
void output_restricted_dequeue()
{
	system("CLS");
	cout << "1. Insert at start\n2. Insert at end\n3. Delete from start\n4. Display\n5. Select type of Dequeue\n6. Exit\n\nEnter your choice:\n";
	switch (_getch())
	{
	case '1':
		push_start();
		break;
	case '2':
		push_end();
		break;
	case '3':
		pop_start();
		break;
	case '4':
		display();
		break;
	case '5':
		mainMenu();
		break;
	case '6':
		exit(0);
	default:
		cout << "\n\aWrong entry!!!";
		break;
	}
}
void push_start()
{
	system("CLS");

	newNode = new node;
	cout << "Enter integer you want to insert: ";
	cin >> newNode->data;
	newNode->link = NULL;

	if (front == NULL)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		newNode->link = front;
		front = newNode;
	}

	cout << "\nItem is successfully inserted in the list!\n";

	cout << "\nNew list:\n";
	current = front;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->link;
	}


	cout << "\n\nPress ENTER to add more or ESCAPE to go back to Main Menu.";
	char ch = _getch();
	if (ch == 13)
		push_start();
	else if (ch == 27)
		output_restricted_dequeue();
	else
		cout << "\n\aWrong entry!!!";
	output_restricted_dequeue();
}
void push_end()
{
	system("CLS");

	newNode = new node;
	cout << "Enter integer you want to insert: ";
	cin >> newNode->data;
	newNode->link = NULL;

	if (front == NULL)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->link = newNode;
		rear = newNode;
	}

	cout << "\nItem is successfully inserted in the list!\n";

	cout << "\nNew list:\n";
	current = front;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->link;
	}


	cout << "\n\nPress ENTER to add more or ESCAPE to go back to Main Menu.";
	char ch = _getch();
	if (ch == 13)
		push_end();
	else if (ch == 27 && dequeue_type == 1)
		input_restricted_dequeue();
	else if (ch == 27 && dequeue_type == 2)
		output_restricted_dequeue();
	else
		cout << "\n\aWrong entry!!!";
}
void pop_start()
{
	system("CLS");
	if (front == NULL)
	{
		cout << "\n\aStack Underflow!";

		cout << "\n\nPress 1 to insert an item or ESCAPE to go back to Main Menu.";

		char ch = _getch();
		if (ch == 1 && dequeue_type == 1)
			push_end();
		else if (ch == 1 && dequeue_type == 2)
			output_restricted_dequeue();
		else if (ch == 27 && dequeue_type == 1)
			input_restricted_dequeue();
		else if (ch == 27 && dequeue_type == 2)
			output_restricted_dequeue();
		else
			cout << "\n\aWrong entry!!!";
	}
	else
	{
		int n = front->data;
		temp = front;
		front = temp->link;
		delete temp;

		cout << "\n" << n << " is successfully deleted from the list!\n";

		cout << "\nNew list:\n";
		current = front;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->link;
		}

		cout << "\n\nPress ENTER to delete more or ESCAPE to go back to Main Menu.";
		char ch = _getch();
		if (ch == 13)
			pop_start();
		else if (ch == 27 && dequeue_type == 1)
			input_restricted_dequeue();
		else if (ch == 27 && dequeue_type == 2)
			output_restricted_dequeue();
		else
			cout << "\n\aWrong entry!!!";
	}
}
void pop_end()
{
	system("CLS");
	if (front == NULL)
	{
		cout << "\n\aStack Underflow!";

		cout << "\n\nPress 1 to insert an item or ESCAPE to go back to Main Menu.";

		char ch = _getch();
		if (ch == 1)
			push_end();
		else if (ch == 27)
			input_restricted_dequeue();
		else
			cout << "\n\aWrong entry!!!";
		input_restricted_dequeue();
	}
	else
	{
		current = front;
		while (current->link != NULL)
		{
			pre = current;
			current = current->link;
		}
		pre->link = NULL;

		int n = front->data;
		temp = front;
		front = pre;
		delete temp;

		cout << "\n" << n << " is successfully deleted from the list!\n";

		cout << "\nNew list:\n";
		current = front;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->link;
		}

		cout << "\n\nPress ENTER to delete more or ESCAPE to go back to Main Menu.";
		char ch = _getch();
		if (ch == 13)
			pop_end();
		else if (ch == 27)
			input_restricted_dequeue();
		else
			cout << "\n\aWrong entry!!!";
		input_restricted_dequeue();

	}
}
void display()
{
	system("CLS");
	if (front == NULL)
	{
		cout << "\n\aList is empty!";

		cout << "\n\nPress 1 to insert an item or ESCAPE to go back to Main Menu.";

		char ch = _getch();
		if (ch == 1 && dequeue_type == 1)
			push_end();
		else if (ch == 1 && dequeue_type == 2)
			output_restricted_dequeue();
		else if (ch == 27 && dequeue_type == 1)
			input_restricted_dequeue();
		else if (ch == 27 && dequeue_type == 2)
			output_restricted_dequeue();
		else
			cout << "\n\aWrong entry!!!";
	}
	else
	{
		cout << "List:\n";
		current = front;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->link;
		}

		cout << "\n\nPress any key to go back to Main Menu.";
		if (_getch() && dequeue_type == 1)
			input_restricted_dequeue();
		else
			output_restricted_dequeue();
	}
}