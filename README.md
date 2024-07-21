# heapguard
This is a simple tool for managing all the memory allocated to the heap in a c program.

It's purpose is to keep track of any memory and to automatically wipe and free all the memory when the program exits. This ensures that no memory leaks occur, no sensative information is left in memory and speeds up the development process


## Usage

Add this file to your project folder and include the header file.
Once you've done this make sure you call initheapguard() at the start of your program.
Now whenever you want to allocate memory to the heap do it through heapguard and all the memory will be safely wiped and freed at the end of the program.

This version of heapguard only supports char * types but updates will be coming out soon allowing you to store more types of data in the future.
## Contributing

Contributions are welcome! If you'd like to contribute to Velocifare, please follow these guidelines:

- Fork the repository
- Create a new branch for your feature or fix: `git checkout -b feature-name`
- Make your changes and commit them: `git commit -am 'Add new feature'`
- Push to your fork: `git push origin feature-name`
- Submit a pull request
