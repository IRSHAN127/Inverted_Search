#include"inverted.h"
//header file
void save_database(Wlist *head[])              //save data in file
{
	char file_name[FNAME_SIZE];

	printf("Enter the filename\n");            //read file name to creat file name 
	scanf("%s",file_name);

	FILE *fptr = fopen(file_name, "w");       

	for(int i = 0; i < 27; i++)                //travers in all 27 hash table and if data present in any node print in file 
	{
		if(head[i] != NULL)
		{
			write_databasefile(head[i],fptr); //function for printing in file
		}
	}
	printf("Database is saved\n");
}


void write_databasefile(Wlist *head, FILE* databasefile)
{
	//#[0]
	//word is [are]: file count is  1 file/s: file is file1.txt word count is 1 --> sample

	//Wlist *Wtemp = head->link;
    int index = tolower(head->word[0]) % 97;
	//other than alphabets
        if(!(index >= 0 && index <= 25))
            index = 26;
	while(head)
	{
		fprintf(databasefile,"\n#[%d]\nword\tis\t[%s]:\tfile\tcount\tis\t[%d]\n",index,head->word,head->file_count);

		Ltable *Ltemp = head->Tlink;
		
		while(Ltemp)
		{
			fprintf(databasefile,"file/s:\tfile\tis\t[%s]\tword\tcount\tis\t%d\n",Ltemp->file_name,Ltemp->word_count);
			Ltemp = Ltemp->table_link;
		}
		head = head->link;
	}
}
