#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <string>
#include <vector>
#include <time.h>
#include <string.h>

using namespace std;

class LogManager
{
    fstream file;
	string file_name;
	mutex log_mutex;

	public:
		LogManager(string file_name);
		void WriteLog(string str);
		void ShowLog();
};

LogManager::LogManager(string file_name)
{
	time_t current_time = time(NULL);
	char *str = (ctime(&current_time));
	str[strlen(str)-1] = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == ' ')
			str[i] = '_';
	}
	string tempo(str);
		

	this->file_name = tempo + "_" + file_name;
}

void LogManager::WriteLog(string str)
{
	log_mutex.lock();
	file.open(file_name, ios::app);
	time_t current_time = time(NULL);
	char *strin = ctime(&current_time);
	strin[strlen(strin)-1] = 0;
	string tempo(strin);
	file << tempo;
	file << " - ";
	file << str;
	file << '\n';
	file.close();
	log_mutex.unlock();
}

void LogManager::ShowLog()
{
	string line;
	file.open(file_name, ios::in);
	
	while(getline(file,line))
	{
		cout << line << '\n';
	}
}

int main()
{
	LogManager l1("log_1.txt");
	LogManager l2("log_2.txt");

	thread t1(&LogManager::WriteLog, &l1, "aaa");
	thread t2(&LogManager::WriteLog, &l1, "bbbbb");
	thread t3(&LogManager::WriteLog, &l2, "CcC");
	thread t4(&LogManager::WriteLog, &l2, "abacaxi");
	thread t5(&LogManager::WriteLog, &l1, "EEeEeEeEeE");

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	cout << "Log 1:\n";
	l1.ShowLog();
	cout << "Log 2:\n";
	l2.ShowLog(); 
}


