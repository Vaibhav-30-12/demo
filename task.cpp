#include <iostream>
#include <string>

class CaesarCipher {
public:
    static std::string encrypt(const std::string& message, int key) {
        std::string result = "";
        for (char c : message) {
            if (isalpha(c)) {
                char shifted = (isupper(c)) ? 'A' + (c - 'A' + key) % 26 : 'a' + (c - 'a' + key) % 26;
                result += shifted;
            } else {
                result += c; // Preserve non-alphabetic characters
            }
        }
        return result;
    }

    static std::string decrypt(const std::string& encryptedMessage, int key) {
        return encrypt(encryptedMessage, -key); // Decryption is just encryption with negative key
    }
};

int main() {
    std::string message;
    int key;
    std::cout << "Enter the message: ";
    std::getline(std::cin >> std::ws, message); // Read the entire line, including whitespace
    std::cout << "Enter the key: ";
    std::cin >> key;

    std::string encryptedMessage = CaesarCipher::encrypt(message, key);
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;

    std::string decryptedMessage = CaesarCipher::decrypt(encryptedMessage, key);
    std::cout << "Decrypted message: " << decryptedMessage << std::endl;

    return 0;
}
