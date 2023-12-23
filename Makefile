default: clean setup build


clean:
	rm -rf builddir

setup:
	meson setup builddir

build:
	cd builddir && ninja
install:
	cp builddir/meson_init_cpp /usr/local/bin/meson-init-cpp
