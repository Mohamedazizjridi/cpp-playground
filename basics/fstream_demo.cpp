/*
<fstream> is the C++ standard library for file input/output.
It provides classes to read from and write to files using streams, just like cin and cout for console I/O.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // ---------------------------
    // 1. ofstream (write to file)
    // ---------------------------
    ofstream ofs("output.txt"); // open file for writing (truncates by default)
    if (!ofs) {
        cerr << "Error opening output.txt for writing!" << endl;
        return 1;
    }

    ofs << "Hello, world!\n";
    ofs << "Writing multiple lines to file.\n";
    ofs.close(); // always close file

    // ---------------------------
    // 2. ifstream (read from file)
    // ---------------------------
    ifstream ifs("output.txt");
    if (!ifs) {
        cerr << "Error opening output.txt for reading!" << endl;
        return 1;
    }

    string line;
    cout << "Reading file line by line:\n";
    while (getline(ifs, line)) { // read line by line
        cout << line << endl;
    }
    ifs.close();

    // ---------------------------
    // 3. fstream (read & write)
    // ---------------------------
    fstream fs("example.txt", ios::in | ios::out | ios::trunc);
    if (!fs) {
        cerr << "Error opening example.txt!" << endl;
        return 1;
    }

    // Writing to file
    fs << "Line 1\n";
    fs << "Line 2\n";

    // Move get pointer to beginning
    fs.seekg(0);

    cout << "\nReading example.txt after writing:\n";
    while (getline(fs, line)) {
        cout << line << endl;
    }

    // Move put pointer to end for appending
    fs.clear();            // clear EOF flag
    fs.seekp(0, ios::end);
    fs << "Appended line\n";

    fs.close();

    // ---------------------------
    // 4. File open modes examples
    // ---------------------------
    // ios::in    -> read
    // ios::out   -> write
    // ios::app   -> append
    // ios::trunc -> truncate file
    // ios::ate   -> start at end
    // ios::binary-> binary mode

    // ---------------------------
    // 5. Reading using different methods
    // ---------------------------
    ifstream fin("output.txt");
    char c;

    cout << "\nReading character by character:\n";
    while (fin.get(c)) { // get single character
        cout << c;
    }
    fin.close();

    // Using read() in binary mode
    ofstream binFile("binary.dat", ios::binary);
    int numbers[] = {1, 2, 3, 4, 5};
    binFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    binFile.close();

    ifstream binIn("binary.dat", ios::binary);
    int readNums[5];
    binIn.read(reinterpret_cast<char*>(readNums), sizeof(readNums));
    cout << "\nReading binary file contents:\n";
    for (int n : readNums) cout << n << " ";
    cout << endl;
    binIn.close();

    // ---------------------------
    // 6. Tricks & useful methods
    // ---------------------------
    // fs.tellg()  -> get current read position
    // fs.tellp()  -> get current write position
    // fs.seekg(pos) / fs.seekp(pos) -> move read/write pointer
    // fs.eof()   -> check end of file
    // fs.fail()  -> check failure
    // fs.good()  -> check if stream is OK

    cout << "\nDemo finished.\n";
    return 0;
}
