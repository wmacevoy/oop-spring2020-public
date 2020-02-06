# Greet

Make a Greeting class that can print out greeting messages.  The makefile is fairly generic, and, if you structure your project as

```
src/*.cpp
include/*.h
tmp/*.o - temporary object files
lib/*.so - external shared libraries
bin/XXXX - programs built from src/main_XXXX.cpp
bin/test_XXXX - tests built from src/test_XXXX.cpp
```

You can use make clean/all without modifying Makefile and Makefile.googletest


## Build

```bash
make clean
make all
```

## Test

```bash
bin/test_greet
```

## Run

```bash
bin/greet
```

## Clean-Build-Test Screen Capture

Note it says hello, but I moved the project to "greet" for a simpler hello...

As a mov: (must download to play): [clean-test-build.mov](https://raw.githubusercontent.com/wmacevoy/csci000-astudent/master/greet/clean-build-test.mov)

As a [gif](https://cloudconvert.com/mov-to-gif)

![clean-test-build.gif](clean-build-test.gif)

## Docker

To create a reproducible build (advanced) and you have docker installed, you can do the following:

```bash
docker build -t cpp-greet .
docker run -i --rm -t cpp-greet test_greet # test
docker run -i --rm -t cpp-greet greet # run
```

## References

1. [GNU make tutorial](https://linuxhint.com/gnu-make-tutorial/)
1. [C++ Google Test](https://github.com/google/googletest)
1. [src/include](https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)

