#include "inverted.h"
char *fname;
void create_database(Flist* f_head, Wlist* head[])           //create database 
{
    //traverse through the file list
    while(f_head)                                  
    {
		if(f_head->check_database == 0)                      //from skiping if create database option create database choosen more then once
		{
			f_head->check_database = 1;                      //avoid word count for same file
        	read_datafile(f_head,head,f_head->file_name);
		}
		else
			printf("\n%s data already added in database\n",f_head->file_name);
		f_head = f_head->link;
    }
}

//read content of file and create database
Wlist* read_datafile(Flist *file, Wlist *head[], char *filename)
{

    //open file
    FILE *fptr = fopen(filename, "r");
    //declare an array to store the words
    char word[25];
    fname = filename;
	Wlist *temp;

    while(fscanf(fptr, "%s" ,word) != EOF)
    {
        //find index
        int index = tolower(word[0])%97;
        //other than alphabets
        if(!(index >= 0 && index <= 25))
            index = 26;

        int flag = 1;

        if(head[index] != NULL)
        {
            temp = head[index];
            //compare the word at each node with new word
            while(temp)
            {
                if(!(strcmp(temp->word , word)))
                {
                    update_word_count(&temp , filename);
                    flag = 0;
                    break;
                }
				temp = temp->link;
            }
        }
        if(flag == 1)
        {
            //words are not repeated
            insert_at_last(&head[index], word);
        }
    }
}



int update_word_count(Wlist **head,char *filename)
{
    //check whether file are same or not
    // if filename are same ,increment the word count in tlink
    //if the filename is different , creat ltable and increment file count;
    Ltable* temp =(*head)->Tlink,*last;
    while(temp)
    {
        if(!(strcmp(temp->file_name,fname)))
        {
            temp->word_count =temp->word_count + 1;
            return SUCCESS;
        }
		last = temp;
		temp = temp->table_link;

	}
	
	Ltable *new=malloc(sizeof(Ltable));
    if(new == NULL)
	return FAILURE;
    new->word_count=1;
    strcpy(new->file_name,filename);
    new->table_link=NULL;

    last->table_link=new;
    (*head)->file_count=((*head)->file_count)+1;
	return SUCCESS;
}



int insert_at_last(Wlist **head, data_t *data)
{
    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    //update
    new->file_count = 1;
    strcpy(new->word,data);
    new->Tlink = NULL;
    new->link = NULL;

    //call func() to the linktable
     update_link_table(&new);

     //check wlist empty or not
     if(*head == NULL)
     {
        *head = new;
        return SUCCESS;
     }

     //not empty

     Wlist* temp = *head;

     //traverse through the list
     while(temp->link != NULL)
     {
        temp = temp->link;
     }

     temp->link = new;
     return SUCCESS;
}



int update_link_table(Wlist **head)
{
    //create node
    Ltable *new = malloc(sizeof(Ltable));

    //error check
    if(new == NULL)
        return FAILURE;

    new->word_count = 1;
    strcpy(new->file_name,fname);
    new->table_link = NULL;

    
	(*head)->Tlink = new;
    return SUCCESS;
}

