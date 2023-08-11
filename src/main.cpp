#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    std::cout
        << "Usage: <project_name> <version> <c++ version>\nExample: foo 0.1 14"
        << std::endl;
    exit(1);
  } else if (argc == 4) {
    std::filesystem::path currentDir = std::filesystem::current_path();
    if (!std::filesystem::is_empty(currentDir)) {
      std::cout << "The directory must be empty!" << std::endl;
      exit(1);
    }

    if (std::string(argv[1]) == "test") {
      std::cout << " ERROR: Target name 'test' is reserved for Meson's "
                   "internal use. Please rename."
                << std::endl;
      exit(1);
    }

    std::ofstream project("meson.build");

    // create meson.build file
    project << "project('" << argv[1] << "', 'cpp',\n"
            << "\tversion : '" << argv[2] << "',\n"
            << "\tdefault_options : ['warning_level=3',\n"
            << "\t\t\t   'cpp_std=c++" << argv[3] << "'])\n\n"
            << "exe = executable('" << argv[1] << "', 'src/main.cpp',\n"
            << "\tinstall : true)\n\n"
            << "test('basic', exe)\n";

    // create source dir
    std::string src = "src";
    std::filesystem::create_directory(src);
    std::filesystem::permissions(src, std::filesystem::perms::others_all,
                                 std::filesystem::perm_options::remove);

    // create example file
    std::ofstream main("src/main.cpp");

    main << "#include <iostream>" << std::endl
         << std::endl
         << "int main() {" << std::endl
         << "  std::cout <<  \"Hello World\" << std::endl;" << std::endl
         << std::endl
         << "  return 0;" << std::endl
         << "}" << std::endl;

    std::cout << "Source Directory" << std::endl;
    for (const auto &entry : std::filesystem::directory_iterator(src)) {
      std::cout << entry.path() << std::endl;
    }
  }

  // create Makefile
  std::ofstream makefile("Makefile");

  makefile << "all: clean setup compile" << std::endl
           << "default: all" << std::endl
           << std::endl
           << "setup:" << std::endl
           << "\t@meson setup builddir" << std::endl
           << std::endl
           << "compile:" << std::endl
           << std::endl
           << std::endl
           << "\t@meson compile -C builddir" << std::endl
           << "clean:" << std::endl
           << "\t@rm -f -R builddir" << std::endl;

  // check if git is installed
  int checkGit = std::system("git --version");

  if (checkGit != 0) {
    std::cout << "Pleas install git on your system" << std::endl;
    exit(1);
  }

  // git init & and all files

  std::system("git init");
  std::system("git add Makefile meson.build src/main.cpp");
  std::system("git commit -m 'init repo'");

  return 0;
}
