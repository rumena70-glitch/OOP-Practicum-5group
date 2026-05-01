#include <algorithm>
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
    Restaurant() : name(""), category(Category::Italian), isOpen(false), rating(0), averagePrice(0) {}
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
    Category getCategory() const {
        return category;
    }

    const char *getName() const {
        return name;
    }
    double getAveragePrice() const {
        return averagePrice;
    }
};
void selectionSortDesc(Restaurant* arr, const int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].getAveragePrice() > arr[minIndex].getAveragePrice()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}
class RestaurantChain {
    Restaurant restaurants[100]{Restaurant()};
    int pos = 0;
    RestaurantChain(const Restaurant* restaurants, const int n) {
        for (int i = 0; i < n; i++) {
            if (pos < 100) {
                this -> restaurants[pos++] = restaurants[i];
            }
        }
    }
    RestaurantChain(const Restaurant* restaurants, const int n, const Category category) {
        for (int i = 0; i < n; i++) {
            if (restaurants[i].getCategory() == category && pos < 100) {
                this -> restaurants[pos++] = restaurants[i];
            }
        }
    }
    void addRestaurant(const Restaurant& restaurant) {
        if (pos < 100) {
            this -> restaurants[pos++] = restaurant;
        }
    }
    void removeRestaurant(const char* name) {
        for (int i = 0; i < pos; i++) {
            if (strcmp(restaurants[i].getName(), name) == 0) {
                restaurants[i] = Restaurant();
            }
        }
    }
    int getCount() const {
        int counter = 0;
        for (int i = 0; i < pos; i++) {
            if (strcmp(restaurants[i].getName(), "") != 0) {
                counter++;
            }
        }
        return counter;
    }
    Restaurant* getMostExpensive(const int num) {
        selectionSortDesc(restaurants, 100);
        Restaurant* result = new Restaurant[num];
        for (int i = 0; i < num; i++) {
            result[i] = restaurants[i];
        }
        for (int i = 0; i < num; i++) {
            result[i] = restaurants[i];
        }
        return result;
    }
    void printOpen() const {
        for (int i = 0; i < pos; i++) {
            restaurants[i].print();
        }
    }
    void rateAll(double rating) {
        for (int i = 0; i < pos; i++) {
            restaurants[i].rate(rating);
            if (restaurants[i].getRating() < 1) {
                remove(restaurants[i].getName());
            }
        }
    }
    double getAveragePriceForCategory(Category category) const {
        double averagePrice = 0;
        int counter = 0;
        for (int i = 0; i < pos; i++) {
            if (restaurants[i].getCategory() == category) {
                averagePrice += restaurants[i].getAveragePrice();
                counter++;
            }
        }
        return averagePrice / counter;
    }
};
int main() {

}
