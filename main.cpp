#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <map>
#include <cstdlib>
#include <vector>

std::vector <int> random;
std::vector <std::string> random_binary;
std::vector <std::string> sentence_binary;
std::vector <std::string> sum_result;
std::map<int, std::string> random_numbers;
std::map<int, std::string> sentence_numbers;
std::string file_content;
std::string key;

void convert_to_binary()
{
    for(int i : random)
    {

        std::string binary= std::bitset<8>(i).to_string();
        random_numbers[i] = binary.substr();

        std::cout<< "key_number[i]: " << i <<" binary: " << binary << std::endl;
        random_binary.push_back(binary);
    }

    for(char i : file_content)
    {
        std::string binary= std::bitset<8>(int(i)).to_string();
        sentence_numbers[int(i)] = binary.substr();

        std::cout<< "sentence_numbers[i]: " << int(i) <<" binary: " << binary << std::endl;
        sentence_binary.push_back(binary);
    }

}

void addBinary(std::string a, std::string b){
    std::string ans;
    int  n=8;

    // Loop to iterate over the
    // Binary Strings
    for (int i = 0; i < n; i++)
    {
        // If the Character matches
        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    std::cout <<"String a + b : " << a << " + " << b << " = " << ans << "<----------- \n";
    sum_result.push_back(ans);
}


int main()
{
    std::ifstream ofs;
    ofs.open("C:/Users/mlewa/CLionProjects/One-Time_Pad/output.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    std::ifstream ofs1;
    ofs1.open("C:/Users/mlewa/CLionProjects/One-Time_Pad/key.txt", std::ofstream::out | std::ofstream::trunc);
    ofs1.close();

    std::ifstream file;
    file.open("C:/Users/mlewa/CLionProjects/kompresja/output.txt");

    if(file.fail())
    {
        std::cout << "File fail";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    file_content = buffer.str();
    file.close();

    std::cout << "Sentence: " << file_content << std::endl;

    for(int i=0; i < file_content.length(); i++)
    {
        int temp = std::rand() % 256;
       // std::cout << temp<< " ";
        random.push_back(temp);
    }



    for (int i = 0; i < file_content.length(); i++)
    {
        key += char(random[i]);
    }

    std::cout <<"Key: " << key << std::endl;

    std::fstream key_to_file;
    key_to_file.open("C:/Users/mlewa/CLionProjects/One-Time_Pad/key.txt", std::ios::out| std::ios::app);

    key_to_file << key;
    convert_to_binary();

   // FUNKCJA DO WYŚWIETLANIA ZAWARTOŚCI MAP, nawet działa hurray! - chuj
//    for (auto const& pair : random_numbers)
//    {
//        std::cout << pair.second << std::endl;
//        random_binary.push_back(pair.second);
//
//    }
//
//
//    for (auto const& pair : sentence_numbers)
//    {
//        std::cout <<  pair.second << std::endl;
//        sentence_binary.push_back(pair.second);
//    }

    for (int i=0; i<sentence_numbers.size(); i++)
    {
        addBinary(random_binary[i], sentence_binary[i]);
    }

//    for (int i=0; i< random_numbers.size(); i++)
//    {
//        addBinary(random_numbers.find(i), sentence_numbers.find(i));
//    }

  //  std::cout << "\n  random_numbers[3].at(2): " << random_numbers[3.second] << "\n  sentence_numbers[3].at(2): " << sentence_numbers[3];


//    for (int ite = 0; ite < file_content.length(); ite++)
//    {
//        addBinary(random_numbers[ite].at(2), sentence_numbers[ite].at(2));
//    }


//    for (int i=0; i<file_content.length(); i++)
//    {
//        int value1 = std::bitset<8>(i).to_ulong();
//        //int value2 = std::bitset<8>(sentence_numbers.at(pair.first)).to_ulong();
//        int sum = random_numbers.at(2) + sentence_numbers.at(2);
//        result[i] = std::bitset<8>(sum).to_string();
//    }

    std::string encrypted_sentence;
    for (const auto & i : sum_result)
    {
        std::string substr = i.substr();
        std::bitset<8> bits(substr);
        encrypted_sentence += char(bits.to_ulong());
    }

    std::cout << "Encrypted sentence: " <<  encrypted_sentence << " Length: " << encrypted_sentence.length() << std::endl;
    std::cout << "File content: " <<  file_content << " Length: " << file_content.length() << std::endl;

    std::fstream final_encrypted_sentence;
    final_encrypted_sentence.open("C:/Users/mlewa/CLionProjects/One-Time_Pad/output.txt", std::ios::out| std::ios::app);

    final_encrypted_sentence << encrypted_sentence;

    ///     1. Najpierw trzeba odczytać plik skompresowany
    ///     2. Trzeba zmierzyć długość pliku skompresowanego i na podstawie tej liczby wygenereować taką samą liczbę losowych liczb,
    ///         tak żeby każdemu znakowi z inputu opdowiadała losowo wygenerowana liczba

    ///     KLUCZEM DO SZYFROWANIA TZW PAD BĘDZIE: CIĄG WYGENEROWANYCH LOSOWO LICZB ZAMIENIONYCH NA POSZCZEGÓLNE ZNAKI ASCII

    ///     3. Zmieniamy każdy znak ze zdania z inputu na liczbę w ASCII
    ///     4. Dodajemy binarnie liczbę randomową do liczby odpowiadającej ze znaku ASCII i na tej podstawie generuje się trzecia - zaszyfrowana
    ///     5. Konwertujemy powstałą trzecią liczbę na znak ASCII
    ///     6. Składamy wszystkie znaki w całość i otrzymujemy zaszyfrowane zdanie


    /// znak w zdaniu  ----> liczba w ASCII ----> liczba binarna
    // -----STRING----       ---------------MAPA----------------

    /// liczba binarna <---- random liczba  ----> znak w ASCII ----> KLUCZ
    //  --------------MAPA----------------                        --STRING--

}
