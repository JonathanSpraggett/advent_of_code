#include <advent_of_code/day1.h>


int day1() {
    int sum = 0;
    string myText;
    ifstream MyReadFile("input/input_day1.txt");
    string list1[] = {"one", "two", "three", "four", "five", "six",
                     "seven", "eight", "nine","1", "2",
                      "3", "4", "5", "6","7","8","9"};

    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        int index_1 = 10000;
        int index_2 = 0;
        int val_1 = 0;
        int val_2 = 0;
        int counter=1;
        for (const auto& str: list1){
            if (counter == 10){
                counter=1;
            }
            int temp;
            for(int i = 0; i < myText.size(); i++) {
                temp = myText.substr(i).find(str);

                if (temp == -1){
                    break;
                }
                
                if (temp+i < index_1){
                    index_1 = temp + i;
                    val_1 = counter;
                }
                if(temp+i > index_2){
                    index_2 = temp + i;
                    val_2 = counter;
                }
                i+= temp;

            }
            counter++;
        }
        if (index_2 == 0){
            val_2 = val_1;
        }
        sum += val_1*10+val_2;
    }
    // Close the file
    MyReadFile.close();
    return sum;
}