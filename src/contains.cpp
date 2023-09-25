#include <algorithm>
#include <iostream>
#include <vector>

bool containsVersion(int version) {
  std::vector<int> versions = {98, 03, 11, 14, 17, 20, 23};

  auto it = std::find(versions.begin(), versions.end(), version);

  if (it != versions.end()) {
    return true;
  } else {
    return false;
  }
}
