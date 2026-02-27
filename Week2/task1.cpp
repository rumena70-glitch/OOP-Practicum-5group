#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
    string name;
    double balance = 0;
    string IBAN;
    // string currency = "EUR";
    public:
    string getName() const {
        return this -> name;
    }
    bool setName(const string& name) {
        if (!name.empty()) {
            this -> name = name;
            return true;
        }
        return false;
    }
    string getIBAN() const {
        return this -> IBAN;
    }
    bool setIBAN(const string& IBAN) {
        if (!IBAN.empty()) {
            this -> IBAN = IBAN;
            return true;
        }
        return false;
    }
    bool withdraw(const int amount) {
        if (amount > balance) {
            return false;
        }
        this -> balance -= amount;
        return true;
    }
    void deposit(const int amount) {
        this -> balance += amount;
    }
    double getBalance(const string& currency) const {
        if (currency == "EUR") {
            return this -> balance;
        }
        if (currency == "USD") {
            return (this -> balance) * 1.18;
        }
        if (currency == "ARS") {
            return (this -> balance) * 1656.45;
        }
        if (currency == "GBP") {
            return (this -> balance) * 0.87;
        }
        if (currency == "BTC") {
            return (this -> balance) * 0.000018;
        }
        return -1;
    }
};
class bankAccountSerializer {
    string outputFileName;
    BankAccount bankAccount;
    string currency = "EUR";
    public:
    bool setOutputFileName(const string& filename) {
        if (!filename.empty()) {
            this -> outputFileName = filename;
            return true;
        }
        return false;
    }
    bool setBankAccount(const BankAccount& bankAccount) {
        if (bankAccount.getName().empty() || bankAccount.getIBAN().empty()) {
            return false;
        }
        this -> bankAccount = bankAccount;
        return true;
    }
    bool setCurrency(const string& currency) {
        if (currency == "EUR" || currency == "USD" || currency == "ARS" || currency == "GBP" || currency == "BTC") {
            this -> currency = currency;
            return true;
        }
        return false;
    }
    bool save() {
        ofstream outFile(outputFileName, ios::app);
        if (!outFile) {
            return false;
        }
        println(outFile, "{}, {:.2f} {}, {}", bankAccount.getName(), bankAccount.getBalance(this -> currency), this -> currency, bankAccount.getIBAN());
        outFile.close();
        return true;
    }
};
int main() {
    BankAccount bankAccount;
    bankAccount.setName("Rumen Anastasov");
    bankAccount.setIBAN("8MI0600680");
    bankAccount.deposit(2000);
    bankAccount.withdraw(1000);
    bankAccountSerializer serializer;
    string outputFileName = "output.txt";
    serializer.setOutputFileName(outputFileName);
    serializer.setBankAccount(bankAccount);
    for (string currency[] = {"EUR", "USD", "ARS", "GBP", "BTC"}; const auto & i : currency) {
        serializer.setCurrency(i);
        serializer.save();
    }
};