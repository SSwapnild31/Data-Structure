#include"header.h"

int main()
{
	node *head = 0;
	int c;
	while(1)
	{
		int ch;
		printf("1.add_begin 2.add_end 3.add_middle 4.print_data 5.print_rev 6.count_node 7.rev_print_upto_half 99.exit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1 : add_begin(&head);	break;
			case 2 : add_end(&head);	break;
			case 3 : //add_middle(&head);	break;
			case 4 : print_data(head); 	break;
			case 5 : print_rev(head);	break;
			case 6 : c = count_node(head);
				 printf("node count : %d\n",c);	break;
			case 7 : rev_print_upto_half(head);	break;
			case 99 : exit(0);
			default : printf("wrong choice.!\n"); 
		}
	}
	return 0;
}
