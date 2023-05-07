// Mustafa
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

// including the header file to import the function declarations
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of string format functions to be used in program written by Mubarak
#include <terminalcancer/terminalcancer.hpp>

#include "histoguzzy.hpp"

float calculateScale(vector<float>& values, int& width) {
  // get the maximum value in values
  float max = getMax(values);

  // initialize variable `scale` to 0
  float scale = 0;

  // increments scale by 10 until max/scale becomes smaller than the width of
  // the terminal
  if (max < width) return 1;
  while (scale == 0 || (max / scale) >= width) {
    // I chose 10 arbitarily
    scale += 5;
  }
  return scale;
};

int calculateNumberOfUnits(float& value, float& scale) {
  // This will get you the number of units needed to represent the value using
  // the given scale
  int units = value / scale;
  return units;
};

string createRect(int width, int bgColor) {
  // declare an empty string to store the string of characters representing the
  // rectangle
  string rect;

  // Add formatting to the string to change its color to bgColor
  rect += colorfmt(fg::black, bgColor);

  // Using a for loop, we increment rect with empty spaces, depending on the
  // width of the rectangle
  for (int x = 0; x < width; x++) rect += " ";

  // Stop the color formatting at the end of the string
  rect += clearfmt;

  // returns the string
  return rect;
};

void addHorizontalBar(string& colHeader, int& units, float& value) {
  // Decorative purposes
  cout << setw(10) << colHeader << " |";

  // Display the bar with width `units`, as well as the value the bar is
  // supposed to represent
  cout << createRect(units) << " " << value << endl;
}

void displayVerticalHistogram(vector<string>& headers, vector<float>& values) {
  // Decorative purposes
  cout << endl;
  cout << colorfmt(fg::green) << "Vertical Histogram" << clearfmt << endl;

  // // Create a bold seperator
  cout << setw(30) << setfill('=') << " " << setfill(' ') << endl;

  // // Setting the height of the Histogram to 200
  auto [width, height] = getTerminalDimensions();
  height = 100;
  // // Calculate the scale to be used in the historgram
  float scale = calculateScale(values, height);
  // // Display the scale of the histogram for reference
  cout << bold << "1 unit = " << scale << clearfmt << endl << endl;

  // // Get the maximum value to calculate the number of units and calibrate the
  // // other values
  float max = getMax(values);
  int cutoff = calculateNumberOfUnits(max, scale) + 5;

  // // For decorative purposes, we set barWidth to 8
  int barWidth = 8;

  // // Creates a blank bar
  cout << createRect(barWidth / 2 + 1, 0) << "+";

  // // This draws a line
  for (int x = 0; x < values.size(); x++) {
    cout << setfill('-') << setw(barWidth) << "-" << setfill(' ');
  }

cout << endl;
  // // This will output the vertical bars, line by line
  // // By setting a variable cutoff...
  float minimum = getMin(values);
  float floor = calculateNumberOfUnits(minimum, scale);
  while (cutoff >= floor - scale) {
    // Decorative purposes
    cout << left << setw(barWidth / 2 + 1) << right << cutoff * scale << "|";
    // Iterates through every value in values

    for (int x = 0; x < values.size(); x++) {
      // Calculates the number of the units for each value using the scale
      int units = calculateNumberOfUnits(values[x], scale);
      // if the number of units needed to represent the bar is bigger than the
      // cutoff point for that y value
      if (units >= cutoff ) {
        // It will output a barlet for that line

        cout << createRect(barWidth);
      } else {
        // Otherwise it will leave the bar blank
        cout << createRect(barWidth, 0);
      }
    }
    cutoff -= scale;
    // Goes to the next line
    cout << endl;
  }

  // // Decorative purposes
  cout << createRect(barWidth / 2 + 1, 0) << "+";

  // // Iterates through every value in values
  for (int x = 0; x < values.size(); x++) {
    // Draws a line
    cout << setfill('-') << setw(barWidth) << "-" << setfill(' ');
  }
  // // Creates a blank rectangle
  cout << endl << createRect(barWidth / 3 + 2, 0);

  // // This will output the Horizontal axis with all the names of bars
  for (int x = 0; x < values.size(); x++) {
    cout  << bold << colorfmt(fg::cyan)
         << setw(barWidth) << headers[x] << clearfmt;
  };
  cout << endl;
}

void displayHorizontalHistogram(vector<string>& headers,
                                vector<float>& values) {
  // Decorative purposes
  cout << endl;
  cout << colorfmt(fg::green) << "Horizontal Histogram" << clearfmt << endl;
  // Draws a line
  cout << setw(30) << setfill('=') << " " << setfill(' ') << endl;

  // Sets the width the graph to 80 characters
  int width = 80;
  // Calculates the scale to be used in the graph
  float scale = calculateScale(values, width);

  // Displays the scale to be used in the graph
  cout << bold << "1 unit = " << scale << clearfmt << endl << endl;

  // Iterates through every value in values..
  for (int x = 0; x < values.size(); x++) {
    // Calculates the number of units needed to display the bar for that value
    int units = calculateNumberOfUnits(values[x], scale);

    // Draws the bar using the number of units
    // Header and the value of that bar are provided for decorative purposes
    addHorizontalBar(headers[x], units, values[x]);
  }
}
