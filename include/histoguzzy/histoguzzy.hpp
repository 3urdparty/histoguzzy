#ifndef HISTOGUZZY_HPP
#define HISTOGUZZY_HPP

#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <string>
#include <vector>

using namespace std;

/// @brief takes a vector of floats `values` as well as the width of the terminal, and returns a float value representing the scale of one unit in the histrogram
/// @param values 
/// @param width 
/// @return a float value representing the scale of one unit in the histogram
float calculateScale(vector<float>& values, int& width);

/// @brief takes a float `value` and float `scale` and calcualtes the number of units that shuold be used to represent the value
/// @param value 
/// @param scale 
/// @return  returns an int representing the number of units used to represent a value
int calculateNumberOfUnits(float& value, float& scale);


/// @brief takes int `width` and int `bgColor`
/// @param width Width of the rectangle
/// @param bgColor Color of the rectangle
/// @return a string representing Unicode symbols that resemble a rectangle
string createRect(int width, int bgColor = bg::white);


/// @brief takes the header for the bar, an int number of units and a float value, representing the value that the bar represents
/// @param colHeader The name of the bar
/// @param units The number of units used to make the bar
/// @param value The value represented by the bar
void addHorizontalBar(string& colHeader, int& units, float& value);


/// @brief Takes a list of strings `headers` and displays a vertical histogram using the vector of floats `values`
/// @param headers 
/// @param values 
void displayVerticalHistogram(vector<string>& headers, vector<float>& values);

/// @brief Takes a list of strings `headers` and displays a horizontal histogram using the vector of floats `values`
/// @param headers 
/// @param values 
void displayHorizontalHistogram(vector<string>& headers, vector<float>& values);


#endif
