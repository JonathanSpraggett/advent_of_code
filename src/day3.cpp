//
// Created by jonathan on 11/12/23.
//

#include <advent_of_code/day3.h>

int day3_part1() {
    string myText;
    ifstream MyReadFile("input/input_day3.txt");
    std::vector<vector<int>> engine;
    std::vector<int> extractedNumbers;
    std::vector<int> usedNumbers;
    int sum = 0;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        std::vector<int> engine_row;
        std::string currentNumber;
        std::string currentLine;

        for (char ch : myText) {
            if (std::isdigit(ch)) {
                currentNumber += ch;
                engine_row.push_back(extractedNumbers.size() + 2);
            } else if(ch == '.')  {
                if (!currentNumber.empty())
                {
                    extractedNumbers.push_back(stoi(currentNumber));
                currentNumber.clear();
                }
                engine_row.push_back(0);


            }else
            {
                if (!currentNumber.empty())
                {
                    extractedNumbers.push_back(stoi(currentNumber));
                    currentNumber.clear();
                }
                engine_row.push_back(1);
            }
        }

        // Check if there's a number at the end of the string
        if (!currentNumber.empty()) {
            extractedNumbers.push_back(stoi(currentNumber));
        }
        engine.push_back(engine_row);
        // print(myText, "1");
        // engine.push_back(myText);

    }
    // for (const auto& row: engine)
    // {
    //     for (const auto& i: row)
    //     {
    //         cout << i << ", ";
    //     }
    //     cout << endl;
    // }
    for (int row = 0; row < engine.size(); row++ )
    {
        for (int col = 0; col < engine[row].size(); col++)
        {
            if (engine[row][col] == 1)
            {
                int location []= {engine[row-1][col-1],engine[row][col-1],engine[row-1][col],
                                    engine[row+1][col+1],engine[row][col+1],engine[row+1][col],
                                    engine[row+1][col-1],engine[row-1][col+1]};
                for (auto i: location)
                {
                    if (i>= 2 && !(std::find(usedNumbers.begin(), usedNumbers.end(), i) != usedNumbers.end()))
                    {
                        sum += extractedNumbers[i-2];
                        usedNumbers.push_back(i);
                    }
                }

            }
            // cout << engine[row][col] << ", ";
        }
        // cout << endl;
    }
    print(sum);
    // Close the file
    MyReadFile.close();
    return 0;
}

int day3_part2() {
    string myText;
    ifstream MyReadFile("input/input_day3.txt");
    std::vector<vector<int>> engine;
    std::vector<int> extractedNumbers;
    std::vector<int> usedNumbers;
    int sum = 0;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        std::vector<int> engine_row;
        std::string currentNumber;
        std::string currentLine;

        for (char ch : myText) {
            if (std::isdigit(ch)) {
                currentNumber += ch;
                engine_row.push_back(extractedNumbers.size() + 2);
            } else if(ch == '*')
            {
                if (!currentNumber.empty())
                {
                    extractedNumbers.push_back(stoi(currentNumber));
                    currentNumber.clear();
                }
                engine_row.push_back(1);
            }
            else  {
                if (!currentNumber.empty())
                {
                    extractedNumbers.push_back(stoi(currentNumber));
                    currentNumber.clear();
                }
                engine_row.push_back(0);


            }
        }

        // Check if there's a number at the end of the string
        if (!currentNumber.empty()) {
            extractedNumbers.push_back(stoi(currentNumber));
        }
        engine.push_back(engine_row);

    }
    // for (const auto& row: engine)
    // {
    //     for (const auto& i: row)
    //     {
    //         cout << i << ", ";
    //     }
    //     cout << endl;
    // }

    for (int row = 0; row < engine.size(); row++ )
    {
        for (int col = 0; col < engine[row].size(); col++)
        {
            if (engine[row][col] == 1)
            {
                int location []= {engine[row-1][col-1],engine[row][col-1],engine[row-1][col],
                                    engine[row+1][col+1],engine[row][col+1],engine[row+1][col],
                                    engine[row+1][col-1],engine[row-1][col+1]};
                int count = 0;
                int gear_ratio = 1;
                for (auto i: location)
                {
                    if (i>= 2 && !(std::find(usedNumbers.begin(), usedNumbers.end(), i) != usedNumbers.end()))
                    {
                        // sum += extractedNumbers[i-2];
                        gear_ratio *= extractedNumbers[i-2];
                        usedNumbers.push_back(i);
                        count += 1;
                    }
                }
                // print(count);
                if (count == 2)
                {
                    sum += gear_ratio;
                }
                usedNumbers.clear();
            }
            // cout << engine[row][col] << ", ";
        }
        // cout << endl;
    }
    print(sum);
    // Close the file
    MyReadFile.close();
    return 0;
}