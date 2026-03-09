using System;

class Program {
    static void Main(string[] args) {
        string role = "Student";
        int months = 8;
        double basePrice = 10;
        double price = 0;

        if (role == "Student") {
            if (months > 6) {
                price = basePrice * months * 0.8;
            }
            else {
                price = basePrice * months;
            }
        }
        else if (role == "Teacher") {
            if (months > 6) {
                price = basePrice * months * 0.7;
            }
            else {
                price = basePrice * months;
            }
        }
        else if (role == "Guest") {
            price = basePrice * months;
        }
        Console.WriteLine("Final price: " + price);
    }
}