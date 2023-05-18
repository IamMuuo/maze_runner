# Maze Runner
A remake of the classic maze runner game

## Prerequisites
- Cmake (version 3.12) or higher
- Compiler compatible with your operating system (e.g., GCC, Clang)

## How to build
1.  Clone or download the project from the repository.
2.  Open a terminal or command prompt and navigate to the project directory.
3.  Create a build directory for out-of-source builds:

```bash
$ mkdir build cd build`
```

4.  Generate the build files using CMake:

```bash
$ cmake -G "Unix Makefiles" ../
```

5.  Build the project using the generated build system:

```bash
$ cmake --build . --config Debug --debug runner
```


6.  After a successful build, you can run the executable generated in the `build` directory.

```bash
$ ./runner
```

7. Enjoy the game

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request on the repository.

## License

This project is licensed under the [MIT License](https://github.com/git/git-scm.com). Feel free to use, modify, and distribute it according to the terms of the license.
