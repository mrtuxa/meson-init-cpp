default: clean setup build


clean:
	rm -rf builddir

setup:
	meson setup builddir

build:
	cd builddir && ninja
