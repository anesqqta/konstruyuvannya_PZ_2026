using Microsoft.Data.Sqlite;
using System.Collections.Generic;

namespace Pr2AvaloniaMVVM.Services
{
    public class DatabaseService
    {
        private string _connectionString = "Data Source=history.db";

        public DatabaseService()
        {
            CreateTable();
        }

        private void CreateTable()
        {
            using var connection = new SqliteConnection(_connectionString);
            connection.Open();

            var command = connection.CreateCommand();
            command.CommandText =
            @"
            CREATE TABLE IF NOT EXISTS History (
                Id INTEGER PRIMARY KEY AUTOINCREMENT,
                Expression TEXT,
                Result TEXT
            );
            ";

            command.ExecuteNonQuery();
        }

        public void SaveResult(string expr, string res)
        {
            using var connection = new SqliteConnection(_connectionString);
            connection.Open();

            var command = connection.CreateCommand();
            command.CommandText =
            "INSERT INTO History (Expression, Result) VALUES ($expr, $res)";

            command.Parameters.AddWithValue("$expr", expr);
            command.Parameters.AddWithValue("$res", res);

            command.ExecuteNonQuery();
        }

        public List<string> GetHistory()
        {
            var history = new List<string>();

            using var connection = new SqliteConnection(_connectionString);
            connection.Open();

            var command = connection.CreateCommand();
            command.CommandText = "SELECT Expression, Result FROM History ORDER BY Id DESC";

            using var reader = command.ExecuteReader();

            while (reader.Read())
            {
                string expr = reader.GetString(0);
                string res = reader.GetString(1);

                history.Add($"{expr} = {res}");
            }

            return history;
        }
    }
}