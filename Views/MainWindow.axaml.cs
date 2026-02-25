using Avalonia.Controls;
using Avalonia.Interactivity;
using Pr2AvaloniaMVVM.ViewModels;

namespace Pr2AvaloniaMVVM.Views
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            DataContext = new MainWindowViewModel();
        }

        private void OnCalculateClick(object sender, RoutedEventArgs e)
        {
            if (DataContext is MainWindowViewModel vm)
            {
                vm.Calculate();
            }
        }
    }
}