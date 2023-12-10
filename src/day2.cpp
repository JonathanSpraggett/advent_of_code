#include <advent_of_code/day2.h>

int day2_part1() {
    string myText;
    ifstream MyReadFile("input/input_day2.txt");
    string list[] = {"blue", "red", "green"};
    vector<int> failed;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        const int index_space = myText.find(' '), index_colon = myText.find(':');
        int id = stoi(myText.substr(index_space,(index_colon - index_space)));
        vector<string> pulls;
        vector<int> indexes;

        bool pass = true;
        stringstream  ss(myText.substr(index_colon + 1));
        string str;
        while (getline(ss, str, ';')) {
            pulls.push_back(trim(str));
        }


        for (const auto& i: pulls) {
            stringstream  ss2(i);
            string str2;

            while (getline(ss2, str2, ',')) {
                // print(trim(str2));
                int j = -1;
                for (const auto & color: list) {
                    j+=1;
                    int temp = str2.find(color);
                    if (temp == -1){
                        continue;
                    }

                    // print(trim(str2.substr(0, temp)));

                    int num = stoi(trim(str2.substr(0, temp)));
                    // print(color, str2, j, num);
                    switch (j) {
                        case 0: // blue
                            if (num > 14) {
                                pass = false;
                            }
                            break;
                        case 1: // red
                            if (num > 12) {
                                pass = false;
                            }
                            break;
                        case 2: // green
                            if (num > 13) {
                                pass = false;
                            }
                            break;
                        // default:
                        //     break;

                    }


                }

            }

        }
        if (pass) {
            failed.push_back(id);
        }


    }
    int sum = 0;
    for (const auto& i: failed) {
        sum+= i;
    }

    // Close the file
    MyReadFile.close();
    return sum;
}

int day2_part2() {
    string myText;
    ifstream MyReadFile("input/input_day2.txt");
    string list[] = {"blue", "red", "green"};
    vector<int> failed;
    int sum = 0;
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        const int index_space = myText.find(' '), index_colon = myText.find(':');
        int id = stoi(myText.substr(index_space,(index_colon - index_space)));
        vector<string> pulls;
        vector<int> indexes;
        int max_blue = 0,max_red = 0,max_green = 0;

        bool pass = true;
        stringstream  ss(myText.substr(index_colon + 1));
        string str;
        while (getline(ss, str, ';')) {
            pulls.push_back(trim(str));
        }


        for (const auto& i: pulls) {
            stringstream  ss2(i);
            string str2;

            while (getline(ss2, str2, ',')) {
                // print(trim(str2));
                int j = -1;
                for (const auto & color: list) {
                    j+=1;
                    int temp = str2.find(color);
                    if (temp == -1){
                        continue;
                    }

                    // print(trim(str2.substr(0, temp)));

                    int num = stoi(trim(str2.substr(0, temp)));
                    // print(color, str2, j, num);
                    switch (j) {
                        case 0: // blue
                            if (num > max_blue)
                                max_blue = num;
                            break;
                        case 1: // red
                            if (num > max_red)
                                max_red = num;
                            break;
                        case 2: // green
                            if (num > max_green)
                                max_green = num;
                            break;
                        // default:
                        //     break;

                    }


                }

            }

        }
        sum += max_blue*max_green*max_red;

    }

    for (const auto& i: failed) {
        sum+= i;
    }

    // Close the file
    MyReadFile.close();
    return sum;
}