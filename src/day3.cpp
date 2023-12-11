//
// Created by jonathan on 11/12/23.
//

#include <advent_of_code/day3.h>

int day3() {
    string myText;
    ifstream MyReadFile("input/input_day3.txt");
    std::vector<int> engine;
    std::vector<int> extractedNumbers;

    while (getline (MyReadFile, myText)) {
        // Output the text from the file

        std::string currentNumber = "";
        std::string currentLine = "";
        for (char ch : myText) {
            if (std::isdigit(ch)) {
                currentNumber += ch;
                engine.push_back(extractedNumbers.size() + 1);
            } else if(ch == '.')  {
                if (!currentNumber.empty())
                {
                    extractedNumbers.push_back(stoi(currentNumber));
                currentNumber.clear();
                }
                engine.push_back(0);


            }else
            {
                if (!currentNumber.empty())
                {
                    extractedNumbers.push_back(stoi(currentNumber));
                    currentNumber.clear();
                }
                engine.push_back(-1);
            }
        }

        // Check if there's a number at the end of the string
        if (!currentNumber.empty()) {
            extractedNumbers.push_back(stoi(currentNumber));
        }
        // print(myText, "1");
        // engine.push_back(myText);

    }
    for (const auto& i: engine)
    {
        cout << i;
    }
    cout << endl;
    // Close the file
    MyReadFile.close();
    return 0;
}
