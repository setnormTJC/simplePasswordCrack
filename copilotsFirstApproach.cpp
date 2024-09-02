#include <iostream>
#include <string>

void generatePasswords(std::string& guessedPassword, const std::string& correctPassword, int index) {
    if (index == guessedPassword.length()) {
        if (guessedPassword == correctPassword) {
            std::cout << "Password found: " << guessedPassword << std::endl;
            exit(0);
        }
        return;
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        guessedPassword[index] = c;
        generatePasswords(guessedPassword, correctPassword, index + 1);
    }
}

int main() {
    std::string correctPassword = "pswd";
    std::string guessedPassword(correctPassword.length(), '_');

    generatePasswords(guessedPassword, correctPassword, 0);

    std::cout << "Password not found.\n";
    return 0;
}
