using System;

class Program {
    static void Main(string[] args) {
        string role = "Student";
        int months = 8;
        double basePrice = 10;

        double price = CalculatePrice(role, months, basePrice);

        Console.WriteLine("Final price: " + price);
    }

    static double CalculatePrice(string role, int months, double basePrice) {
        double discount = GetDiscount(role, months);
        return basePrice * months * discount;
    }

    static double GetDiscount(string role, int months) {
        if (role == "Student") {
            if (months > 6)
                return 0.8;
            return 1;
        }

        if (role == "Teacher") {
            if (months > 6)
                return 0.7;
            return 1;
        }

        if (role == "Guest") {
            return 1;
        }

        return 1;
    }
}