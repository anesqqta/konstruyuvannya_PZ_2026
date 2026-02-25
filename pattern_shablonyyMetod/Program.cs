using System.Text;

class Program
{
    static void Main()
    {
        // Встановлюємо кодування консолі на UTF-8
        Console.OutputEncoding = Encoding.UTF8;
        Console.InputEncoding = Encoding.UTF8;

        while (true)
        {
            Console.WriteLine("Оберіть напій:");
            Console.WriteLine("1 - Лимонад");
            Console.WriteLine("2 - Мохіто");
            Console.WriteLine("3 - Вода з/без льоду");
            Console.WriteLine("0 - Вийти");

            string choice = Console.ReadLine();

            Drink drink = null;

            switch (choice)
            {
                case "1":
                    drink = new Lemonade();
                    break;
                case "2":
                    drink = new Mojito();
                    break;
                case "3":
                    drink = new IcedWater();
                    break;
                case "0":
                    return;
                default:
                    Console.WriteLine("Невірний вибір\n");
                    continue;
            }

            drink.PrepareDrink();
        }
    }
   
        
            
        
    
}