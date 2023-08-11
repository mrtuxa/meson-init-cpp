#include <algorithm>
#include <iostream>
#include <vector>

auto containsVersion(int version) {
  std::vector<int> versions = {98, 03, 11, 14, 17, 20, 23};

  auto it = std::find(versions.begin(), versions.end(), version);

  if (it != versions.end()) {
    return version;
  } else {
    std::cout << "No valid C++ Version, valid C++ versions: 98, 03, 11, 14, "
                 "17, 20, 13"
              << std::endl;
    exit(1);
  }
}
