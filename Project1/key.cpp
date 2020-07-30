#include"key.h"
void Encryption(const char* inFILE, const char* outFILE)
{
	int length;
	_flushall();
	FILE* input = fopen(inFILE, "r+");
	FILE* output = fopen(outFILE, "w+");
	char temp_string[256];
	while (!feof(input)) {
		fscanf(input, "%[^\n]\n", temp_string);
		length = strlen(temp_string);
		for (int i = 0; i < length; i++)
		{
			temp_string[i] = temp_string[i] ^ key;
		}
		fprintf(output, "%s", temp_string);
		fprintf(output, "\n");
	}
	fclose(input);
	fclose(output);
}
void Decryption(const char* inFILE, const char* outFILE)
{
	FILE*input = fopen(inFILE, "r+");
	FILE*output = fopen(outFILE, "w+");
	int length;
	char temp_string[256];
	while (!feof(input)) {
		fscanf(input, "%[^\n]\n", temp_string);
		length = strlen(temp_string);
		for (int i = 0; i < length; i++)
		{
			temp_string[i] = temp_string[i] ^ key;
		}
		fprintf(output, "%s", temp_string);
		fprintf(output, "\n");
	}
	fclose(input);
	fclose(output);
}
