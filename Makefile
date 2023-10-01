
.PHONY: all clean build run format

build:
	mkdir -p build && cd build && cmake .. && make -j4

bf: format build

clean:
	rm -rf build

format:
	clang-format -i *.c *.h -style=file:.clang-format