#include <iostream>
#include <fstream>
//unsgined char is equivalent to a byte from 0 to 255
typedef unsigned char byte;


short DigitParse(char symbol)
{
    if (symbol < '0' || symbol > '9')
        return -1;
    return symbol - '0';
}

unsigned IntegerParse(const char* digits, size_t size) {
    unsigned number = 0;
    for (size_t i = 0; i < size; i++)
        (number *= 10) += DigitParse(digits[i]);
    return number;
}

namespace Colours {

    struct Colour {
        byte R = 0;
        byte G = 0;
        byte B = 0;
    };

    unsigned GetColourNumber(const Colour& colour)
    {
        unsigned result = 0;
        result += (unsigned)colour.R * (1 << 16);
        result += (unsigned)colour.G * (1 << 8);
        result += (unsigned)colour.B;
        return result;
    }

    void SetColourByNumber(Colour& colour, unsigned number)
    {
        unsigned pow16 = (1 << 16), pow8 = (1 << 8);
        colour.R = number / pow16;
        colour.G = (number % pow16) / pow8;
        colour.B = number % pow8;
    }

    void SetColoursByNumber(Colour* colours, unsigned* numbers, size_t size)
    {
        for (size_t i = 0; i < size; i++)
            SetColourByNumber(colours[i], numbers[i]);
    }

    void PrintColour(const Colour& colour)
    {
        std::cout <<"(" << (unsigned)colour.R <<", " << (unsigned)colour.G <<", " << (unsigned)colour.B << ")";
        std::cout << " -> " << GetColourNumber(colour) << std::endl;
    }

    void ReadNumbers(std::ifstream& reader, unsigned* numbers, size_t size) {
        for (size_t i = 0; i < size; i++)
        {
            char buff[16];
            reader.getline(buff, 16, '|');
            numbers[i] = IntegerParse(buff, sizeof(size_t));
        }
    }

    void GetNumbersCount(std::ifstream& reader, size_t& size) {
        size_t init_pos = reader.tellg();
        reader.seekg(0, std::ios::end);
        size_t pos = reader.tellg();
        size = (pos + 1)/9;
        reader.seekg(0, std::ios::beg);
        reader.seekg(init_pos);
    }

    Colour* ReadColours(const char* fileName, size_t& count) {
        std::ifstream reader(fileName);
        if (!reader.is_open())
            return nullptr;
        
        GetNumbersCount(reader, count);
        unsigned* numbers = new unsigned[count];
        ReadNumbers(reader, numbers, count);

        Colour* result = new Colour[count];
        SetColoursByNumber(result, numbers, count);

        reader.close();
        return result;
    }

}

int main()
{
    using namespace Colours;

    size_t colours_size = 0;
    Colour* colours;

    colours = ReadColours("colours.txt", colours_size);

    if (colours == nullptr)
    {
        std::cerr << "ERROR: Could not read the  colours properly!" << std::endl;
        return -1;
    }

    for (size_t i = 0; i < colours_size; i++)
        PrintColour(colours[i]);
}