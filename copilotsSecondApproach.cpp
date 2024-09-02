#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string correctPassword = "pswd";
    std::string guessedPassword(correctPassword.length(), '_');
    std::stack<std::pair<std::string, int>> stack;

    stack.push({guessedPassword, 0});

    while (!stack.empty()) {
        auto [currentGuess, index] = stack.top();
        stack.pop();

        if (index == currentGuess.length()) {
            if (currentGuess == correctPassword) {
                std::cout << "Password found: " << currentGuess << std::endl;
                return 0;
            }
            continue;
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            currentGuess[index] = c;
            stack.push({currentGuess, index + 1});
        }
    }

    std::cout << "Password not found.\n";
    return 0;
}
