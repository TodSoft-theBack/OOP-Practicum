#include <iostream>
#include <fstream>

using namespace std;

size_t GetFileSize(std::ifstream& file)
{
	size_t initialPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(initialPos);
	return fileSize;
}
struct User {
	static const size_t MAX_TEXT_FIELD_SIZE = 20;
	static const size_t MIN_PASSWORD_SIZE = 6;
	static const size_t MAX_PHONE_SIZE = 10;

	char Username[MAX_TEXT_FIELD_SIZE + 1] = "";
	char Password[MAX_TEXT_FIELD_SIZE + 1] = "";
	unsigned Age = 0;
	char Phone[MAX_PHONE_SIZE + 1] = "";

	static User Init()
	{
		User user;
		cin.getline(user.Username, User::MAX_TEXT_FIELD_SIZE + 1);
		cin.getline(user.Password, User::MAX_TEXT_FIELD_SIZE + 1);
		cin >> user.Age;
		cin.ignore();
		cin.getline(user.Phone, User::MAX_PHONE_SIZE + 1);
		return user;
	}
	static void Print(const User& user)
	{
		cout << user.Username << endl;
		cout << user.Password << endl;
		cout << user.Age << endl;
		cout << user.Phone << endl;
	}
	static void PrintUsers(const User* users, size_t users_count) {
		for (size_t i = 0; i < users_count; i++)
		{
			if (i > 0)
				cout << " < ------- >" << endl;

			User::Print(users[i]);
		}
	}

	static bool SaveToFile(const char* filename, const User* users, size_t user_count)
	{
		ofstream file(filename, ios::out | ios::binary);
		if (!file.is_open())
			return false;

		for (size_t i = 0; i < user_count; i++)
			file.write((const char*)&users[i], sizeof(users[i]));

		file.close();
		return true;
	}
	static void SaveUserToFile(ofstream& file, const User user)
	{
		file.write((const char*)&user, sizeof(user));
	}

	static User* ReadFromFile(const char* filename, size_t& users_count)
	{
		ifstream file(filename, ios::in | ios::binary);
		if (!file.is_open())
			return nullptr;

		size_t fileSize = GetFileSize(file);
		users_count = fileSize / sizeof(User);

		User* users = new User[users_count];
		for (size_t i = 0; i < users_count; i++)
			file.read((char*)(users + i), sizeof(users[i]));

		return users;
	}

	static void FreeAllocation(User* users)
	{
		delete[] users;
		users = nullptr;
	}

	static bool ContainsUser(const User& user, User* registeredUsers, size_t users_count)
	{
		for (size_t i = 0; i < users_count; i++)
		{
			if (strcmp(user.Username, registeredUsers[i].Username) == 0)
				return true;
		}
		return false;
	}

	static bool IsDigit(const char symbol)
	{
		return symbol >= '0' && symbol <= '9';
	}
	

	static bool HasDigit(const char* string)
	{
		size_t len = strlen(string);
		for (size_t i = 0; i < len; i++)
			if (IsDigit(string[i]))
				return true;
		return false;
	}

	static bool IsCapital(const char symbol)
	{
		return symbol >= 'A' && symbol <= 'Z';
	}

	static bool HasCapitals(const char* string)
	{
		size_t len = strlen(string);
		for (size_t i = 0; i < len; i++)
			if (IsCapital(string[i]))
				return true;
		return false;
	}

	static bool ValidateUser(const User& user, User* registeredUsers, size_t users_count)
	{
		if (ContainsUser(user, registeredUsers, users_count))
			return false;
		if (strlen(user.Password) < User::MIN_PASSWORD_SIZE)
			return false;
		if (!HasDigit(user.Password))
			return false;
		if (!HasCapitals(user.Password))
			return false;
		return true;
	}

	static bool RegisterUser(ofstream& file, User* registeredUsers, size_t users_count)
	{
		
		User user = User::Init();
		if (ValidateUser(user, registeredUsers, users_count))
		{
			SaveUserToFile(file, user);
			return true;
		}
		return false;
	}

	static void RegisterUsers(const char* filename, unsigned n)
	{
		size_t users_count = 0;
		User* users = ReadFromFile(filename, users_count);
		ofstream file(filename, ios::out | ios::binary | ios::app);
		for (size_t i = 0; i < n; i++)
			RegisterUser(file, users, users_count);
		FreeAllocation(users);
	}
};



void CreateBinaryFile(const char* filename)
{
	User user = User::Init();
	User user2 = User::Init();
	User user3 = User::Init();
	User array[] = { user, user2, user3 };
	User::SaveToFile(filename, array, 3);
}

int main()
{
	const char file[] = "users.bin";
	const char onlyOlder18[] = "adults.bin";
	size_t users_count = 0;
	User* users = User::ReadFromFile(file, users_count);

	User::FreeAllocation(users);
}