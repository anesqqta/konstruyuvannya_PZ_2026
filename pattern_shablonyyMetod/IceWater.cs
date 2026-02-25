class IcedWater : Drink
{
    protected override void AddBase()
    {
        Console.WriteLine("Наливаємо чисту воду.");
    }

    protected override void AddMainIngredient()
    {
        Console.WriteLine("Основний інгредієнт відсутній.");
    }

    protected override void Mix()
    {
        Console.WriteLine("Перемішування не потрібне.");
    }

    protected override void AddExtras()
    {
        Console.WriteLine("Додаємо лід.");
    }
}