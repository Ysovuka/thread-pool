#include "threadpool.h"
#include <string>
#include <iostream>

std::mutex _mutex;
ThreadPool threadpool;

void writeOutput()
{
	std::lock_guard<std::mutex> lock(_mutex);

	static int count = 0;
	std::cout << "WiteOutput: " << count << std::endl;
	count++;
	threadpool.task_perform(threadpool.task_create(), writeOutput);
}

void writeOutput2()
{
	std::lock_guard<std::mutex> lock(_mutex);

	static int count = 0;
	std::cout << "WriteOutput2: " << count << std::endl;
	count++;
	threadpool.task_perform(threadpool.task_create(), writeOutput2);
}

void writeOutput3()
{
	std::lock_guard<std::mutex> lock(_mutex);

	static int count = 0;
	std::cout << "WriteOutput3: " << count << std::endl;
	count++;
	threadpool.task_perform(threadpool.task_create(), writeOutput3);
}

void writeOutput4()
{
	std::lock_guard<std::mutex> lock(_mutex);

	static int count = 0;
	std::cout << "WriteOutput4: " << count << std::endl;
	count++;
	threadpool.task_perform(threadpool.task_create(), writeOutput4);
}

int main(const char* args)
{
	
	threadpool.task_perform(threadpool.task_create(), writeOutput);
	threadpool.task_perform(threadpool.task_create(), writeOutput2);
	threadpool.task_perform(threadpool.task_create(), writeOutput3);
	threadpool.task_perform(threadpool.task_create(), writeOutput4);

	return 0;
}