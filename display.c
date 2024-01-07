#include "inverted.h"

void display_database(Wlist *head[])
{
	printf("\033[1;33m");  //for printing in yellow
	printf("[index]\t\t[word]\t\tfile_count\tfile/s\t\tFile : file_name\tword_count\n");
	int j = 0;
	for(int i = 0 ; i < 27 ; i++)
	{
		if(head[i] != NULL)
		{  
			j++;
			print_word_count(head[i]);
		}
	}
	if(!j)
		printf("no data in database\n"); // if j is 0, means no data in database
}


int print_word_count(Wlist *head)
{
	//traverse through the Wlist till last node

	while(head != NULL)
	{
		int index = tolower(head->word[0])%97;
        //other than alphabets
        if(!(index >= 0 && index <= 25))
            index = 26;
		
		printf("\n[%d]\t\t[%s]\t\t%d\t\tfile/s:\t\t",index, head->word, head->file_count);
		
		Ltable* temp =head->Tlink;
		int i = 1;
		//traverse
		while(temp)
		{
			if(i--)                 //for printing file only once
				printf("File : ");
			printf("%s\t\t%d\t\t", temp->file_name, temp->word_count);
			temp = temp->table_link;
		}
		head = head->link;
	}
}
