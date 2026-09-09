PROJECT_NAME := bonobomock

# CMake listfiles to be formatted with cmake-format. Mirrors the file set used
# by the CI `cmake-format` check (CMakeLists.txt and *.cmake), while excluding
# build artifacts and *.cmake.in templates.
CMAKE_FILES := $(shell git ls-files 'CMakeLists.txt' '*/CMakeLists.txt' '*.cmake')

.PHONY: format format-cpp format-cmake check-format check-format-cpp check-format-cmake

format: format-cpp format-cmake

format-cpp:
	find . \( -name \*.h -o -name \*.cpp \) -exec clang-format-21 -i --style=file {} \; -print

format-cmake:
	cmake-format -i -c .cmake-format.yaml -- $(CMAKE_FILES)

check-format: check-format-cpp check-format-cmake

check-format-cpp:
	find . \( -name \*.h -o -name \*.cpp \) -exec clang-format-21 --dry-run -Werror --style=file {} +

check-format-cmake:
	cmake-format --check -c .cmake-format.yaml -- $(CMAKE_FILES)
