using System;
using System.Collections.Generic; // Додали для роботи зі списками
using System.Data;
using Pr2AvaloniaMVVM.Services;

namespace Pr2AvaloniaMVVM.ViewModels
{
    public class MainWindowViewModel : ViewModelBase
    {
        private string _input;
        public string Input
        {
            get => _input;
            set => SetProperty(ref _input, value);
        }

        private string _result;
        public string Result
        {
            get => _result;
            set => SetProperty(ref _result, value);
        }

        // --- НОВЕ: Список для збереження історії ---
        private List<string> _history;
        public List<string> History
        {
            get => _history;
            set => SetProperty(ref _history, value);
        }

        private readonly DatabaseService _db = new DatabaseService();

        // --- НОВЕ: Конструктор, який завантажує історію при старті ---
        public MainWindowViewModel()
        {
            History = _db.GetHistory();
        }

        public void Calculate()
        {
            try
            {
                var table = new DataTable();
                var value = table.Compute(Input, null);

                Result = value.ToString();

                // Зберігаємо в базу
                _db.SaveResult(Input, Result);

                // --- НОВЕ: Оновлюємо список на екрані відразу після обчислення ---
                History = _db.GetHistory();
            }
            catch (Exception)
            {
                Result = "Помилка обчислення!";
            }
        }
    }
}