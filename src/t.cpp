#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  vector<float> values = {10, 20, 30, 45};
  vector<float> units;
  float max = 45;

  float scale = 5;
  for (float val : values) {
    cout << val << endl;
    int unit = val / scale;
    units.push_back(unit);
  }

  int cutoff = 9;
  while (cutoff > 0) {
    for (float unit : units) {
      // cout << unit << ",";

      if (unit >= cutoff)
        cout << "N ";
      else
        cout << "  ";
    }
    cout << endl;
    cutoff--;
  }
}
