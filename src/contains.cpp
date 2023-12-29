#include <algorithm>
#include <string_view>
bool containsVersion(const std::string_view &version) {
  const auto versions = {"98", "03", "11", "14", "17", "20", "23"};
  return std::find(versions.begin(), versions.end(), version) != versions.end();
}
