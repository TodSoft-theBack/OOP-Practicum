#include <iostream>
#include <fstream>
//unsgined char is equivalent to a byte from 0 to 255
typedef unsigned char byte;

const size_t MAX_BUFFER_SIZE = 16;

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
            
            char buff[MAX_BUFFER_SIZE];
            reader.getline(buff, MAX_BUFFER_SIZE, '|');
            unsigned digitsCount = strlen(buff);
            numbers[i] = IntegerParse(buff, digitsCount);
        }
    }

    void CountCharsInFile(std::ifstream& reader, size_t& size, char _char) {
        size_t currentPosition = reader.tellg();
        reader.seekg(0, std::ios::beg);

        if (!reader.is_open())
            return ;

        while (true)
        {
            char current = reader.get();
            if (reader.eof())
            {
                size++;
                break;
            }

            if (current == _char)
                size++;
        }

        reader.clear();
        reader.seekg(currentPosition);
    }

    Colour* ReadColours(const char* fileName, size_t& count) {
        const char delim = '|';
        std::ifstream reader(fileName);
        if (!reader.is_open())
            return nullptr;
        
        CountCharsInFile(reader, count, delim);
        unsigned* numbers = new unsigned[count];
        ReadNumbers(reader, numbers, count);

        Colour* result = new Colour[count];
        SetColoursByNumber(result, numbers, count);

        delete[] numbers;
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