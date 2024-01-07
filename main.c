#include "inverted.h"
//header file
int main(int argc, char *argv[])
{
	system("clear");

	//validate the CLA
	if(argc <= 1)                                           // checking argument passed or not
	{
		printf("Enter the valid no. of argument\n");
		printf("./Slist.exe f1.txt , f2.txt...\n");
		return FAILURE;
	}

	//create the list of filenames
	//declare head pointer

	Flist* f_head = NULL;
	Wlist* head[27];
	for(int i = 0 ; i<27 ;i++)
		head[i]=NULL;

	//validate the files
    file_validation_n_file_list(&f_head,argv);

	if(f_head == NULL)                                         //checking in  f_head file head added or not
	{
		printf("No file are available in the file\n");   
		printf("Hence the process terminated\n");
		return FAILURE;
	}

	int choice;                //for choosing option
	int flag =1;              
	while(flag)
	{
		printf("\033[0m");       //default print colour
		printf("\n\nSelect your choice among following options:\n");       //instruction in stdout
		printf("1. Create Database\n2. Display Database\n3. Update Databae\n4. Search\n5. Save Database\n6. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		getchar();
		switch(choice)
		{
			case 1:
				create_database(f_head, head);                //creating database creat Wlist Tlink by Flist
				break;
            case 2:
				display_database(head);                       //print database on stdout
				break;
            case 3:
				update_database(head,&f_head);                //add new file data in database
				break;
            case 4:
				char word[WORD_SIZE];
				printf("Enter the word to search\n");         
				scanf("%s",word);
				int index = tolower(word[0])%97;
        		//other than alphabets
        		if(!(index >= 0 && index <= 25))               //check wheather is 1 char is non alphabet
            	index = 26;            
				search(head[index],word);                      //search for searched input in database
				break;
            case 5:
				save_database(head);                           //store database data in given file 
				break;
			case 6:
				system("clear");                               //clearing screen in exit
				flag = 0;                                     //exit case
				break;
      		default :
				printf("invalid input\n");                    //choice out of range
				break;
		}
	}
}

