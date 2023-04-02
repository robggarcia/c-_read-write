#include <iostream>
#include <fstream> // FILE STREAM
#include <vector>

void write_to_file()
{
    std::cout << "What is the file name you'd like to use?" << std::endl;
    std::string filename;
    std::cin >> filename;

    // create a file object from the ofstream class
    // when writing to a file, it will automaticall be created if it doesn't already exist
    // std::ios::app will append any new data to the end of the file

    // output ofstream for WRITING files
    std::ofstream file(filename, std::ios::app);
    // file.open("hello.txt");

    if (file.is_open())
    {
        std::cout << "file successfully opened :)" << std::endl;
    }

    std::vector<std::string> names;
    names.push_back("Rob");
    names.push_back("Mario");
    names.push_back("Luigi");

    // loop through the vector and add the names to the file
    for (std::string name : names)
    {
        file << name << std::endl;
    }

    // good practice to close the file at the end
    file.close();
}

void read_file()
{
    // when reading from files, we need to create our own object from fstream
    // input ifstream for READING files
    std::ifstream file("names.txt");

    std::vector<std::string> names;

    std::string input;
    while (file >> input) // return file stream similar to std::cin
    {
        names.push_back(input);
    }

    for (std::string name : names)
    {
        std::cout << name << std::endl;
    }

    // we can also read an entire line from the file
    std::string line;
    getline(file, line);
    std::cout << line << std::endl;
}

int main()
{
    write_to_file();
    read_file();

    return 0;
}