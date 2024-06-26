# PixelSearch

PixelSearch is a simple C project that searches for a specific color on your screen. This project is designed to demonstrate basic screen capture and pixel color search functionality using a DLL **[FastFind](https://github.com/FastFrench/FastFind)**.

## Features

- Capture a screenshot within a specified field of view (FOV).
- Search for a specific color within the captured screenshot.
- Dynamically load functions from a DLL for screen capture and color search.

## Requirements

- Windows operating system
- `FastFind64.dll` (Make sure this DLL is in the same directory as the executable)
- GCC (MinGW) or any C compiler for Windows

## Building the Project

1. Clone the repository:
   ```sh
   git clone https://github.com/scovl/pixelsearch.git
   cd pixelSearch
   ```

2. Build the project using `make`:
   ```sh
   make
   ```

   This will compile the source code and create an executable named `pixelSearch`.

## Running the Project

1. Ensure `FastFind64.dll` is in the same directory as the `pixelSearch` executable.
2. Run the executable:
   ```sh
   ./pixelSearch
   ```

   The program will capture a screenshot and search for the specified color. If the color is found, it will print the coordinates of the pixel. If not, it will report a failure.


## Customizing the Search

You can customize the search settings by modifying the `User_init` function in `src/User.c`:

```c
void User_init(User* user) {
    user->searchSettings.refX = 100;
    user->searchSettings.refY = 100;
    user->searchSettings.color = 0x00FF00; // Example color (green)
    user->searchSettings.colorVariation = 10;
    user->searchSettings.sizeSearch = 10;
    user->searchSettings.minMatch = 5;
}
```

Change the values as needed to search for different colors or adjust the search area.

## Troubleshooting

- Ensure `FastFind64.dll` is present in the same directory as the executable.
- Verify that the DLL functions (`SnapShot` and `GenericColorSearch`) are correctly exported and accessible.
- Check for any error messages printed to the console for clues about what might be going wrong.

## Contributing

Feel free to fork this repository and submit pull requests. If you encounter any issues, please report them on the project's GitHub page.

## License

This project is licensed under the BSD 2-Clause License. See the `LICENSE` file for more details.
