#include "User.h"
int loginUser(User& u,FILE* f) //tra ve ti`nh trang log
{
	int ord;
	char tempID[LENGTH_MAX];
	printf("ID : ");
	scanf("%[^\n]\n", &tempID);
	if ((ord = findUser(tempID, f)) < 0)
	{
		return 0;
	}
	
}
int findUser(char* name,FILE* f) //tra ve number(STT), -1 la khong tim thay
{
	if (f == NULL)
	{
		printf("Loi khong tim thay csv!\n");
		return -1;
	}
	char trash[LENGTH_MAX];
	int ord;
	char name_temp[LENGTH_MAX];
	rewind(f);
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%d,%[^,],", &ord, &name_temp);
		if (strcmp(name, name_temp) == 0)
		{
			rewind(f);
			return ord;
		}
		fscanf(f, "%[^\n]\n", trash);
	}
	return -1;
}
int checkpassUser(User& u,int ord, FILE* f) //chua xong
{
	if (f == NULL)
		return 0;
	rewind(f);
	char trash[LENGTH_MAX];
	int n;
	fscanf(f,"%d\n", &n);
	for (int i = 0; i < n; i++)
	{

	}
	return 1;
}