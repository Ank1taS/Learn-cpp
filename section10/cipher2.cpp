// cipher - encrypting and decrypting secrete massage 
// cipher substitutes letters, digits, special character, spaces

#include <iostream>
#include <string>

int main() {
    const std::string alphabet {"abcdefghikjlmonpqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890~`!@#$%^|&*()_+-=/'}{[]\";:<>,.?"};
    const std::string key {"~1!2`09#8@7%56^4&3*Q$W(ER)TY{UI]O P}lkjh'gf/dsaZ_X-C+V=B[|NM\">mn<bvcx,zA;SD:FGHJKL.poiuy?trewq"};

    std::string originalMassage, encryptedMassage, decryptedMassage ;

    // reading inputs
    std::cout << "Enter your secret massage: ";
    getline(std::cin, originalMassage);

    // size stores length of original massage
    size_t size {originalMassage.length()};
    size_t index {};
    // character stores each extracted character from massage
    char character {};


//--------------------------------------------
//---------To encrypt the original massage------
//--------------------------------------------
    std::cout << "\n\nEncrypting Massage.........." << std::endl;
    
    for (int i = 0; i < size; ++i) {

        //extracts character from index is stored in character
        character = originalMassage.at(i);
    
        // search for character in alphabet string(if character is an alphabet) and stored in index
        index = alphabet.find(character);
    
        // checks if the character is found in alphabet string or not
        if (index != std::string::npos) {
            // concarting key character with encryptedMassage string
            encryptedMassage += key.at(index);
        }
        // if character is not alphabet
        else {
            encryptedMassage += character;
        }
    }
    
    // displaying encrypted massage
    std::cout << "Encrypted massage : " << encryptedMassage << std::endl;
    
    
//--------------------------------------------
//---------To decrypt the encrypted massage------
//--------------------------------------------
    std::cout << "\n\nDecrypting Massage.........." << std::endl;
    
    for (int i = 0; i < size; ++i) {
        //extracts character from index is stored in character
        character = encryptedMassage.at(i);

        // search for character in key string and found possion is stored in index
        index = key.find(character);

        // checks if the character is an alphabet or not
        if (index != std::string::npos) {
            // concarting key character with encryptedMassage string
            decryptedMassage += alphabet.at(index);
        }
        // if character is not alphabet
        else {
                decryptedMassage += encryptedMassage.at(i);
        }
    }
    
    // displaying decrypted massage
    std::cout << "decrypted massage : " << decryptedMassage << std::endl;
    
    return 0;
}
