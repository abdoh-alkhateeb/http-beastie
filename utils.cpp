#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string read_file(const string& file_path) {
    ifstream file(file_path);

    if (!file.is_open()) {
        return "";
    }

    stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}
