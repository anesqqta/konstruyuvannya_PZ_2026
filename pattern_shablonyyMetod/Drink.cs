using System;

abstract class Drink
{
    // Шаблонний метод
    public void PrepareDrink()
    {
        PrepareGlass();
        AddBase();
        AddMainIngredient();
        Mix();

        if (CustomerWantsExtras())
        {
            AddExtras();
        }

        Serve();
    }

    private void PrepareGlass()
    {
        Console.WriteLine("Підготовка склянки...");
    }

    protected abstract void AddBase();
    protected abstract void AddMainIngredient();
    protected abstract void Mix();

    // Hook (можна перевизначати)
    protected virtual void AddExtras()
    {
        Console.WriteLine("Додаємо лід або декор...");
    }

    protected virtual bool CustomerWantsExtras()
    {
        Console.Write("Додати лід/декор? (y/n): ");
        string answer = Console.ReadLine();
        return answer.ToLower() == "y";
    }

    private void Serve()
    {
        Console.WriteLine("Подаємо напій.\n");
    }
}