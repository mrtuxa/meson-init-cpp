# meson-init-cpp
meson-init-cpp is a project initialization tool for C++ projects using the Meson build system.

# Installation
To install meson-init-cpp, follow these steps:

Clone the repository: `git clone https://github.com/mrtuxa/meson-init-cpp.git` <br>
Navigate to the project directory: `cd meson-init-cpp` <br>
Build the project: `bash run`

# Arch Linux

with AUR Helper
```shell
yay -S meson-init-cpp-git
```

```shell
git clone https://aur.archlinux.org/meson-init-cpp-git.git
cd meson-init-cpp-git/
makepkg -si
```

# Usage
To use meson-init-cpp, run the following command:


```bash
meson-init-cpp <project_name> <version> <c++ version>
```

For example:

```bash
meson-init-cpp foo 0.1 14
```

This will create a new project with the specified name, version, and C++ version.

# Contributing
Contributions to meson-init-cpp are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the GitHub repository.

# License
meson-init-cpp is licensed under the GPL-3.0 License. See the LICENSE file for more information.

# Contact
For any questions or further information, you can reach out to me via email (mrtuxa@infra-sys.de) or through a issue.

# tested OS

- [x] Debian
- [x] OpenBSD
