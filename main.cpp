#include <iostream>
#include "utils.h"
using namespace std;

int main() {
    cout << "Server starting..." << endl;
    
    string content = read_file("test.txt");

    if (content.empty()) {
        cout << "Failed to read file or file is empty." << endl;
    } else {
        cout << "File content:\n" << content << endl;
    }    
return 0;
}
