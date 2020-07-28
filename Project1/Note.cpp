#include"Note.h"
extern FILE* fReader;
extern FILE* fBook;

void createBorrowNote(FILE*& f)
{
	if (f == NULL)
	{
		printf("required file not found! action failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX*4];
	int n_Note,n_book;
	fscanf(f, "%d\n", &n_Note); n_Note++;
	// prepare new file
	FILE* temp_f = fopen("temp.txt", "w+t");
	{
		fprintf(temp_f, "%d\n", n_Note);
		while (!feof(f))
		{
			fscanf(f, "%[^\n]\n", temp_string);

			fprintf(temp_f, "%s\n", temp_string);
		}

	}
	Reader r;
	r.name = NULL;
	Book b;
	b.name = NULL;
	Date date; char* date_string;
	fillReader(r, fReader);
	fprintf(temp_f, "%s,", r.ID);
	printf("Nhap ngay muon sach :\n");
	printf("Ngay: ");
	scanf("%d", &date.d);
	printf("Thang: ");
	scanf("%d", &date.m);
	printf("Nam: ");
	scanf("%d", &date.y);
	date_string=convertDatetoString(date); 
	fprintf(temp_f, "%s,", date_string);
	date = sau_k_ngay(date, 7);
	date_string = convertDatetoString(date);
	fprintf(temp_f, "%s,", date_string);

	printf("Nhap so cuon sach muon : "); scanf("%d", &n_book);
	fprintf(temp_f, "%d\n", n_book);
	for (int i = 0; i < n_book; i++)
	{
		fillBook(b, fBook);
		b.name = NULL;
		fprintf(temp_f, "%s\n", b.ISBN);
	}
	fclose(f);
	fclose(temp_f);
	remove(fBORROW);
	rename("temp.txt", fBORROW);
	f = fopen(fBORROW, "r+t");
}
void createReturnNote(FILE*& f)
{
	if (f == NULL)
	{
		printf("required file not found! action failed \n");
		return;
	}
	rewind(f);
	char temp_string[LENGTH_MAX * 4];
	int n_Note, n_book;
	fscanf(f, "%d\n", &n_Note); n_Note++;
	// prepare new file
	FILE* temp_f = fopen("temp.txt", "w+t");
	{
		fprintf(temp_f, "%d\n", n_Note);
		while (!feof(f))
		{
			fscanf(f, "%[^\n]\n", temp_string);

			fprintf(temp_f, "%s\n", temp_string);
		}

	}
	Note n;
	Date date; char* date_string;

	fclose(f);
	fclose(temp_f);
	remove(fBORROW);
	rename("temp.txt", fBORROW);
	f = fopen(fBORROW, "r+t");
}
int findNote(char* name,FILE* f,Note* &result)
{
	if (f == NULL) 
	{
		printf("required file not found! action failed \n");
		return -1;
	}
	rewind(f);
	Note check;
	int k=0;
	char trash[LENGTH_MAX * 4];
	char name_temp[LENGTH_MAX];
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%[^,],%d/%d/%d,%d/%d/%d,%d\n", check.reader_ID, &check.bor_date.d, &check.bor_date.m, &check.bor_date.y, &check.expe_date.d, &check.expe_date.m, &check.expe_date.y, &check.book_number);
		if (_stricmp(name, name_temp) == 0)
		{
			result[k] = check;
			result[k].book_ISBN = (char**)calloc(check.book_number, sizeof(char*));
			for (int j = 0; i < check.book_number ; i++)
			{
				fscanf(f, "%[^\n]\n", &result[k].book_ISBN[j]);
			}
			k++;
		}
		else 
		{
			for (int j = 0; i < check.book_number ; i++)
			{
				fscanf(f, "%[^\n]\n", trash);
			}
		}
	}
	return k;
}