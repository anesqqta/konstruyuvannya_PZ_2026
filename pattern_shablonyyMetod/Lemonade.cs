class Lemonade : Drink
{
    protected override void AddBase()
    {
        Console.WriteLine("Додаємо воду.");
    }

    protected override void AddMainIngredient()
    {
        Console.WriteLine("Додаємо лимонний сік.");
    }

    protected override void Mix()
    {
        Console.WriteLine("Перемішуємо ложкою.");
    }
}