**Instructions**  
Clone or download the repository.  
Open the main.cpp file and add method calls to the in memory database in the main method.  
Open a terminal locally that is in the same folder as the repository.  
On a Windows machine, type `g++ ./main.cpp ./InMemory.cpp -o ./main.exe` into the terminal to compile the code.  
Then type `./main.exe` to run the program.  
On a Mac machine, you might be able to use similar commands but type `main` instead of `main.exe`.  

**How to Improve This**  
One way to improve this can be to show how all the outputs should look like and how to compile our code so an autograder can be used. Another way can be to update the last comment in Figure 2 of the assignment because I think it's wrong as `inmemoryDB.get("B")` should return NULL because B does not exist in the database. Also, the assignment might be better if a real relational database was used so students can get some experience working with one.