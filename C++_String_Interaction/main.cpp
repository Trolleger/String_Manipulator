#include <iostream> // Include the input/output stream library
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include <cstring>
#include <SFML/Graphics.hpp> // For rendering, textures, sprites, shapes
#include <SFML/Window.hpp>   // For window creation and input handling
#include <SFML/System.hpp>   // For system utilities (time, threads, etc.)
#include <SFML/Audio.hpp>    // For sound and music (only if needed)
#include <SFML/Window.hpp>
#include <SFML/Network.hpp> // For networking (only if needed)

// DEFINING STRINGS
std::string user_prompt;
std::string user_prompt_for_how_to_manipulate_string;

void open_screen()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    sf::Font font("arial.ttf");
    sf::Text text(font);
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // Text entered event - MOVED INSIDE THE EVENT LOOP
            if (const auto* textEntered = event->getIf<sf::Event::TextEntered>())
            {
                if (textEntered->unicode < 128)
                     // add this above your loop
                  
                    text.setString(static_cast<char>(textEntered->unicode));
                    
            }
            
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.draw(text);  
        window.display();
    }
}

// FUNCTIONS
void phrase_reverser_loop()
{

    std::string phrase; // Create a string variable to store the phrase
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while (user_prompt == "1")
    {
        std::cout << "Enter a phrase to reverse: ";              // Clear prompt message
        std::getline(std::cin, phrase);                          // Get the phrase from the user
        std::reverse(phrase.begin(), phrase.end());              // Reverse the phrase
        std::cout << "Reversed phrase: " << phrase << std::endl; // Display reversed string clearly

        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2")
        {
            return;
        }
    }
}

void phrase_uppercaser_loop()
{
    std::string phrase; // Create a string variable to store the phrase
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while (user_prompt == "1")
    {
        std::cout << "Enter a phrase to turn Uppercase: "; // Clear prompt message
        std::getline(std::cin, phrase);                    // Get the phrase from the user
        std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::toupper);
        ;                                                          // Uppercase the phrase
        std::cout << "Uppercased Phrase: " << phrase << std::endl; // Display reversed string clearly

        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2")
        {
            return;
        }
    }
}

void phrase_lowercaser_loop()
{
    std::string phrase; // Create a string variable to store the phrase
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while (user_prompt == "1")
    {
        std::cout << "Enter a phrase to Lowercase: "; // Clear prompt message
        std::getline(std::cin, phrase);               // Get the phrase from the user
        std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
        ;                                                          // Uppercase the phrase
        std::cout << "Lowercased Phrase: " << phrase << std::endl; // Display reversed string clearly

        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2")
        {
            return;
        }
    }
}

void phrase_titlecase_loop()
{
    std::string phrase;
    std::string user_prompt; // Declare user_prompt here
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO): ";
    std::getline(std::cin, user_prompt);

    while (user_prompt == "1")
    {
        std::cout << "Enter a phrase to turn Titlecase: ";
        std::getline(std::cin, phrase);

        // Convert the phrase to title case
        bool new_word = true;
        for (char &c : phrase)
        {
            if (new_word && std::isalpha(c))
            {
                c = std::toupper(c);
                new_word = false;
            }
            else if (std::isspace(c))
            {
                new_word = true;
            }
            else
            {
                c = std::tolower(c);
            }
        }

        std::cout << "Titlecased phrase: " << phrase << std::endl;

        std::cout << "Would you like to continue? 1 (YES) or 2 (NO): ";
        std::getline(std::cin, user_prompt);

        if (user_prompt == "2")
        {
            return; // Exit the function if the user chooses to stop
        }
    }
}

void phrase_remove_occurrences_of_a_substring()
{
    std::string phrase, substring, user_prompt;

    std::cout << "Would you like to Start? 1 (YES) or 2 (NO): ";
    std::getline(std::cin, user_prompt);

    while (user_prompt == "1")
    {
        std::cout << "Enter the phrase you are removing the substring from: ";
        std::getline(std::cin, phrase); // Get the phrase from the user
        std::cout << "Enter the substring you are removing from the phrase: ";
        std::getline(std::cin, substring); // Get the substring from the user

        // Check if the substring is found and remove it
        if (phrase.find(substring) != std::string::npos)
        {                                                             // Substring found
            phrase.erase(phrase.find(substring), substring.length()); // Erase the substring
        }
        else
        {
            std::cout << "Substring not found!" << std::endl; // Substring not found error
            return;                                           // Exit if substring is not found
        }

        std::cout << "Updated phrase: " << phrase << std::endl; // Display updated phrase

        std::cout << "Would you like to continue? 1 (YES) or 2 (NO): ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2")
        {
            return; // Exit if the user chooses "NO"
        }
    }
}

void phrase_shuffle_loop()
{
    std::string phrase; // Create a string variable to store the phrase
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while (user_prompt == "1")
    {
        std::cout << "Enter a phrase to Shuffle: "; // Clear prompt message
        std::getline(std::cin, phrase);             // Get the phrase from the user

        std::random_device rd;                         // Initialize a random number generator
        std::mt19937 g(rd());                          // Create a Mersenne Twister random number generator
        std::shuffle(phrase.begin(), phrase.end(), g); // Shuffle the string

        std::cout << "Shuffled String: " << phrase << std::endl; // Display reversed string clearly
        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2")
        {
            return;
        }
    }
}

void phrase_replace_occurrences_of_a_substring()
{
    std::string phrase;                   // Create a string variable to store the phrase
    std::string substring_being_replaced; // Create a string variable to store the substring
    std::string substring_to_replace_with;
    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while (user_prompt == "1")
    {
        std::cout << "Enter the phrase you are doing this operation on ";
        std::getline(std::cin, phrase); // Get the phrase from the user

        std::cout << "Enter a substring to replace: ";    // Clear prompt message
        std::getline(std::cin, substring_being_replaced); // Get the phrase from the user

        std::cout << "Enter what you are REPLACING WITH!: "; // Clear prompt message
        std::getline(std::cin, substring_to_replace_with);   // Get the phrase from the user

        if (phrase.find(substring_being_replaced) != std::string::npos)
        {                                                                                           // Substring found
            phrase.erase(phrase.find(substring_being_replaced), substring_being_replaced.length()); // Erase the substring
        }
        else
        {
            std::cout << "Substring not found!" << std::endl; // Substring not found error
            return;                                           // Exit if substring is not found
        }

        phrase.replace(phrase.find(substring_being_replaced), substring_being_replaced.length(), substring_to_replace_with);
        std::cout << "Here is your new string or whatever: " << phrase << std::endl; // Display reversed string clearly

        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2")
        {
            return;
        }
    }
}

void phrase_remove_spaces()
{
    std::string phrase; // Create a string variable to store the phrase

    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while (user_prompt == "1")
    {
        std::cout << "Enter the phrase you are removing whitespace form: ";
        std::getline(std::cin, phrase); // Get the phrase from the user

        phrase.erase(remove(phrase.begin(), phrase.end(), ' '), phrase.end());

        std::cout << "Here is your string (without whitespace): " << phrase << std::endl; // Display string without space

        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2")
        {
            return;
        }
    }
}

void phrase_remove_vowels()
{
    std::string phrase; // Create a string variable to store the phrase

    std::cout << "Would you like to Start? 1 (YES) or 2 (NO) ";
    std::getline(std::cin, user_prompt);
    while (user_prompt == "1")
    {
        std::cout << "Enter the phrase you are removing vowels form: ";
        std::getline(std::cin, phrase); // Get the phrase from the user

        phrase.erase(remove_if(phrase.begin(), phrase.end(), [](char c)
                               { return strchr("aeiouAEIOU", c); }),
                     phrase.end());

        std::cout << "Here is your string (without vowels): " << phrase << std::endl; // Display string without space

        std::cout << "Would you like to continue? 1 (YES) or 2 (NO) ";
        std::getline(std::cin, user_prompt);
        if (user_prompt == "2")
        {
            return;
        }
    }
}

// Next make code cleaner and put in things to prevent errors

void main_loop()
{
    while (true)
    {
        std::cout << "Pick how you would like to manipulate your string. 1- Reverse 2- Uppercase 3- Lowercase 4- Titlecase 5 -Remove Substring 6- Shuffle String 7- Change Substring 8- Remove Whitespace 9- Remove Vowels ";
        std::getline(std::cin, user_prompt_for_how_to_manipulate_string);

        if (user_prompt_for_how_to_manipulate_string == "1")
        {
            phrase_reverser_loop();
        }
        else if (user_prompt_for_how_to_manipulate_string == "2")
        {
            phrase_uppercaser_loop();
        }
        else if (user_prompt_for_how_to_manipulate_string == "3")
        {
            phrase_lowercaser_loop();
        }
        else if (user_prompt_for_how_to_manipulate_string == "4")
        {
            phrase_titlecase_loop();
        }
        else if (user_prompt_for_how_to_manipulate_string == "5")
        {
            phrase_remove_occurrences_of_a_substring();
        }
        else if (user_prompt_for_how_to_manipulate_string == "6")
        {
            phrase_shuffle_loop();
        }
        else if (user_prompt_for_how_to_manipulate_string == "7")
        {
            phrase_replace_occurrences_of_a_substring();
        }
        else if (user_prompt_for_how_to_manipulate_string == "8")
        {
            phrase_remove_spaces();
        }
        else if (user_prompt_for_how_to_manipulate_string == "9")
        {
            phrase_remove_vowels();
        }
        else
        {
            break;
        }
    }
}

// MAIN FUNCTION
int main()
{
    open_screen();
    // main_loop();
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
// c++ related extensions and related