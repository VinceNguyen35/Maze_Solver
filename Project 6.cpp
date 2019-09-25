// Project 6.cpp : Defines the entry point for the console application.
//

#include "Point.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <stdio.h>

/**
Displays the 2D array
@param int rows is the number of x coordinates
@param int cols is the number of y coordinates
@param char** &array is the 2D dynamic array
*/
void printMaze(int rows, int cols, char** &array)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j];
		}
		cout << endl;
	}
}

/**
Checks that the user's input is valid for the Maze option
@param int &num is the number being checked
*/
void inputValMazeOption(int &num)
{
	while (true)
	{
		if (cin >> num)
		{
			if (num >= 1 && num <= 4)
			{
				break;
			}
			else
			{
				cout << "Invalid Input" << endl;
			}
		}
		else
		{
			cin.clear(); //clear out invalid input
			string invalid;
			cin >> invalid;
			cout << "Invalid Input" << endl;
		}
	}
}

/**
Validates the user's input for the search option
@param int &num is the number being checked
*/
void inputValSearchOption(int &num)
{
	while (true)
	{
		if (cin >> num)
		{
			if (num >= 1 && num <= 3)
			{
				break;
			}
			else
			{
				cout << "Invalid Input" << endl;
			}
		}
		else
		{
			cin.clear(); //clear out invalid input
			string invalid;
			cin >> invalid;
			cout << "Invalid Input" << endl;
		}
	}
}

/**
Checks to see if the user used a valid input while solving the maze
@param int &num is the number being checked
*/
void inputValUserOption(int &num)
{
	while (true)
	{
		if (cin >> num)
		{
			if (num >= 1 && num <= 5)
			{
				break;
			}
			else
			{
				cout << "Invalid Input" << endl;
			}
		}
		else
		{
			cin.clear(); //clear out invalid input
			string invalid;
			cin >> invalid;
			cout << "Invalid Input" << endl;
		}
	}
}

/**
Reads the first 2 numbers of the text file to determine the size of the dynamic array
@param int input is the maze file to be used
@param int &rows is the row size of the array
@param int &cols is the column size of the array
*/
void readArrayDimensions(int input, int &rows, int &cols)
{
	fstream file;
	if (input == 1)
	{
		file.open("Maze-Level1.txt", ios::in);
		if (file)
		{
			file >> rows;
			file >> cols;
		}
	}
	if (input == 2)
	{
		file.open("Maze-Level2.txt", ios::in);
		if (file)
		{
			file >> rows;
			file >> cols;
		}
		file.close();
	}
	if (input == 3)
	{
		file.open("Maze-Level3.txt", ios::in);
		if (file)
		{
			file >> rows;
			file >> cols;
		}
		file.close();
	}
	if (input == 4)
	{
		file.open("Maze-Level4.txt", ios::in);
		if (file)
		{
			file >> rows;
			file >> cols;
		}
		file.close();
	}
}

/**
Reads the rest of the text file after creating the dynamic array
@param int input is the maze file to be used
@param int rows is the row size of the array
@param int cols is the column size of the array
@param char** &array is the dynamic 2D array
*/
void readFile(int input, int rows, int cols, char** &array)
{
	fstream file;
	string readString;
	if (input == 1)
	{
		file.open("Maze-Level1.txt", ios::in);
		getline(file, readString);
		readString.clear();
		for (int i = 0; i < rows; i++)
		{
			getline(file, readString);
			for (int j = 0; j < cols; j++)
			{
				array[i][j] = readString[j];
			}
		}
		file.close();
	}
	if (input == 2)
	{
		file.open("Maze-Level2.txt", ios::in);
		getline(file, readString);
		readString.clear();
		for (int i = 0; i < rows; i++)
		{
			getline(file, readString);
			for (int j = 0; j < cols; j++)
			{
				array[i][j] = readString[j];
			}
		}
		file.close();
	}
	if (input == 3)
	{
		file.open("Maze-Level3.txt", ios::in);
		getline(file, readString);
		readString.clear();
		for (int i = 0; i < rows; i++)
		{
			getline(file, readString);
			for (int j = 0; j < cols; j++)
			{
				array[i][j] = readString[j];
			}
		}
		file.close();
	}
	if (input == 4)
	{
		file.open("Maze-Level4.txt", ios::in);
		getline(file, readString);
		readString.clear();
		for (int i = 0; i < rows; i++)
		{
			getline(file, readString);
			for (int j = 0; j < cols; j++)
			{
				array[i][j] = readString[j];
			}
		}
		file.close();
	}
}

/**
Solves the maze with a stack algorithm
@param int rows is the row size of the array
@param int cols is the column size of the array
@param char** &array is the 2D dynamic array
@param Point &start is the starting point of the maze
*/
void DFS(int rows, int cols, char** &array, Point &start)
{
	stack <Point> values;

	values.push(start);
	bool maze = true;
	while (maze)
	{
		Point reference = values.top();
		if (array[reference.getX()][reference.getY()] == 'f')
		{
			array[values.top().getX()][values.top().getY()] = 's';
			break;
		}
		else
		{
			array[values.top().getX()][values.top().getY()] = 's';
			values.pop();
			array[reference.getX()][reference.getY()] = '.';
			if (array[reference.getX() - 1][reference.getY()] != '*' && array[reference.getX() - 1][reference.getY()] != '.')
			{
				values.push(Point (reference.getX() - 1, reference.getY()));
			}
			if (array[reference.getX() + 1][reference.getY()] != '*' && array[reference.getX() + 1][reference.getY()] != '.')
			{
				values.push(Point (reference.getX() + 1, reference.getY()));
			}
			if (array[reference.getX()][reference.getY() - 1] != '*' && array[reference.getX()][reference.getY() - 1] != '.')
			{
				values.push(Point (reference.getX(), reference.getY() - 1));
			}
			if (array[reference.getX()][reference.getY() + 1] != '*' && array[reference.getX()][reference.getY() + 1] != '.')
			{
				values.push(Point (reference.getX(), reference.getY() + 1));
			}
		}
		
		reference = values.top();

	}
	printMaze(rows, cols, array);
}

/**
Solves the maze using a queue algorithm
@param int rows is the row size of the array
@param int cols is the column size of the array
@param char** &array is the 2D dynamic array
@param Point &start is the starting point of the maze
*/
void BFS(int rows, int cols, char** &array, Point &start)
{
	queue <Point> values;
	
	values.push(start);
	bool maze = true;
	while (maze)
	{
		Point reference = values.front();
		if (array[reference.getX()][reference.getY()] == 'f')
		{
			array[values.front().getX()][values.front().getY()] = 's';
			break;
		}
		else
		{
			array[values.front().getX()][values.front().getY()] = 's';
			values.pop();
			array[reference.getX()][reference.getY()] = '.';
			if (array[reference.getX() - 1][reference.getY()] != '*' && array[reference.getX() - 1][reference.getY()] != '.')
			{
				values.push(Point(reference.getX() - 1, reference.getY()));
			}
			if (array[reference.getX() + 1][reference.getY()] != '*' && array[reference.getX() + 1][reference.getY()] != '.')
			{
				values.push(Point(reference.getX() + 1, reference.getY()));
			}
			if (array[reference.getX()][reference.getY() - 1] != '*' && array[reference.getX()][reference.getY() - 1] != '.')
			{
				values.push(Point(reference.getX(), reference.getY() - 1));
			}
			if (array[reference.getX()][reference.getY() + 1] != '*' && array[reference.getX()][reference.getY() + 1] != '.')
			{
				values.push(Point(reference.getX(), reference.getY() + 1));
			}
		}
		reference = values.front();
	}
	printMaze(rows, cols, array);
}

/**
Allows the user to solve the maze themselves.  Uses DFS if the user fails to solve the maze.
@param int rows is the row size of the array
@param int cols is the column size of the array
@param char** &array is the 2D dynamic array
@param Point &start is the starting point of the maze
*/
void solveMyself(int rows, int cols, char** &array, Point &start)
{
	bool user = true;
	while (user)
	{
		if (array[start.getX()][start.getY()] == 'f')
		{
			array[start.getX()][start.getY()] = 's';
			cout << "Congratulations!  You solved the maze!" << endl;
			break;
		}

		printMaze(rows, cols, array);
		cout << "Choose an option:" << endl;
		cout << "1. Move up" << endl;
		cout << "2. Move down" << endl;
		cout << "3. Move left" << endl;
		cout << "4. Move right" << endl;
		cout << "5. Solve this for me" << endl;

		int userOption;
		inputValUserOption(userOption);

		if (userOption == 1)
		{
			if (array[start.getY()][start.getX() - 1] != '*')
			{
				array[start.getY()][start.getX()] = '.';
				start = Point(start.getY(), start.getX() - 1);
				array[start.getY()][start.getX()] = 's';
			}
			else
			{
				cout << "Can't go there." << endl;
			}
		}
		if (userOption == 2)
		{
			if (array[start.getY()][start.getX() + 1] != '*')
			{
				array[start.getY()][start.getX()] = '.';
				start = Point(start.getY(), start.getX() + 1);
				array[start.getY()][start.getX()] = 's';
			}
			else
			{
				cout << "Can't go there." << endl;
			}
		}
		if (userOption == 3)
		{
			if (array[start.getY() - 1][start.getX()] != '*')
			{
				array[start.getY()][start.getX()] = '.';
				start = Point(start.getY() - 1, start.getX());
				array[start.getY()][start.getX()] = 's';
			}
			else
			{
				cout << "Can't go there." << endl;
			}
		}
		if (userOption == 4)
		{
			if (array[start.getY() + 1][start.getX()] != '*')
			{
				array[start.getY()][start.getX()] = '.';
				start = Point(start.getY() + 1, start.getX());
				array[start.getY()][start.getX()] = 's';
			}
			else
			{
				cout << "Can't go there." << endl;
			}
		}
		if (userOption == 5)
		{
			DFS(rows, cols, array, start);
			break;
		}
	}
}

/**
Main function of the file
@return int the end of the program
*/
int main()
{
	int rows = 0;
	int cols = 0;
	bool menu = true;
	while (menu)
	{
		int mazeOption;
		cout << "Choose a Maze Level:" << endl;
		cout << "1. Maze 1" << endl;
		cout << "2. Maze 2" << endl;
		cout << "3. Maze 3" << endl;
		cout << "4. Maze 4" << endl;
		inputValMazeOption(mazeOption);

		readArrayDimensions(mazeOption, rows, cols);

		char **array;
		array = new char*[rows];
		for (int i = 0; i < rows; i++)
		{
			array[i] = new char[cols];
		}

		readFile(mazeOption, rows, cols, array);

		printMaze(rows, cols, array);

		cout << "How would you like to solve this maze?" << endl;
		cout << "1. Depth First Search (use a stack)" << endl;
		cout << "2. Breadth First Search (use a queue)" << endl;
		cout << "3. I can solve this myself" << endl;
		int searchOption;
		inputValSearchOption(searchOption);

		if (searchOption == 1)
		{
			Point start;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (array[i][j] == 's')
					{
						start = Point(i, j);
					}
				}
			}
			DFS(rows, cols, array, start);
		}
		if (searchOption == 2)
		{
			Point start;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (array[i][j] == 's')
					{
						start = Point(i, j);
					}
				}
			}
			BFS(rows, cols, array, start);
		}
		if (searchOption == 3)
		{
			Point start;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (array[i][j] == 's')
					{
						start = Point(i, j);
					}
				}
			}
			solveMyself(rows, cols, array, start);
		}
	}
	cin.get(); //stops the program to see the final result
	return 0;
}