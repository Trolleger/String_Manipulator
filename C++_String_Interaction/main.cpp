#include <iostream>  // Include the input/output stream library
#include <string>
#include <algorithm>
#include <cctype>
// DEFINING STRINGS
std::string user_prompt;
std::string user_prompt_for_how_to_manipulate_string;

// FUNCTIONS
void phrase_reverser_loop() {

    std::string phrase;  // Create a string variable to store the phrase
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while(user_prompt=="1"){
        std::cout << "Enter a phrase to reverse: ";  // Clear prompt message
        std::getline(std::cin, phrase);  // Get the phrase from the user
        std::reverse(phrase.begin(), phrase.end());  // Reverse the phrase
        std::cout << "Reversed phrase: " << phrase << std::endl;  // Display reversed string clearly

       
        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2"){
            return;
        }
    }
}

void phrase_uppercaser_loop() {
    std::string phrase;  // Create a string variable to store the phrase
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while(user_prompt=="1"){
        std::cout << "Enter a phrase to turn Uppercase: ";  // Clear prompt message
        std::getline(std::cin, phrase);  // Get the phrase from the user
        std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::toupper);;  // Uppercase the phrase
        std::cout << "Uppercased Phrase: " << phrase << std::endl;  // Display reversed string clearly

       
        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2"){
            return;
        }
    }
}

void phrase_lowercaser_loop() {
    std::string phrase;  // Create a string variable to store the phrase
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while(user_prompt=="1"){
        std::cout << "Enter a phrase to Lowercase: ";  // Clear prompt message
        std::getline(std::cin, phrase);  // Get the phrase from the user
        std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);;  // Uppercase the phrase
        std::cout << "Lowercased Phrase: " << phrase << std::endl;  // Display reversed string clearly

       
        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2"){
            return;
        }
    }
}

void phrase_titlecase_loop() {
    std::string phrase;
    std::string user_prompt;  // Declare user_prompt here
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO): ";
    std::getline(std::cin, user_prompt);

    while (user_prompt == "1") {
        std::cout << "Enter a phrase to turn Titlecase: ";
        std::getline(std::cin, phrase);

        // Convert the phrase to title case
        bool new_word = true;
        for (char &c : phrase) {
            if (new_word && std::isalpha(c)) {
                c = std::toupper(c);
                new_word = false;
            } else if (std::isspace(c)) {
                new_word = true;
            } else {
                c = std::tolower(c);
            }
        }

        std::cout << "Titlecased phrase: " << phrase << std::endl;

        std::cout << "Would you like to continue? 1 (YES) or 2 (NO): ";
        std::getline(std::cin, user_prompt);

        if (user_prompt == "2") {
            return;  // Exit the function if the user chooses to stop
        }
    }
}

void main_loop(){
    while(true) {
        std::cout << "Pick how you would like to manipulate your string. 1- Reverse 2- Uppercase 3- Lowercase 4- Titlecase";
        std::getline(std::cin,user_prompt_for_how_to_manipulate_string);
    
        if (user_prompt_for_how_to_manipulate_string == "1") {
            phrase_reverser_loop();
        }
        else if (user_prompt_for_how_to_manipulate_string == "2"){
            phrase_uppercaser_loop();
        }
        else if (user_prompt_for_how_to_manipulate_string == "3"){
            phrase_lowercaser_loop();
        }
        else if (user_prompt_for_how_to_manipulate_string == "4"){
            phrase_titlecase_loop();
        }
        else{
            std::cout << "Invalid input, please try again ";
        }
    }
}    


// MAIN FUNCTION
int main() {   
    main_loop();
    return 0;
}






// Okay, as I see it we will start with 9 string manipulation functions for just our first version

// How can we get this loop to work lets think about it. We need main loop that picks how they want to manipulate the string and once they are done that
// they can break out of the loop to that main loop




// So  here is the plan. Without AI I want to create a application like Lingojam in c++ Essentially you give a string and it gives
// an output, and it has many many different settings, like reversing, or making fancy text and so much more stuff
// I will be using a mix of web assembly and what other stuff to make this work on the world wide web. So yeah, My project structure
// I think is to have a bunch of little functions for manipulating strings then have a main function that calls them all in a way
// Where it gives an option and the user picks whatever option they want to do to the text and it calls that function. Simple! Possibly
// Can be in one cpp file but who knows.

// So my idea for this is 1. Create a constant loop, 2. Keep on repeating the loop and every time is runs ask the user if they want to continue or break. 
// Now we created a basic loop we can find other fun stuff to do to the text



























































// #include <iostream>  // Include the input/output stream library
// #include <string>
// #include <algorithm>

// int word_reverser(){
//     std::string phrase;
//     std::cout << "Enter a phrase to reverse: ";  // Clear prompt message
//     std::getline(std::cin, phrase);
//     std::reverse(phrase.begin(), phrase.end());
//     std::cout << "Reversed phrase: " << phrase << std::endl;  // Display reversed string clearly
//     return 0;
// }

// int main() {
//     for (int i = 0; i < 5; i++){
//         word_reverser();
//     }
//     return 0;
// }
//  a funny thing happens where for some reason it prints my directory in code runner (reversed), maybe i found a glitch kek, 12/19/2024 using g++ and latest most updated
// c++ related faggotry extensions and related