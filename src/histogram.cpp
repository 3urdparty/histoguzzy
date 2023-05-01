#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "histogram.hpp"

#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>

float calculateScale(vector<float>& values, int& width) {
  float max = getMax(values);
  float scale = 0;
  while (scale == 0 || (max / scale) >= width) {
    scale += 10;
  }
  return scale;
};

int calculateNumberOfUnits(float& value, float& scale) {
  int units = value / scale;
  return units;
};

string createRect(int width, int bgColor) {
  string rect;
  rect += colorfmt(fg::black, bgColor);
  for (int x = 0; x < width; x++) rect += " ";
  rect += clearfmt;
  return rect;
};

void addHorizontalBar(string& colHeader, int& units, float& value) {
  cout << setw(10) << colHeader << " |";
  cout << createRect(units) << " " << value << endl;
}

void displayVerticalHistogram(vector<string>& headers, vector<float>& values) {
  cout << endl;
  cout << colorfmt(fg::green) << "Vertical Histogram" << clearfmt << endl;
  cout << setw(30) << setfill('=') << " " << setfill(' ') << endl;

  int height = 200;
  float scale = calculateScale(values, height);

  cout << bold << "1 unit = " << scale << clearfmt << endl << endl;

  float max = getMax(values);
  int cutoff = calculateNumberOfUnits(max, scale) + 5;

  int barWidth = 8;

  cout << createRect(barWidth / 2 + 1, 0) << "+";
  for (int x = 0; x < values.size() ; x++) {
    cout << setfill('-') << setw(barWidth) << "-" << setfill(' ');
  }
cout << endl;
  while (cutoff > 10) {
    cout  << left << setw(barWidth / 2 +1) << right << cutoff*scale << "| ";
    for (int x = 0; x < values.size(); x++) {
      int units = calculateNumberOfUnits(values[x], scale);

      if (units >= cutoff) {
        cout << createRect(barWidth);
      } else {
        cout << createRect(barWidth, 0);
      }
      cutoff -= 1 / scale;
      // addVerticalBar(headers[x], units, values[x]);
    }
    cout << endl;
  }

  cout << createRect(barWidth / 2 + 1, 0) << "+";
  for (int x = 0; x < values.size() ; x++) {
    cout << setfill('-') << setw(barWidth) << "-" << setfill(' ');
  }
  cout << endl << createRect(barWidth / 3 + 2, 0);

  for (int x = 0; x < values.size() ; x++) {
    cout << createRect(barWidth / 2, 0)  << bold << colorfmt(fg::cyan)
         << setw(barWidth / 2) << headers[x] << clearfmt;
  };
  cout << endl;
}

void displayHorizontalHistogram(vector<string>& headers,
                                vector<float>& values) {
  cout << endl;
  cout << colorfmt(fg::green) << "Horizontal Histogram" << clearfmt << endl;
  cout << setw(30) << setfill('=') << " " << setfill(' ') << endl;

  int width = 80;
  float scale = calculateScale(values, width);

  cout << bold << "1 unit = " << scale << clearfmt << endl << endl;
  for (int x = 0; x < values.size(); x++) {
    int units = calculateNumberOfUnits(values[x], scale);
    addHorizontalBar(headers[x], units, values[x]);
  }
}

