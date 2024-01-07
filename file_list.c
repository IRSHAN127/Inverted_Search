#include"inverted.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
	//check argument is valid or not

	int i = 1, empty;
	while(argv[i] != NULL)
	{
		empty = isFileEmpty(argv[i]);
		if(empty == FILE_NOTAVAILABLE)
		{
			printf("File : %s is not avaliable\n",argv[i]);
			printf("Hence we are not adding into file linked list\n");
		}
		else if(empty == FILE_EMPTY)
		{
			printf("File : %s is not having any content in it\n",argv[i]);
			printf("Hence we are not adding into file linked list\n");
		}
		else
		{
			int ret_val = to_create_list_of_files(f_head, argv[i]);
			//return value of func
			if(ret_val == SUCCESS)
			{
				printf("Successfull : insering the filename : %s into file linked list\n",argv[i]);
			}
			else if(ret_val == REPEATATION)
			{
				printf("This file name : %s is repeated . So do not add more than once\n",argv[i]);
			}
			else
			{
				printf("FAILURE\n");
			}
		}
		i++;
	}
}







int isFileEmpty(char *filename)
{
	//function is used to check whether file is exist or not
	//it is going to check file empty or not
	
	FILE *fptr = fopen(filename , "r");
	if(fptr == NULL)
	{
		if(errno == ENOENT)
		{
			return FILE_NOTAVAILABLE;
		}
	}
	fseek(fptr, 0 , SEEK_END);

	if(ftell(fptr) == 0)
		return FILE_EMPTY;

    return SUCCESS;
}

int to_create_list_of_files(Flist **fhead, char *name)
{
	//create file linked_list
	//check filename duplicate or not
	Flist *new = malloc(sizeof(Flist));
	if(new == NULL)
		return FAILURE;

	new->check_database = 0;
	strcpy(new->file_name,name);
	new->link=NULL;

	if(*fhead == NULL)
	{
		*fhead = new;
		return SUCCESS;
	}

	Flist *temp = *fhead;
	
	if(strcmp(temp->file_name, name) == 0)
	{
		return REPEATATION;
	}
	
	while(temp)
	{
		if(strcmp(temp->file_name, name) == 0)
		{
			return REPEATATION;
		}
		if(temp->link)
			temp = temp->link;
		else
			break;
	}
	
	temp->link = new;
	return SUCCESS;

}

