# Maze Runner
A remake of the classic maze runner game

## Prerequisites
- Cmake (version 3.12) or higher
- Compiler compatible with your operating system (e.g., GCC, Clang)

> **Note**
> 
> As of the moment, you will have to setup the libraries manually
<details>
<summary>Linux</summary>
  
- **[SDL_2](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/index.php)**
- **[SDL_2 Extensions](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/linux/index.php)**
</details>
<details>
<summary>Windows</summary>
  
- **[SDL_2](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/index.php)**
- **[SDL_2 Extensions](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/windows/index.php)**
</details>


## How to build
1.  Clone or download the project from the repository.
2.  Ensure you've met all the **prerequisites**
3.  Open a terminal or command prompt and navigate to the project directory.
4.  Compile the files
```sh
mkdir build
make
```
5. Run the game
```sh
make run

# or

cd build
./maze_runner
```
<!-- 3.  Create a build directory for out-of-source builds:

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
``` -->


<!-- 6. After a successful build, you can run the executable generated in the `build` directory.

```bash
$ ./runner
``` -->

6. Enjoy the game

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request on the repository.

## License

This project is licensed under the [MIT License](./LICENSE). Feel free to use, modify, and distribute it according to the terms of the license.
