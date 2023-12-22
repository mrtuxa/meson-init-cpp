#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
bool containsVersion(std::string version) {
  std::vector<std::string> versions = {"98", "03", "11", "14", "17", "20", "23"};

  auto it = std::find(versions.begin(), versions.end(), version);

  if (it != versions.end()) {
    return true;
  } else {
    return false;
  } 
}
