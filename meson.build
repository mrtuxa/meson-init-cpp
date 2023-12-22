project('meson-init-cpp', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

exe = executable('meson_init_cpp', ['src/main.cpp', 'src/contains.cpp', 'src/contains.hpp'],
  install : true)

test('basic', exe)
