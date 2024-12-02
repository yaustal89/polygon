#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class MinMaxScaler {
public:
    // O(n), where n - number of elements in inputArr
    MinMaxScaler(vector<double>& inputArr) : arr(inputArr) {
        normalize(arr); // O(n), where n - number of elements in arr
    }

    const vector<double>& getScaledArray() const {
        return arr;
    }

    void printScaledArray() const {
        cout << setprecision(4) << fixed;
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << scientific << arr[i];
            if (i != arr.size() - 1) cout << " ";
        }
        cout << "]" << endl;
    }

    void saveScaledArrayToFile(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cerr << "Unable to open file: " << filename << endl;
            return;

        }

        for (size_t i = 0; i < arr.size(); ++i) {
            outFile << fixed << setprecision(4) << arr[i];
            if (i != arr.size() - 1) {
                outFile << ",";
            }
        }
        outFile.close();
        cout << "Successfully saved data to file: " << filename << endl;
    }

private:
    vector<double> arr;

    void normalize(vector<double>& inputArr) {
        // If array is empty, then scaledArray is empty too
        if (inputArr.empty()) {
            return; // O(1)
        }

        // Finding minVal and maxVal of the array
        int minVal = *min_element(inputArr.begin(), inputArr.end()); // O(n)
        int maxVal = *max_element(inputArr.begin(), inputArr.end()); // O(n)

        // If min == max, then fill arr with 0.0
        if (minVal == maxVal) {
            arr.resize(inputArr.size(), 0.0); // Create a vector with the same size and fill with 0.0
            return;
        }

        // Normalizing
        arr.resize(inputArr.size()); // Resize arr to store scaled values
        for (size_t i = 0; i < inputArr.size(); ++i) {
            arr[i] = static_cast<double>(inputArr[i] - minVal) / (maxVal - minVal); // O(n)
        }
    }
};

vector<double> readDataFromFile(const string& filename) {
    ifstream file(filename);
    vector<double> data;
    string line;

    if (!file.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return data;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string item;

        while (getline(ss, item, ',')) {
            try {
                data.push_back(stod(item)); // Convert to integer (double)
            }
            catch (const invalid_argument& e) {
                cerr << "Error converting string: " << item << endl;
            }
        }
    }

    return data;

}

int main() {
    string filename = "C:\\Study\\dataset_file3.txt";

    vector<double> myArray = readDataFromFile(filename);

    MinMaxScaler sc(myArray);
    sc.printScaledArray();
    sc.saveScaledArrayToFile("scaledDataset3.txt");

    return 0;
}