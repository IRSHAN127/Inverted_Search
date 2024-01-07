#include"inverted.h"
//header file
void search(Wlist *head,char *word)                                    //search for searched input 
{
	printf("\033[1;33m"); //for printing in yellow 
	//check list empty or not
	if(head == NULL)
	{
		printf("Search word is not available in the list as list is empty\n");          //when head empty
	}

	//traverse the list 
	while(head)
	{
		//compare the search_word with available words in Wlist
		if(!strcmp(head->word,word))                                                          //compare word with word in Wlist
		{
			printf("word %s is present in %d file/s",word,head->file_count);                  //printing if word found
			Ltable *Thead = head->Tlink;
			while(Thead)
			{
				printf("\nIn file: %s\t\t%d times/s\n",Thead->file_name, Thead->word_count);          //print in which file 
				Thead = Thead->table_link;
			}
			return ;
		}
		head = head->link;
	}

	printf("Search is not present in the list\n");
}
