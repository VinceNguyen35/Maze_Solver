#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

/**Declaration for the Point class*/
class Point
{
	private:
		/**First Coordinate*/
		int x;
		/**Second Coordinate*/
		int y;
	public:
		/**
		Creates a point
		@param int is the first coordinate
		@param int is the second coordinate
		*/
		Point(int, int);
		/**Default point constructor*/
		Point();
		/**
		Gets the x coordinate
		@return returns the x coordinate
		*/
		int getX() { return x; }
		/**
		Gets the y coordinate
		@return returns the y coordinate
		*/
		int getY() { return y; }
};
#endif