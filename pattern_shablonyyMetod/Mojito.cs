class Mojito : Drink
{
    protected override void AddBase()
    {
        Console.WriteLine("Додаємо газовану воду.");
    }

    protected override void AddMainIngredient()
    {
        Console.WriteLine("Додаємо м’яту та лайм.");
    }

    protected override void Mix()
    {
        Console.WriteLine("Збовтуємо в шейкері.");
    }
}