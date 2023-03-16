#include <iostream>

class Product 
{
    
    private:
        uint8_t _barcode;
        unsigned _quantity;
        double _price;
        void SetBarcode(uint8_t barcode = 0)
        {
            _barcode = barcode;
        }
        
    public:

        Product()
        {
            SetBarcode();
            SetQuantity();
            SetBarcode();
        }

        Product(uint8_t barcode) :Product()
        {
            SetBarcode(barcode);
        }

        Product(uint8_t barcode, double price):Product(barcode)
        {
            SetBarcode(barcode);
            SetPrice(price);
        }

        Product(uint8_t barcode,unsigned quantity, double price):Product(barcode, price)
        {
            SetQuantity(quantity);
        }

        void SetQuantity(unsigned quantity = 0)
        {
            _quantity = quantity;
        }
        void SetPrice(double price = 0)
        {
            if (price >= 0)
                _price = price;
            else
                _price = 0;
        }

        uint8_t Barcode() {
            return _barcode;
        }

        unsigned Quantity() {
            return _quantity;
        }

        double Price() {
            return _price;
        }
};

int main()
{
    Product pepe(55);
    std::cout << (unsigned)pepe.Barcode() << std::endl;
    pepe.SetQuantity(5);
    std::cout << pepe.Quantity() << std::endl;
    pepe.SetPrice(-5.4);
    std::cout << pepe.Price() << std::endl;
    pepe.SetPrice(1.4);
    std::cout << pepe.Price() << std::endl;
}