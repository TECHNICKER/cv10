#include "cv10.h"

int main()
{
	const char* inputPath = "D:\\vstup.txt";
	FILE* inputFile;

	char current_char;
	const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char* numerals = "0123456789";
	int prev_num_num = 0;
	int num_of_letters = 0;
	int num_of_numbers = 0;

	if (fopen_s(&inputFile, inputPath, "r"))
	{
		return -1;
	}

	current_char = fgetc(inputFile);

	while (current_char != EOF)
	{

		prev_num_num = num_of_numbers;

		for (int i = 0; i < 10; i++)
		{
			if (current_char == numerals[i])
			{
				num_of_numbers++;
				break;
			}
		}

		if (prev_num_num == num_of_numbers)
		{
			for (int i = 1; i <= 26; i++)
			{
				if (toupper(current_char) == alphabet[i])
				{
					num_of_letters++;
					break;
				}
			}
		}

		current_char = fgetc(inputFile);

	}

	fclose(inputFile);


	const char* outputPath = "D:\\vystup.txt";
	FILE* outputFile;

	if (fopen_s(&outputFile, outputPath, "w"))
	{
		return -1;
	}

	printf("V textu bylo nalezeno %d cisel a %d pismen.", num_of_numbers, num_of_letters);
	fprintf(outputFile, "V textu bylo nalezeno %d cisel a %d pismen.", num_of_numbers, num_of_letters);

	fclose(outputFile);


	return 0;
}
