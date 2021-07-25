#include <iostream>

//fstream reads and writes from files
#include <fstream>

/*
This project has 2 parts in which are similar. Part 1: Read from txt file and find num1 and num2 that add to 2020 and display num1*num2.
Part 2: Do the same as part 1 but with num3.                                                                                                                    
*/

int main()
{
	int nums[200];
	int count = 0, listNum = 0, num1 = 0, num2 = 0, num3 = 0, solution2020 = 0;

	std::ifstream inputFile;
    inputFile.open("advent2020101coins.txt");

	if (!inputFile)
	{
		std::cout << "Error finding input file" << std::endl;
		system("pause");
		exit(-1);
	}

	while (!inputFile.eof())
	{
		inputFile >> nums[count];
		count++;
	}

	listNum = count;


	for (int i = 0; i < listNum -1; i++)
	{
		for (int j = 1; j < listNum; j++)
		{
			if (nums[i] + nums[j] == 2020)
			{
				solution2020 = nums[i] * nums[j];
				num1 = nums[i];
				num2 = nums[j];
				break;
			}
		}
	}

	std::cout << "First number is: " << num1 << ". Second number is: " << num2 <<". "<< num1 << " * " << num2 << " = " << solution2020<<std::endl;

	for (int i = 0; i < listNum - 2; i++)
	{
		for (int j = 1; j < listNum - 1; j++)
		{
			for (int k = 2; k < listNum; k++)
			{
				if ((nums[i] + nums[j] + nums[k] == 2020) && (nums[i] * nums[j] * nums[k] != 0))
				{
					solution2020 = nums[i] * nums[j] * nums[k];
					num1 = nums[i];
					num2 = nums[j];
					num3 = nums[k];
					break;
				}
			}
		}
	}

	std::cout << "First number is: " << num1 << ". Second number is: " << num2 << ". Third number is: " << num3 <<". " << num1 << " * " << num2 << " * " << num3<< " = " << solution2020;


	
	//displays all values stored from file 
	/*
	for (int i = 0; i < listNum; i++)
	{
		std::cout << " " << nums[i] << std::endl;
	}
	*/


	

	return 0;
}