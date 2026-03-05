#include <iostream>
using namespace std;

enum class Category {
    Italian, Chinese, American, French, Japanese
};
class Restaurant {
    char name[100];
    Category category;
    bool isOpen = true;
    double rating = 0;
    double averagePrice;
    public:
    Restaurant(const char* name, const Category category, const double averagePrice) : category(category), averagePrice(averagePrice) {
        strcpy(this -> name, name);
    }
    void print() const {
        char country[9];
        char status[7];
        if (category == Category::Italian) {
            strcpy(country, "Italian");
        }
        else if (category == Category::Chinese) {
            strcpy(country, "Chinese");
        }
        else if (category == Category::American) {
            strcpy(country, "American");
        }
        else if (category == Category::French) {
            strcpy(country, "French");
        }
        else if (category == Category::Japanese) {
            strcpy(country, "Japanese");
        }
        if (isOpen) {
            strcpy(status, "Open");
        }
        else {
            strcpy(status, "Closed");
        }
        println("{}, {} category, {}, {:.1f} star rating, {}€ average price", name, country, status, rating, averagePrice);
    }
    bool getStatus() const {
        return isOpen;
    }
    double getRating() const {
        return rating;
    }
    bool rate(const double newRating) {
        if (newRating > 5 || newRating < 0) {
            return false;
        }
        this -> rating = (rating + newRating) / 2;
        return true;
    }
    void open() {
        isOpen = true;
    }
    void close() {
        isOpen = false;
    }
};
int main() {
    Restaurant murafeti = Restaurant("Murafeti", Category::Italian, 50);
    murafeti.print();
    murafeti.close();
    murafeti.print();
    murafeti.open();
    murafeti.rate(5);
    murafeti.print();

}