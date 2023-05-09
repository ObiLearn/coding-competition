.PHONY: clean test

test: build/test
	./build/test

clean:
	rm -fr build

build/build.ninja: CMakeLists.txt
	cmake -S . -B build

build/test: build/build.ninja task.hpp
	cmake --build build
